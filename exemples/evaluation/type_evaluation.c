#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_evaluate(l, "r = 'hello world'");

    int r_type = LuaCEmbed_get_evaluation_type(l, "r");
    const char* converted = LuaCembed_convert_arg_code(r_type);
    printf("result: %s\n", converted);
    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}