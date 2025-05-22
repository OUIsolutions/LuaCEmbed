#include "LuaCEmbedOne.c"
LuaCEmbedNamespace  lua_n;

LuaCEmbedResponse  * create_table(LuaCEmbed *args){

    LuaCEmbedTable *custom_table =  lua_n.tables.new_anonymous_table(args);
    lua_n.tables.append_string(custom_table,"test1");
    lua_n.tables.append_string(custom_table,"test2");
    lua_n.tables.append_string(custom_table,"test3");

    return lua_n.response.send_table(custom_table);

}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"create_string_array", create_table);
    lua_n.evaluate(l,"r = create_string_array()");
    LuaCEmbedTable *table = lua_n.globals.get_table(l,"r");
    long size =lua_n.tables.get_size(table);

    for(int i = 0; i < size; i++){
        char  *current = lua_n.tables.get_string_by_index(table,i);
        if(!lua_n.has_errors(l)){
            printf("%s\n",current);
        }
    }

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }


    lua_n.free(l);

    return 0;
}