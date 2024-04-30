


LuaCEmbed * newLuaCEmbedEvaluation();

int private_LuaCemb_internal_free(lua_State *L);




LuaCEmbed * newLuaCEmbedLib(lua_State *state,bool public_functions);


void LuaCembed_set_delete_function(LuaCEmbed *self,void (*delelte_function)(struct  LuaCEmbed *self));

int LuaCembed_perform(LuaCEmbed *self);

char * LuaCEmbed_get_error_message(LuaCEmbed *self);


bool LuaCEmbed_has_errors(LuaCEmbed *self);

void LuaCEmbed_clear_errors(LuaCEmbed *self);

void private_LuaCembed_handle_timeout(int signum) ;

void privateLuaCEmbed_raise_error_not_jumping(LuaCEmbed *self, const char *error, ...);

void * privateLuaCEmbed_get_current_table_array(LuaCEmbed *self);

void LuaCEmbed_set_timeout(LuaCEmbed *self,int seconds);


void LuaCEmbed_free(LuaCEmbed *self);


