#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    return LuaCEmbed_send_error("my custom error menssage");
}
int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l,"test",test_func);


   LuaCEmbed_evaluate(l,"test()");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n",LuaCEmbed_get_error_message(l));
    }

    LuaCEmbed_free(l);

    return 0;
}