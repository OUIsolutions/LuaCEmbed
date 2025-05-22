#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){

    LuaCEmbed *l = newLuaCEmbedEvaluation();

    LuaCEmbed_evaluate(l, "r = {a='internal text'}");
    LuaCEmbedTable *r_table = LuaCembed_get_global_table(l, "r");
    char *a = LuaCembedTable_get_string_prop(r_table, "a");
    printf("value of r.a = %s\n", a);

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}