#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){
    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_evaluate(l, "r = true");

    bool result = LuaCEmbed_get_evaluation_bool(l, "r");
    printf("result: %d\n", result);
    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}