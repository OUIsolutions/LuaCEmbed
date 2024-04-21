

int LuaCEmbed_get_global_type(LuaCEmbed *self,const char *name);

long LuaCEmbed_get_global_long(LuaCEmbed *self,const char *name);

double LuaCEmbed_get_global_double(LuaCEmbed *self,const char *name);

bool LuaCEmbed_get_global_bool(LuaCEmbed *self,const char *name);

char * LuaCEmbed_get_global_string(LuaCEmbed *self,const char *name);

LuaCEmbedTable * LuaCembed_new_anonymous_table(LuaCEmbed *self);


LuaCEmbedTable * LuaCembed_get_global_table_auto_creating(LuaCEmbed *self, const char *name);

LuaCEmbedTable * LuaCembed_new_global_table(LuaCEmbed *self, const char *name);
