
#include "src/one.c"

LuaCEmbedReturn  * nada(LuaCEmbed *self){


    printf("%s\n", LuaCEmbed_get_table_arg_string(self,0,"['a']['b']"));
    lua_pop(self->state, 1); // Remove a mensagem de erro da pilha
    printf("%s\n", LuaCEmbed_get_table_arg_string(self,0,"['a']['b']"));

    return NULL;

}

int main(){

    LuaCEmbed * lua = newLuaCEmbed();
    LuaCEmbed_add_calback(lua, "nada", nada);

    LuaCEmbed_evaluete_file(lua,"teste.lua");
    LuaCEmbed_free(lua);

}