//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../../../imports/imports.consts.h"
//silver_chain_scope_end




char*  LuaCembedTable_get_string_prop(LuaCEmbedTable *self, const char *name);

char*  LuaCembedTable_get_raw_string_prop(LuaCEmbedTable *self, const char *name,lua_Integer *size);

lua_Integer  LuaCembedTable_get_long_prop(LuaCEmbedTable *self, const char *name);

double  LuaCembedTable_get_double_prop(LuaCEmbedTable *self, const char *name);

bool  LuaCembedTable_get_bool_prop(LuaCEmbedTable *self, const char *name);

int  LuaCEmbedTable_get_type_prop(LuaCEmbedTable *self, const char *name);
