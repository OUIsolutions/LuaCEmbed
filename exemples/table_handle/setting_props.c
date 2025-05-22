#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * create_table(LuaCEmbed *args){

    LuaCEmbedTable *custom_table = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_string_prop(custom_table, "name", "Mateus");
    LuaCEmbedTable_set_long_prop(custom_table, "age", 27);
    LuaCEmbedTable_set_double_prop(custom_table, "height", 1.82);
    LuaCEmbedTable_set_bool_prop(custom_table, "married", false);
    return LuaCEmbed_send_table(custom_table);

}

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l, "create_person", create_table);
    LuaCEmbed_evaluate(l, "r = create_person()");

    char *name = LuaCEmbed_get_evaluation_string(l, "r.name");
    long age  = LuaCEmbed_get_evaluation_long(l, "r.age");
    double height = LuaCEmbed_get_evaluation_double(l, "r.height");
    bool married = LuaCEmbed_get_evaluation_bool(l, "r.married");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    if(!LuaCEmbed_has_errors(l)){
        printf("name: %s\n", name);
        printf("age: %ld\n", age);
        printf("height: %lf\n", height);
        printf("married %d\n", married);
    }

    LuaCEmbed_free(l);

    return 0;
}