
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../../imports/imports.macros.h"
//silver_chain_scope_end


LuaCEmbedTable * private_newLuaCembedTable(LuaCEmbed *main_embed, const char *format, ...);

int  private_lua_cEmbed_unpack(LuaCEmbedTable *self,const char * previews_function);

void privateLuaCEmbedTable_free(LuaCEmbedTable *self);

void privateLuaCEmbedTable_free_setting_nill(LuaCEmbedTable *self);