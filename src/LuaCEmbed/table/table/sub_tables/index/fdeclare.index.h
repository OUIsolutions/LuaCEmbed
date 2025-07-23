//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../../../imports/imports.consts.h"
//silver_chain_scope_end



LuaCEmbedTable  *LuaCEmbedTable_new_sub_table_appending(LuaCEmbedTable *self);


LuaCEmbedTable  *LuaCEmbedTable_get_sub_table_by_index(LuaCEmbedTable *self, lua_Integer index);


void LuaCEmbedTable_set_sub_table_by_index(LuaCEmbedTable *self, lua_Integer index,LuaCEmbedTable *sub_table);
