#include "../../../LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;



int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation_with_custom_allocator();
    int one_mega = 1;
    lua_n.set_memory_limit(l,one_mega);
    lua_n.evaluate(l,"t = 'a';while true do t = t .. t  end");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    lua_n.free(l);

    return 0;
}