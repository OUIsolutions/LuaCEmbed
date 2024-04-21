
LuaCEmbedTable  *privateLuaCEmbedTable_append_or_create(LuaCEmbedTable *self,const char *full_sub_name,const char *name);

LuaCEmbedTable  *LuaCEmbedTable_get_sub_table_auto_creating(LuaCEmbedTable *self, const char *name);

LuaCEmbedTable  *LuaCEmbedTable_new_sub_table(LuaCEmbedTable *self, const char *name);

void LuaCEmbedTable_set_sub_table(LuaCEmbedTable *self,const char *name,LuaCEmbedTable *sub_table);