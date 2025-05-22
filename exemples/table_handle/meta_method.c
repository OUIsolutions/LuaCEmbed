#include "LuaCEmbedOne.c"

LuaCEmbedResponse * index_callback(LuaCEmbedTable *self, LuaCEmbed *args){
    int value_type = LuaCEmbed_get_arg_type(args, 1);
    if(value_type == LUA_CEMBED_NUMBER){
        printf("index-value: %lf\n", LuaCEmbed_get_double_arg(args, 1));
    }
    else if(value_type == LUA_CEMBED_STRING){
        printf("index-value: %s\n", LuaCEmbed_get_str_arg(args, 1));
    }
    return NULL;
}

LuaCEmbedResponse * deletion_callback(LuaCEmbedTable *self, LuaCEmbed *args){
    printf("called the delete function\n");
    return NULL;
}

LuaCEmbedResponse * create_table(LuaCEmbed *args){
    LuaCEmbedTable *custom_table = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_method(custom_table, "__gc", deletion_callback);
    LuaCEmbedTable_set_method(custom_table, "__index", index_callback);
    return LuaCEmbed_send_table(custom_table);
}

int main(int argc, char *argv[]){
    LuaCEmbed *l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l, "create_object", create_table);
    LuaCEmbed_evaluate(l, "r = create_object()");
    LuaCEmbed_evaluate(l, "v = r[10]");
    LuaCEmbed_evaluate(l, "v = r['sss']");
    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);
    return 0;
}
