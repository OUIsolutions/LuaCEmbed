


int  LuaCEmbed_get_table_arg_type(LuaCEmbed *self, int index,const char *expresion,...);

char * privateLuaEmbed_table_iteration(LuaCEmbed *self,privateLuaEmbedTableArgs *args,int index,int started_index);

char *  LuaCEmbed_get_table_arg_string(LuaCEmbed *self, int index,const char *expresion,...);

long LuaCEmbed_get_table_arg_long(LuaCEmbed *self, int index,const char *expresion,...);

long LuaCEmbed_get_table_arg_size(LuaCEmbed *self, int index,const char *expresion,...);


double LuaCEmbed_get_table_arg_double(LuaCEmbed *self, int index,const char *expresion,...);

bool LuaCEmbed_get_table_arg_bool(LuaCEmbed *self, int index,const char *expresion,...);

