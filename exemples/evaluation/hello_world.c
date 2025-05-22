#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){
    
    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_evaluate(l, "r = 30");
    long calc = LuaCEmbed_get_evaluation_long(l, "r + 20");
    printf("result %ld", calc);
    
    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}