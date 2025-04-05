

typedef struct {
    LuaCEmbedResponse * (*send_multi_return)(LuaCEmbedTable *table);
    LuaCEmbedResponse * (*send_str)(const char *text);
    LuaCEmbedResponse * (*send_raw_string)(const char *text,lua_Integer size);
    LuaCEmbedResponse * (*send_str_reference)( const char *text);
    LuaCEmbedResponse * (*send_raw_string_reference)(const char *text,lua_Integer size);
    LuaCEmbedResponse * (*send_table)(LuaCEmbedTable *table);
    LuaCEmbedResponse * (*send_evaluation_function)(const char *function);
    LuaCEmbedResponse  * (*send_double)(double value);
    LuaCEmbedResponse  * (*send_bool)(bool value);
    LuaCEmbedResponse  * (*send_long)(lua_Integer value);
    LuaCEmbedResponse * (*send_error)(const char *format,...);

}LuaCEmbedResponseModule;
