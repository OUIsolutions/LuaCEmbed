#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * create_table(LuaCEmbed *args){

    LuaCEmbedTable *custom_table = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_append_string(custom_table,"test1");
    LuaCEmbedTable_append_string(custom_table,"test2");
    LuaCEmbedTable_append_string(custom_table,"test3");

    return LuaCEmbed_send_table(custom_table);

}

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l,"create_string_array", create_table);
    LuaCEmbed_evaluate(l,"r = create_string_array()");
    LuaCEmbedTable *table = LuaCembed_get_global_table(l,"r");
    long size = LuaCEmbedTable_get_listable_size(table);

    for(int i = 0; i < size; i++){
        char  *current = LuaCEmbedTable_get_string_by_index(table,i);
        if(!LuaCEmbed_has_errors(l)){
            printf("%s\n",current);
        }
    }

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n",LuaCEmbed_get_error_message(l));
    }

    LuaCEmbed_free(l);

    return 0;
}