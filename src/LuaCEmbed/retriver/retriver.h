
int  LuaCEmbed_get_total_args(LuaCEmbed *self);

int  LuaCEmbed_get_arg_type(LuaCEmbed *self,int index);


bool LuaCEmbed_has_errors(LuaCEmbed *self);


long LuaCEmbed_get_long_arg(LuaCEmbed *self, int index);

double LuaCEmbed_get_doube_arg(LuaCEmbed *self, int index);

bool LuaCEmbed_get_bool_arg(LuaCEmbed *self, int index);

char * LuaCEmbed_get_str_arg(LuaCEmbed *self, int index);
