

void  LuaCEmbedTable_set_string_by_index(LuaCEmbedTable *self, lua_Integer index, const char *value);

void  LuaCEmbedTable_set_raw_string_by_index(LuaCEmbedTable *self, lua_Integer index, const char *value,lua_Integer size);

void  LuaCEmbedTable_set_long_by_index(LuaCEmbedTable *self, lua_Integer index, lua_Integer  value);

void  LuaCEmbedTable_set_double_by_index(LuaCEmbedTable *self, lua_Integer index, double  value);

void  LuaCEmbedTable_set_bool_by_index(LuaCEmbedTable *self, lua_Integer index, bool value);


void  LuaCEmbedTable_set_evaluation_by_index(LuaCEmbedTable *self, lua_Integer index, const char *code, ...);
