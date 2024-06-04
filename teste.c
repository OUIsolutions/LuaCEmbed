
#include "src/one.c"

LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * hello(LuaCEmbed *args){
    printf("my first callback\n");
    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    int one_mega = 1;
    lua_n.set_memory_limit(l,one_mega);
    lua_n.add_callback(l,"teste",hello);
    lua_n.evaluate(l,"teste()");
    lua_n.evaluate(l,"t = 'a';while true do t = t .. t  end");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    lua_n.free(l);

    return 0;
}