
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesD.h"
//silver_chain_scope_end

int  private_LuaCemb_internal_free(lua_State *L);

LuaCEmbed * newLuaCEmbedLib(lua_State *state);

int  LuaCembed_perform(LuaCEmbed *self);

int LuaCembed_send_self_as_lib(LuaCEmbed *self);

int LuaCembed_send_global_as_lib(LuaCEmbed *self,const char *global_name);
