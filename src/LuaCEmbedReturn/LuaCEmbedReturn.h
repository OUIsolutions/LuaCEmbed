
typedef struct {
    bool is_error;
    cJSON * value;
}LuaCEmbedReturn;

LuaCEmbedReturn *private_LuaCEmbedReturn_raw();


LuaCEmbedReturn * LuaCEmbedReturn_text(const char *text);

LuaCEmbedReturn  * LuaCEmbedReturn_double(double value);

LuaCEmbedReturn  * LuaCEmbedReturn_long(long value);

LuaCEmbedReturn  * LuaCEmbedReturn_cJSON(cJSON *value);

LuaCEmbedReturn  * LuaCEmbedReturn_error(const char *errror);


void private_LuaCEmbedReturn_free(LuaCEmbedReturn  *self);
