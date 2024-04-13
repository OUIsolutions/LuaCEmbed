
#include "src/one.c"

LuaCEmbedReturn  * nada(LuaCEmbed *self){


    printf("int arg %d\n", LuaCEmbed_get_arg_type(self,0));


    return NULL;

}

int main(){

    LuaCEmbed * lua = newLuaCEmbed();
    LuaCEmbed_add_calback(lua, "nada", nada);
    LuaCEmbed_evaluete_file(lua,"teste.lua");
    LuaCEmbed_free(lua);
    printf("chamu depois\n");

}