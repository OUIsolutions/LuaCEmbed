
typedef struct {

    int type;
    double num_val;
    char *string_val;

}LuaCEmbedResponse;

LuaCEmbedResponse *private_LuaCEmbedReturn_raw();


LuaCEmbedResponse * LuaCEmbed_send_str(const char *text);

LuaCEmbedResponse  * LuaCEmbed_send_double(double value);

LuaCEmbedResponse  * LuaCEmbed_send_long(long value);


void private_LuaCEmbedResponse_free(LuaCEmbedResponse  *self);
