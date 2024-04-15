


LuaCEmbed * newLuaCEmbedEvaluation();

int private_LuaCemb_internal_free(lua_State *L);

LuaCEmbed * newLuaCEmbedLib(lua_State *state,bool public_functions);

void LuaCembed_perform(LuaCEmbed *self);

char * LuaCEmbed_get_error_message(LuaCEmbed *self);


bool LuaCEmbed_has_errors(LuaCEmbed *self);

void private_LuaCembed_handle_timeout(int signum) ;

void LuaCEmbed_raise_error(LuaCEmbed *self, const char *error);



void LuaCEmbed_set_timeout(LuaCEmbed *self,int seconds);

int LuaCEmbed_evaluate_string(LuaCEmbed *self, const char *str);


int LuaCEmbed_evaluete_file(LuaCEmbed *self, const char *file);



void LuaCEmbed_free(LuaCEmbed *self);


