#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * print_func(LuaCEmbed *args){
    long size = LuaCEmbed_get_total_args(args);
    for(int index = 0; index < size; index++){
        int arg_type = LuaCEmbed_get_arg_type(args, index);

        if(arg_type == LUA_CEMBED_NUMBER){
            printf("%lf\n", LuaCEmbed_get_double_arg(args, index));
        }
        else if(arg_type == LUA_CEMBED_STRING){
            printf("%s\n", LuaCEmbed_get_str_arg(args, index));
        }
        else if(arg_type == LUA_CEMBED_BOOL){
            bool result = LuaCEmbed_get_bool_arg(args, index);
            const char *converted_bool = result ? "true" : "false";
            printf("%s\n", converted_bool);
        }
        else{
            const char *converted_to_str = LuaCembed_convert_arg_code(arg_type);
            printf("%s\n", converted_to_str);
        }
    }
    return NULL;
}

int main(int argc, char *argv[]){
    LuaCEmbed *l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l, "print", print_func);
    LuaCEmbed_evaluate(l, "print(10,30,'aa',true,{a=30})");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);
    return 0;
}