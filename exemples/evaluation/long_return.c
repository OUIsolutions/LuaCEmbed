#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){

    LuaCEmbed *l = newLuaCEmbedEvaluation();
    LuaCEmbed_evaluate(l, "r = 20 + 30");

    long result = LuaCEmbed_get_evaluation_long(l, "r");
    printf("result: %ld\n", result);
    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}