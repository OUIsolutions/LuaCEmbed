#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    LuaCEmbedTable *created = lua_n.globals.new_table(l,"r");
    lua_n.tables.set_string_prop(created,"a","internal text");

    char *a =  lua_n.tables.get_string_prop_by_field(created,"a");
    printf("result of r.a %s\n",a);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}