#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    LuaCEmbedTable * multi_response = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_string(multi_response, "first");
    LuaCEmbedTable_append_long(multi_response, 10);
    return LuaCEmbed_send_multi_return(multi_response);
}

int main(int argc, char *argv[]){
    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l, "test", test_func);

    LuaCEmbed_evaluate(l, "a,b = test()");
    char *a = LuaCEmbed_get_evaluation_string(l, "a");
    long b = LuaCEmbed_get_evaluation_long(l, "b");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    printf("a = %s\n", a);
    printf("b = %ld\n", b);

    LuaCEmbed_free(l);

    return 0;
}