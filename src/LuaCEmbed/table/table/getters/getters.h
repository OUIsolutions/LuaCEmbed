


int privateLuaCEmbedTable_ensure_type(LuaCEmbedTable *self,const char *name, int expected_type);


int LuaCEmbedTable_get_type_by_index(LuaCEmbedTable *self, int index);


char*  LuaCembedTable_get_string_prop(LuaCEmbedTable *self, const char *name);

long  LuaCembedTable_get_long_prop(LuaCEmbedTable *self, const char *name);

double  LuaCembedTable_get_double_prop(LuaCEmbedTable *self, const char *name);

bool  LuaCembedTable_get_bool_prop(LuaCEmbedTable *self, const char *name);

long  LuaCEmbedTable_get_size(LuaCEmbedTable *self);

int  LuaCEmbedTable_get_type_prop(LuaCEmbedTable *self, const char *name);
