#include "src/one.c"

LuaCEmbedNamespace  lua_n;




int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate(l,"function test_func(a,b) return a + b end ");
    LuaCEmbedTable * args = lua_n.tables.new_anonymous_table(l);
    lua_n.tables.append_long(args,20);
    lua_n.tables.append_long(args,30);
    LuaCembed_new_anonymous_table()
    LuaCEmbedTable *result = lua_n.globals.run_global_lambda(l,"test_func",args,1);

    double  result_0 = lua_n.tables.get_double_by_index(result,0);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    else{
        printf("result 0: %lf\n",result_0);

    }

    lua_n.free(l);

    return 0;
}