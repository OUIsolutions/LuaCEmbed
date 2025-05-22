
#define LUA_CEMBED_INDEX_DIF 0
#include "LuaCEmbedOne.c"

LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    long size = lua_n.args.size(args);
    if(size == 0){
        printf("no argument providided\n");
        return NULL;
    }
    int index = 1;
    int arg_type = lua_n.args.get_type(args,index);

    if(arg_type  == lua_n.types.NUMBER){
        printf("number: %lf\n",lua_n.args.get_double(args,index));
    }

    else if(arg_type  == lua_n.types.STRING){
        printf("str: %s\n",lua_n.args.get_str(args,index));
    }

    else if(arg_type  == lua_n.types.BOOL){
        printf("bool: %d\n", lua_n.args.get_bool(args,index));
    }
    else{
        const char *converted_to_str = lua_n.convert_arg_code(arg_type);
        printf("type: %s\n",converted_to_str);
    }

    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);

    lua_n.evaluate(l,"test()");
    lua_n.evaluate(l,"test(10)");
    lua_n.evaluate(l,"test('hello')");
    lua_n.evaluate(l,"test(true)");
    lua_n.evaluate(l,"test({a=30})");


    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}