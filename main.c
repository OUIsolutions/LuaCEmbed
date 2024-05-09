#include "src/one.c"


LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){

    LuaCEmbedTable *t = lua_n.args.get_table(args,0);
    lua_n.tables.insert_string_at_index(t,0,"ee");


    return lua_n.response.send_table(t);
}


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);
    lua_n.evaluate(l,"new_table = test({'a','b','c'})");

    LuaCEmbedTable * new_table = lua_n.globals.get_table(l,"new_table");
    long size = lua_n.tables.get_size(new_table);
    for(int i = 0; i < size; i ++){
        char *content = lua_n.tables.get_string_by_index(new_table,i);
        printf("%s\n",content);
    }
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }


    lua_n.free(l);

    return 0;
}