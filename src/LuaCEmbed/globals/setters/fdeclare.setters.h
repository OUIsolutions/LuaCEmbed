
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.typesD.h"
//silver_chain_scope_end

void LuaCEmbed_set_global_string(LuaCEmbed *self, const char *name, const  char *value);

void LuaCEmbed_set_global_raw_string(LuaCEmbed *self, const char *name, const  char *value,long size);

void LuaCEmbed_set_global_long(LuaCEmbed *self, const char *name, lua_Integer  value);

void LuaCEmbed_set_global_double(LuaCEmbed *self, const char *name, double value);

void LuaCEmbed_set_global_bool(LuaCEmbed *self, const char *name, bool value);

void LuaCEmbed_set_global_table(LuaCEmbed *self, const char *name, LuaCEmbedTable *table);
