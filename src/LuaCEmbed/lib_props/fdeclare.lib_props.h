//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.consts.h"
//silver_chain_scope_end



void LuaCEmbed_set_long_lib_prop(LuaCEmbed *self,const char *name,lua_Integer value);

void LuaCEmbed_set_double_lib_prop(LuaCEmbed *self,const char *name,double value);

void LuaCEmbed_set_bool_lib_prop(LuaCEmbed *self,const char *name,bool value);

void LuaCEmbed_set_string_lib_prop(LuaCEmbed *self,const char *name,const char * value);

void LuaCEmbed_set_table_lib_prop(LuaCEmbed *self,const char *name,LuaCEmbedTable *value);

int private_LuaCEmbed_ensure_lib_prop_type(LuaCEmbed *self,const char *name,int expected_type);;


lua_Integer LuaCEmbed_get_long_lib_prop(LuaCEmbed *self,const char *name);

double LuaCEmbed_get_double_lib_prop(LuaCEmbed *self,const char *name);

bool LuaCEmbed_get_bool_lib_prop(LuaCEmbed *self,const char *name);

char * LuaCEmbed_get_string_lib_prop(LuaCEmbed *self,const char *name);

LuaCEmbedTable *LuaCEmbed_get_table_lib_prop(LuaCEmbed *self,const char *name);
