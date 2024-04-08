
#include "src/one.c"

LuaCEmbedReturn  * nada(LuaCEmbed *self){


    const char * teste =  "function extrai(f)\n return f['a'] \nend";
    LuaCEmbed_evaluate_string(self,teste);

    lua_getglobal(self->state, "extrai");
    lua_pushvalue(self->state,1);

    lua_pcall(self->state,1,1,0);

    printf("valor: %s\n", lua_tostring(self->state,-1));

    return NULL;

}

int main(){

    LuaCEmbed * lua = newLuaCEmbed();
    LuaCEmbed_add_calback(lua, "nada", nada);

    LuaCEmbed_evaluete_file(lua,"teste.lua");
    LuaCEmbed_free(lua);

}