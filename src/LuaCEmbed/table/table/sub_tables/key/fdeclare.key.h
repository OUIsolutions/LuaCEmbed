//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../../../imports/imports.consts.h"
//silver_chain_scope_end


LuaCEmbedTable  *LuaCEmbedTable_new_sub_table_by_key(LuaCEmbedTable *self, const char *name);

LuaCEmbedTable  *LuaCEmbedTable_get_sub_table_by_key(LuaCEmbedTable *self, const char *name);

void LuaCEmbedTable_set_sub_table_prop(LuaCEmbedTable *self, const char *name, LuaCEmbedTable *sub_table);