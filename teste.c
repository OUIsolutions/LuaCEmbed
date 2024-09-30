

#include "src/one.c"
LuaCEmbedNamespace  lua_n;

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate(l,"r = 30");
    long calc = lua_n.get_evaluation_long(l,"r + 20");
    printf("result %ld",calc);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
