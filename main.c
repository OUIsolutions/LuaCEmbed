
#include "src/one.c"

LuaCEmbedReturn  * nada(LuaCEmbed *self){


    printf("int arg %ld\n", LuaCEmbed_get_long_arg(self,0));
    printf("str arg %s\n", LuaCEmbed_get_str_arg(self,0));

    return NULL;

}

int main(){

    LuaCEmbed * lua = newLuaCEmbed();
    LuaCEmbed_add_calback(lua, "nada", nada);
    LuaCEmbed_evaluete_file(lua,"teste.lua");
    LuaCEmbed_free(lua);


}