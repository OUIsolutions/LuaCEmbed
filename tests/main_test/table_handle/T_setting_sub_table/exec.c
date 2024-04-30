#include "../../../LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;

LuaCEmbedResponse  * create_table(LuaCEmbed *args){

    LuaCEmbedTable *custom_table =  lua_n.tables.new_anonymous_table(args);
    LuaCEmbedTable *sub_table = lua_n.tables.new_anonymous_table(args);
    lua_n.tables.set_string_prop(sub_table,"test","custom text");
    lua_n.tables.set_sub_table_prop(custom_table,"sub_table",sub_table);

    return lua_n.response.send_table(custom_table);

}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"create_table", create_table);
    lua_n.evaluate(l,"r = create_table()");

    char *test = lua_n.get_string_evaluation(l,"r.sub_table.test");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    if(!lua_n.has_errors(l)){
        printf("%s\n",test);
    }

    lua_n.free(l);

    return 0;
}