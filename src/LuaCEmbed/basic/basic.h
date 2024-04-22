


LuaCEmbed * newLuaCEmbedEvaluation();

int private_LuaCemb_internal_free(lua_State *L);


void * private_LuaCembed_get_table_or_create_internal(LuaCEmbed *self, const char *name);

LuaCEmbed * newLuaCEmbedLib(lua_State *state,bool public_functions);


void LuaCembed_set_delete_function(LuaCEmbed *self,void (*delelte_function)(struct  LuaCEmbed *self));

void LuaCembed_perform(LuaCEmbed *self);

char * LuaCEmbed_get_error_message(LuaCEmbed *self);


bool LuaCEmbed_has_errors(LuaCEmbed *self);

void private_LuaCembed_handle_timeout(int signum) ;

void privateLuaCEmbed_raise_error_not_jumping(LuaCEmbed *self, const char *error, ...);

/*
void LuaCEmbed_raise_error_jumping(LuaCEmbed *self, const char *error, ...);
*/
void LuaCEmbed_set_timeout(LuaCEmbed *self,int seconds);


void LuaCEmbed_free(LuaCEmbed *self);


