#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * hello(LuaCEmbed *args){
    printf("hello world");
    return NULL;
}

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l,"hello",hello);

    LuaCEmbed_evaluete_file(l,"tests/target/hello.lua");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n",LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}