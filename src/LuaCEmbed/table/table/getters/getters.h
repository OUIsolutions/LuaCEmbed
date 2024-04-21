






char*  LuaCembedTable_get_string_prop(LuaCEmbedTable *self, const char *name);

long  LuaCembedTable_get_long_prop(LuaCEmbedTable *self, const char *name);

double  LuaCembedTable_get_double_prop(LuaCEmbedTable *self, const char *name);

bool  LuaCembedTable_get_bool_prop(LuaCEmbedTable *self, const char *name);

int  LuaCEmbedTable_get_type_prop(LuaCEmbedTable *self, const char *name);

long  LuaCEmbedTable_get_size(LuaCEmbedTable *self);

long  privateLuaCEmbedTable_convert_index(LuaCEmbedTable *self,long index);

int LuaCEmbedTable_get_type_by_index(LuaCEmbedTable *self, int index);

long LuaCEmbedTable_get_long_by_index(LuaCEmbedTable *self, int index);

double LuaCEmbedTable_get_double_by_index(LuaCEmbedTable *self, int index);

char * LuaCEmbedTable_get_string_by_index(LuaCEmbedTable *self, int index);

bool LuaCEmbedTable_get_bool_by_index(LuaCEmbedTable *self, int index);


