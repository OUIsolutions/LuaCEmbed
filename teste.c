
#include "src/one.c"
LuaCEmbedNamespace  lua_n;

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    luaL_openlibs(l->state);  // Abre todas as bibliotecas padrão, incluindo a base

    lua_n.evaluate(l,"os.execute('echo hello')");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}

