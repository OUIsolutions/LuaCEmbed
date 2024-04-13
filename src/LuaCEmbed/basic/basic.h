


LuaCEmbed * newLuaCEmbed();

char * LuaCEmbed_get_error_message(LuaCEmbed *self);


bool LuaCEmbed_has_errors(LuaCEmbed *self);

void private_LuaCembed_handle_timeout(int signum) ;

void LuaCEmbed_raise_error(LuaCEmbed *self, const char *error);

void LuaCEmbed_set_timeout(LuaCEmbed *self,int seconds);

int LuaCEmbed_evaluate_string(LuaCEmbed *self, const char *str);


int LuaCEmbed_evaluete_file(LuaCEmbed *self, const char *file);


int privateLuaCEmbed_main_callback_handler(lua_State  *L);


void LuaCEmbed_add_callback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) );




void LuaCEmbed_free(LuaCEmbed *self);


