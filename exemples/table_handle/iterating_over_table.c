#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * show_table(LuaCEmbed *args){

    LuaCEmbedTable * t1 = LuaCEmbed_get_arg_table(args, 0);
    if(LuaCEmbed_has_errors(args)){
        char *message = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(message);
    }
    long size = LuaCEmbedTable_get_listable_size(t1);
    for(int i = 0; i < size; i++){
        printf("index: %d\n", i);
        const char *key = "Not provided";
        if(LuaCembedTable_has_key_at_index(t1, i)){
            key = LuaCembedTable_get_key_by_index(t1, i);
        }
        printf("key: %s\n", key);

        int type = LuaCEmbedTable_get_type_by_index(t1, i);
        printf("type %s\n", LuaCembed_convert_arg_code(type));

        if(type == LUA_CEMBED_NUMBER){
            double value = LuaCEmbedTable_get_double_by_index(t1, i);
            printf("value: %lf\n", value);
        }

        if(type == LUA_CEMBED_STRING){
            char * value = LuaCEmbedTable_get_string_by_index(t1, i);
            printf("value: %s\n", value);
        }

        if(type == LUA_CEMBED_BOOL){
            bool value = LuaCEmbedTable_get_bool_by_index(t1, i);
            printf("value: %d\n", value);
        }
        printf("------------------------------------------\n");
    }
    return NULL;
}

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l, "show_table", show_table);
    LuaCEmbed_evaluate(l, "show_table({name='Mateus',age=27,single=true,'indexable random string'})");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}
