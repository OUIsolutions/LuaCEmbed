

int privateLuaCEmbed_main_callback_handler(lua_State  *L);


void LuaCEmbed_add_callback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) );



