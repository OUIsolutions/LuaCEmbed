#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();

    LuaCEmbed_set_global_double(l, "r", 30);
    double result = LuaCEmbed_get_global_double(l, "r");
    printf("result %lf\n", result);

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}