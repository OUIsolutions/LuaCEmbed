
typedef struct {
    bool is_error;
    cJSON * value;
}LuaCEmbedReturn;

LuaCEmbedReturn *private_LuaCEmbedReturn_raw();


LuaCEmbedReturn * LuaCEmbed_return_text(const char *text);

LuaCEmbedReturn  * LuaCEmbed_return_double(double value);

LuaCEmbedReturn  * LuaCEmbed_return_long(long value);

LuaCEmbedReturn  * LuaCEmbed_return_xpath(CxpathJson *value);

LuaCEmbedReturn  * LuaCEmbed_return_cJSON(cJSON *value);

LuaCEmbedReturn  * LuaCEmbed_return_error(const char *errror);


void private_LuaCEmbedReturn_free(LuaCEmbedReturn  *self);
