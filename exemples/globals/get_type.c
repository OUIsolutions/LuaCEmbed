#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();

    LuaCEmbed_evaluate(l, "r = 'hello world'");
    int type_code = LuaCEmbed_get_global_type(l, "r");
    const char *converted_type = LuaCembed_convert_arg_code(type_code);
    printf("result %s\n", converted_type);

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}