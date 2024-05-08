

typedef struct {
    LuaCEmbedResponse * (*send_multi_return)(LuaCEmbedTable *table);
    LuaCEmbedResponse * (*send_str)(const char *text);
    LuaCEmbedResponse * (*send_table)(LuaCEmbedTable *table);
    LuaCEmbedResponse * (*send_evaluation_function)(const char *function);
    LuaCEmbedResponse  * (*send_double)(double value);
    LuaCEmbedResponse  * (*send_bool)(bool value);
    LuaCEmbedResponse  * (*send_long)(long value);
    LuaCEmbedResponse * (*send_error)(const char *text);

}LuaCEmbedResponseModule;

LuaCEmbedResponseModule newLuaCEmbedResponseModule();