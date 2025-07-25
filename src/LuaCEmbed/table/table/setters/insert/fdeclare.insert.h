//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../../../imports/imports.consts.h"
//silver_chain_scope_end



void  private_LuaCEmbedTable_add_space(LuaCEmbedTable *self, lua_Integer formatted_index);

void  LuaCEmbedTable_insert_string_at_index(LuaCEmbedTable *self, lua_Integer index, const char *value);

void  LuaCEmbedTable_insert_bool_at_index(LuaCEmbedTable *self, lua_Integer index,bool value);

void  LuaCEmbedTable_insert_long_at_index(LuaCEmbedTable *self,lua_Integer  index,lua_Integer value);

void  LuaCEmbedTable_insert_double_at_index(LuaCEmbedTable *self, lua_Integer index,double value);

void  LuaCEmbedTable_insert_table_at_index(LuaCEmbedTable *self, lua_Integer index,LuaCEmbedTable *table);
