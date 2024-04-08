


LuaCEmbed * newLuaCEmbed();



void LuaCEmbed_evaluate_string(LuaCEmbed *self, const char *str);


int privateLuaCEmbed_main_callback_handler(lua_State  *L);


void LuaCEmbed_add_calback(LuaCEmbed *self, const char *callback_name, LuaCEmbedReturn* (*callback)(LuaCEmbed *args) );


void LuaCEmbed_evaluete_file(LuaCEmbed *self, const char *file);


void LuaCEmbed_free(LuaCEmbed *self);


