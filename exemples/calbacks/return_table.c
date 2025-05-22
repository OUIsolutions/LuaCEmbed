#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    LuaCEmbedTable *created = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_string_prop(created,"a","test message");
    return LuaCEmbed_send_table(created);
}
int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l,"test",test_func);


    LuaCEmbed_evaluate(l,"created_table = test()");
    LuaCEmbedTable *created = LuaCembed_get_global_table(l,"created_table");
    char *a = LuaCEmbedTable_get_string_prop(created,"a");
    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n",LuaCEmbed_get_error_message(l));
    }

   printf("value of created.a = %s\n",a);
    
    LuaCEmbed_free(l);

    return 0;
}