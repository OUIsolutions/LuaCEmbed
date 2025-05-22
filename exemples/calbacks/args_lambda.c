#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * test_func(LuaCEmbed *args){

    LuaCEmbedTable *created = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_long(created,10);
    LuaCEmbedTable_append_long(created,20);
    LuaCEmbedTable *response = LuaCEmbed_run_args_lambda(args,0,created,3);
    double result = LuaCEmbedTable_get_double_by_index(response,0);

    printf("result %lf\n",result);

    return NULL;
}

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l,"test",test_func);

    LuaCEmbed_evaluate(l,"test(function (a,b) return a + b end )"); 


    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n",LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}