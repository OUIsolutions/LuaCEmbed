#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * describe(LuaCEmbedTable  *self, LuaCEmbed *args){
    char *name = LuaCembedTable_get_string_prop(self, "name");
    long age  = LuaCembedTable_get_long_prop(self, "age");
    double height = LuaCembedTable_get_double_prop(self, "height");
    bool married = LuaCembedTable_get_bool_prop(self, "married");
    printf("person description:\n");
    printf("name: %s\n", name);
    printf("age: %ld\n", age);
    printf("height: %lf\n", height);
    printf("married %d\n", married);
    return NULL;
}

LuaCEmbedResponse  * create_table(LuaCEmbed *args){
    LuaCEmbedTable *custom_table = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_string_prop(custom_table, "name", "Mateus");
    LuaCEmbedTable_set_long_prop(custom_table, "age", 27);
    LuaCEmbedTable_set_double_prop(custom_table, "height", 1.82);
    LuaCEmbedTable_set_bool_prop(custom_table, "married", false);
    LuaCEmbedTable_set_method(custom_table, "describe", describe);
    return LuaCEmbed_send_table(custom_table);
}

int main(int argc, char *argv[]){
    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l, "create_person", create_table);
    LuaCEmbed_evaluate(l, "r = create_person()");
    LuaCEmbed_evaluate(l, "r.describe()");
    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);
    return 0;
}
