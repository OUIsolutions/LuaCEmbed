
#include "src/one.c"

LuaCEmbedReturn  * nada(LuaCEmbed *self){

    char *result = LuaCEmbed_get_table_arg_string(self,0,"['a']['b']");

    printf("%s\n",result);
    return NULL;

}

int main(){

    LuaCEmbed * lua = newLuaCEmbed();
//    LuaCEmbed_add_calback(lua, "nada", nada);

    LuaCEmbed_evaluete_file(lua,"teste.lua");

    if(LuaCEmbed_has_errors(lua)){
        printf("%s", LuaCEmbed_get_error_message(lua));
    }
    
    LuaCEmbed_free(lua);

}