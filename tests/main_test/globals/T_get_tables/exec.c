#include "../../../LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate_string(l,"r = {name='Mateus',age=27, height=1.80, sigle=true}");
    char *name = lua_n.globals.table.get_string(l,"r","{'name'}");
    long age = lua_n.globals.table.get_long(l,"r","{'age'}");
    double height = lua_n.globals.table.get_double(l,"r","{'height'}");
    
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}