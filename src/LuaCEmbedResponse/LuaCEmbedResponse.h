
typedef struct {

    int type;
    double num_val;
    char *string_val;

}LuaCEmbedResponse;

LuaCEmbedResponse *private_LuaCEmbedReturn_raw();


LuaCEmbedResponse * LuaCEmbed_send_str(const char *text);

LuaCEmbedResponse * LuaCEmbed_send_table(const char *table_code);


LuaCEmbedResponse * LuaCEmbed_send_evaluation_function(const char *function);



LuaCEmbedResponse  * LuaCEmbed_send_double(double value);

LuaCEmbedResponse  * LuaCEmbed_send_bool(bool value);


LuaCEmbedResponse  * LuaCEmbed_send_long(long value);


void private_LuaCEmbedResponse_free(LuaCEmbedResponse  *self);
