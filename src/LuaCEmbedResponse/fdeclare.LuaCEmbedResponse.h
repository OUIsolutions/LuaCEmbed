

LuaCEmbedResponse *private_LuaCEmbedReturn_raw();


LuaCEmbedResponse * LuaCEmbed_send_str(const char *text);

LuaCEmbedResponse * LuaCEmbed_send_raw_string(const char *text,lua_Integer size);

LuaCEmbedResponse * LuaCEmbed_send_str_reference( const char *text);

LuaCEmbedResponse * LuaCEmbed_send_raw_string_reference(const char *text,lua_Integer size);

LuaCEmbedResponse * LuaCEmbed_send_error(const char *format,...);


LuaCEmbedResponse * LuaCEmbed_send_evaluation(const char *code);





LuaCEmbedResponse  * LuaCEmbed_send_double(double value);

LuaCEmbedResponse  * LuaCEmbed_send_bool(bool value);


LuaCEmbedResponse  * LuaCEmbed_send_long(lua_Integer value);


void private_LuaCEmbedResponse_free(LuaCEmbedResponse  *self);


LuaCEmbedResponse * LuaCEmbed_send_table(LuaCEmbedTable *table);


LuaCEmbedResponse * LuaCEmbed_send_multi_return(LuaCEmbedTable *table);
