
#include "src/one.c"

LuaCEmbedResponse * print_lua_value(LuaCEmbed *lua){
    if(LuaCEmbed_get_arg_type(lua,0) == LUA_CEMBED_NUMBER){
        printf("%lf\n", LuaCEmbed_get_double_arg(lua,0));
    }

    if(LuaCEmbed_get_arg_type(lua,0) == LUA_CEMBED_STRING){
        printf("%s\n", LuaCEmbed_get_str_arg(lua,0));
    }
    return NULL;

}
LuaCEmbedResponse * soma(LuaCEmbed *lua){
    int arg1 = LuaCEmbed_get_long_arg(lua,0);
    int arg2 = LuaCEmbed_get_long_arg(lua,1);

    return LuaCEmbed_send_long(arg1 + arg2);
}


int main(){

    LuaCEmbed * lua = newLuaCEmbed();
//    LuaCEmbed_add_calback(lua, "nada", nada);
    LuaCEmbed_add_calback(lua,"puts", print_lua_value);
    LuaCEmbed_add_calback(lua,"soma", soma);

    LuaCEmbed_evaluete_file(lua,"teste.lua");

    if(LuaCEmbed_has_errors(lua)){
        printf("error: %s\n", LuaCEmbed_get_error_message(lua));
    }
    else{
        printf("no errors\n");
    }

    LuaCEmbed_free(lua);

}