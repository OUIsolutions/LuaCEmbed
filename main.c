
#include "src/one.c"

<<<<<<< HEAD
LuaCEmbedReturn  * nada(LuaCEmbed *self){


    printf("int arg %d\n", LuaCEmbed_get_arg_type(self,0));

=======
LuaCEmbedResponse * print_lua_value(LuaCEmbed *values){
    if(LuaCEmbed_get_arg_type(values,0) == LUA_CEMBED_NUMBER){
        printf("%lf\n", LuaCEmbed_get_double_arg(values,0));
    }
>>>>>>> origin/table_getting

    if(LuaCEmbed_get_arg_type(values,0) == LUA_CEMBED_STRING){
        printf("%s\n", LuaCEmbed_get_str_arg(values,0));
    }
    return NULL;

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