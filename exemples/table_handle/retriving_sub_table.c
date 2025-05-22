#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * show_table(LuaCEmbed *args){

    LuaCEmbedTable * t1 = LuaCEmbed_get_arg_table(args, 0);
    if(LuaCEmbed_has_errors(args)){
        char *message = LuaCEmbed_get_error_message(args);
        return  LuaCEmbed_send_error(message);
    }

    long size = LuaCEmbedTable_get_listable_size(t1);
    for(int i = 0; i < size; i++){

        LuaCEmbedTable *current = LuaCEmbedTable_get_sub_table_by_index(t1, i);
        char *name  = LuaCembedTable_get_string_prop(current, "name");
        long age = LuaCembedTable_get_long_prop(current, "age");

        if(LuaCEmbed_has_errors(args)){
            char *message = LuaCEmbed_get_error_message(args);
            return  LuaCEmbed_send_error(message);
        }

        printf("name : %s\n", name);
        printf("age: %ld\n", age);

        printf("------------------------------------------\n");
    }
    
    return NULL;

}
int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l, "show_table", show_table);
    LuaCEmbed_evaluate(l, "show_table({{name='mateus',age=27},{name='john',age=30}} )");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}