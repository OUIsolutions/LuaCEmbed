#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * create_table(LuaCEmbed *args){

    LuaCEmbedTable *custom_table = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable *sub_table = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_string_prop(sub_table, "test", "custom text");
    LuaCEmbedTable_set_sub_table_prop(custom_table, "sub_table", sub_table);

    return LuaCEmbed_send_table(custom_table);

}

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l, "create_table", create_table);
    LuaCEmbed_evaluate(l, "r = create_table()");

    char *test = LuaCEmbed_get_evaluation_string(l, "r.sub_table.test");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    if(!LuaCEmbed_has_errors(l)){
        printf("%s\n", test);
    }

    LuaCEmbed_free(l);

    return 0;
}