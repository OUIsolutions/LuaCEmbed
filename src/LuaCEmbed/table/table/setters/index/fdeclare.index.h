//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../../../imports/imports.consts.h"
//silver_chain_scope_end


void  LuaCEmbedTable_set_string_by_index(LuaCEmbedTable *self, lua_Integer index, const char *value);

void  LuaCEmbedTable_set_raw_string_by_index(LuaCEmbedTable *self, lua_Integer index, const char *value,lua_Integer size);

void  LuaCEmbedTable_set_long_by_index(LuaCEmbedTable *self, lua_Integer index, lua_Integer  value);

void  LuaCEmbedTable_set_double_by_index(LuaCEmbedTable *self, lua_Integer index, double  value);

void  LuaCEmbedTable_set_bool_by_index(LuaCEmbedTable *self, lua_Integer index, bool value);


void  LuaCEmbedTable_set_evaluation_by_index(LuaCEmbedTable *self, lua_Integer index, const char *code, ...);

void LuaCEmbedTable_copy_index_to_global_var(LuaCEmbedTable *self,lua_Integer index, const char *name);

void LuaCEmbedTable_set_table_index_with_table_prop(LuaCEmbedTable *self, lua_Integer self_index, LuaCEmbedTable *table,const char * table_prop );

void LuaCEmbedTable_set_table_index_with_table_index(LuaCEmbedTable *self, lua_Integer self_index, LuaCEmbedTable *table,const char * table_index );