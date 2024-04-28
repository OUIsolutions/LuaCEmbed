

LuaCEmbedTable  *LuaCEmbedTable_get_sub_table_auto_creating_by_key(LuaCEmbedTable *self, const char *name);

LuaCEmbedTable  *LuaCEmbedTable_get_sub_table_by_index_auto_creating(LuaCEmbedTable *self, int index);

LuaCEmbedTable  *LuaCEmbedTable_new_sub_table_by_key(LuaCEmbedTable *self, const char *name);

void LuaCEmbedTable_set_sub_table_by_key(LuaCEmbedTable *self, const char *name, LuaCEmbedTable *sub_table);