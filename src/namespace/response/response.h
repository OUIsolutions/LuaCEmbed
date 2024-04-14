

typedef struct {
    LuaCEmbedResponse * (*send_str)(const char *text);
    LuaCEmbedResponse * (*send_table)(const char *table_code);
    LuaCEmbedResponse * (*send_evaluation_function)(const char *function);
    LuaCEmbedResponse  * (*send_double)(double value);
    LuaCEmbedResponse  * (*send_bool)(bool value);
    LuaCEmbedResponse  * (*send_long)(long value);

}LuaCEmbedResponseModule;

LuaCEmbedResponseModule newLuaCEmbedResponseModule();