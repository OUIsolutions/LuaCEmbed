


LuaCEmbed * newLuaCEmbed();

char * LuaCEmbed_get_error_message(LuaCEmbed *self);


bool LuaCEmbed_has_errors(LuaCEmbed *self);


int LuaCEmbed_evaluate_string(LuaCEmbed *self, const char *str);


int LuaCEmbed_evaluete_file(LuaCEmbed *self, const char *file);


int privateLuaCEmbed_main_callback_handler(lua_State  *L);


void LuaCEmbed_add_calback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) );




void LuaCEmbed_free(LuaCEmbed *self);


