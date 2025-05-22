#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();

    LuaCEmbedTable *created = LuaCembed_new_global_table(l, "r");
    LuaCEmbedTable_set_string_prop(created, "a", "internal text");

    char *a = LuaCembedTable_get_string_prop(created, "a");
    printf("result of r.a %s\n", a);

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}