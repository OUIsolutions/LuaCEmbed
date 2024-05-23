#include "src/one.c"
LuaCEmbedNamespace  lua_n;


LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){

    LuaCEmbedTable *created = lua_n.tables.new_anonymous_table(args);
    lua_n.tables.append_long(created,10);
    lua_n.tables.append_long(created,20);


    LuaCEmbedTable *response = lua_n.args.run_lambda(args,0,created,3);
    double result = lua_n.tables.get_double_by_index(response,0);

    printf("result %lf\n",result);

    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);

    lua_n.evaluate(l,"test(function (a,b) return a + b end )");


    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}