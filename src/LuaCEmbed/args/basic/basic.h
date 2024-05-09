
int  LuaCEmbed_get_total_args(LuaCEmbed *self);

int  LuaCEmbed_get_arg_type(LuaCEmbed *self,int index);



long LuaCEmbed_get_long_arg(LuaCEmbed *self, int index);

double LuaCEmbed_get_double_arg(LuaCEmbed *self, int index);

bool LuaCEmbed_get_bool_arg(LuaCEmbed *self, int index);

char * LuaCEmbed_get_str_arg(LuaCEmbed *self, int index);

LuaCEmbedTable  * LuaCEmbed_get_arg_table(LuaCEmbed *self,int index);

LuaCEmbedTable* LuaCEmbed_run_callback_lambda(LuaCEmbed *self, int index, LuaCEmbedTable *args,int total_returns);

