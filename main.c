
#include "src/one.c"

LuaCEmbedReturn  * nada(LuaCEmbed *self){


    printf("%d\n", LuaCEmbed_get_table_arg_type(self,0,"['a']"));
    printf("%s\n", lua_tostring(self->state,-1));

    return NULL;

}

int main(){

    LuaCEmbed * lua = newLuaCEmbed();
    LuaCEmbed_add_calback(lua, "nada", nada);

    LuaCEmbed_evaluete_file(lua,"teste.lua");
    LuaCEmbed_free(lua);

}