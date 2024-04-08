
#include "src/one.c"

LuaCEmbedReturn  * nada(LuaCEmbed *self){

    char *result = LuaCEmbed_get_table_arg_string(self,0,"['a']['c']");
    printf("%d\n",lua_type(self->state, -1) );
   // printf("%s\n", LuaCEmbed_get_table_arg_string(self,0,"['a']['b']"));

    return NULL;

}

int main(){

    LuaCEmbed * lua = newLuaCEmbed();
    LuaCEmbed_add_calback(lua, "nada", nada);

    LuaCEmbed_evaluete_file(lua,"teste.lua");
    LuaCEmbed_free(lua);

}