#include "src/one.c"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){

    LuaCEmbedTable * multi_response  = lua_n.tables.new_anonymous_table(args);
    lua_n.tables.append_string(multi_response,"first");
    lua_n.tables.append_long(multi_response,10);
    return lua_n.response.send_multi_return(multi_response);
}

int main(int argc, char *argv[]){

    printf("size %ld\n",sizeof(long long ));
    return 0;
    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);


    lua_n.evaluate(l,"a,b =test()");
    char *a = lua_n.get_string_evaluation(l,"a");
    long b = lua_n.get_evaluation_long(l,"b");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    printf("a = %s\n",a);
    printf("b = %ld\n",b);


    lua_n.free(l);

    return 0;
}