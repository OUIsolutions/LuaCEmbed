#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    int one_mega = 1;
    LuaCEmbed_set_memory_limit(l, one_mega);
    LuaCEmbed_evaluate(l, "t = 'a';while true do t = t .. t end");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }

    LuaCEmbed_free(l);

    return 0;
}