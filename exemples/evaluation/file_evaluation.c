#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * hello(LuaCEmbed *args){
    printf("hello world");
    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"hello",hello);

    lua_n.evaluete_file(l,"tests/target/hello.lua");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}