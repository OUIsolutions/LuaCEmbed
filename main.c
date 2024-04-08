
#include "src/one.c"

LuaCEmbedReturn  * nada(LuaCEmbed *self){
    printf("teste\n");
}

int main(){

    LuaCEmbed * lua = newLuaCEmbed();

    LuaCEmbed_push_function(lua,"nada",nada);
    LuaCEmbed_evaluete_file(lua,"teste.lua");

    LuaCEmbed_free(lua);


}