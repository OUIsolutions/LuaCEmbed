#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();

    LuaCEmbed_evaluate(l,"r = 'hello world'");
    char * result = LuaCEmbed_get_global_string(l,"r");
    printf("result %s\n",result);

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n",LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}