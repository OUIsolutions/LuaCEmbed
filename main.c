#include "src/one.c"


LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    LuaCEmbedTable * args_to_call  = lua_n.tables.new_anonymous_table(args);
    lua_n.tables.append_long(args_to_call,10);
    lua_n.tables.append_long(args_to_call,20);
    int total_returns = 1;
    int index_of_lambda = 0;

    lua_n.args.run_lambda(args,index_of_lambda,args_to_call,total_returns);
    return NULL;
}


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);

    lua_n.evaluate(l,"test(function(a,b) return a + b end )");

    if(lua_n.has_errors(l)){
        char *error = lua_n.get_error_message(l);
        printf("%s\n",error);
    }
    lua_n.free(l);

    return 0;
}