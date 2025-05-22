#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    return LuaCEmbed_send_long(30);
}

int main(int argc, char *argv[]){
    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l, "test", test_func);
    long result = LuaCEmbed_get_evaluation_long(l, "test()");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    printf("result: %ld\n", result);
    
    LuaCEmbed_free(l);
    return 0;
}