
#include "src/one.c"

LuaCEmbedResponse * print_lua_value(LuaCEmbed *self){


    

}


int main(){

    LuaCEmbed * lua = newLuaCEmbed();
//    LuaCEmbed_add_calback(lua, "nada", nada);
    LuaCEmbed_add_calback(lua,"puts", print_lua_value);
    LuaCEmbed_evaluete_file(lua,"teste.lua");

    if(LuaCEmbed_has_errors(lua)){
        printf("error: %s\n", LuaCEmbed_get_error_message(lua));
    }
    else{
        printf("no errors\n");
    }

    LuaCEmbed_free(lua);

}