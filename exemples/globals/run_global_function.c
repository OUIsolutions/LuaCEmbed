#include "LuaCEmbedOne.c"


int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();

    LuaCEmbed_evaluate(l,"function test_func(a,b) return a + b end ");

    LuaCEmbedTable * args = LuaCembed_new_anonymous_table(l);
    LuaCEmbedTable_append_long(args,20);
    LuaCEmbedTable_append_long(args,30);
    LuaCEmbedTable *result = LuaCEmbed_run_global_lambda(l,"test_func",args,1);

    double result_0 = LuaCEmbedTable_get_double_by_index(result,0);

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n",LuaCEmbed_get_error_message(l));
    }
    else{
        printf("result 0: %lf\n",result_0);

    }

    LuaCEmbed_free(l);

    return 0;
}