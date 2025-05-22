#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * show_table(LuaCEmbed *args){

    LuaCEmbedTable * t1 = LuaCEmbed_get_arg_table(args, 0);
    if(LuaCEmbed_has_errors(args)){
        char *message = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(message);
    }

    char *name  = LuaCembedTable_get_string_prop(t1, "name");
    long age = LuaCembedTable_get_long_prop(t1, "age");

    if(LuaCEmbed_has_errors(args)){
        char *message = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(message);
    }

    printf("name : %s\n", name);
    printf("age: %ld\n", age);

    return NULL;
}

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l, "show_table", show_table);
    LuaCEmbed_evaluate(l, "show_table({name='mateus',age=27})");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}