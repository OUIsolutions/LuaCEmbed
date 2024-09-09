#include "old/src/one.c"
LuaCEmbedNamespace  lua_n;

int main(int argc, char *argv[]){

    LuaCEmbedTypeModule
    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    //NEVER USE THESE IF YOU DONT TRUSt IN THE CLIENT
    lua_n.load_native_libs(l);
    lua_n.evaluate(l,"print('hello from lua')");
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
