
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

    int arg1 = (int)LuaCEmbed_get_long_arg(lua,0);
    int arg2 = (int)LuaCEmbed_get_long_arg(lua,1);


    if(LuaCEmbed_has_errors(lua)){

        return NULL;
    }



    return LuaCEmbed_send_long(arg1 + arg2);
}
LuaCEmbedResponse  *create_ob(LuaCEmbed *lua){
    return LuaCEmbed_send_evaluation_function("function () return {a=30} end ");

}





int main(){
//    signal(SIGALRM, alarmante);
    //alarm(3);


    LuaCEmbed * lua = newLuaCEmbed();

    LuaCEmbed_add_callback(lua, "puts", print_lua_value);
    LuaCEmbed_add_callback(lua, "soma", soma);
    LuaCEmbed_add_callback(lua, "create_obj", create_ob);
    LuaCEmbed_set_timeout(lua,4);
    LuaCEmbed_evaluete_file(lua,"teste.lua");

   // char *global = LuaCEmbed_get_global_string(lua,"v");
    if(LuaCEmbed_has_errors(lua)){
        printf("error: %s\n", LuaCEmbed_get_error_message(lua));
    }

    else{
       // printf("global %s\n",global);
        printf("no errors\n");
    }

    LuaCEmbed_free(lua);

}