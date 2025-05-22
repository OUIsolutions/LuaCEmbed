#include "LuaCEmbedOne.c"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    int type_code  = lua_n.globals.get_type(l,"r");
    const char *converted_type = lua_n.convert_arg_code(type_code);
    printf("result %s\n",converted_type);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}