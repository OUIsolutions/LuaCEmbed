

int LuaCEmbed_get_global_type(LuaCEmbed *self,const char *name);

long LuaCEmbed_get_global_long(LuaCEmbed *self,const char *name);

double LuaCEmbed_get_global_double(LuaCEmbed *self,const char *name);

bool LuaCEmbed_get_global_bool(LuaCEmbed *self,const char *name);

char * LuaCEmbed_get_global_string(LuaCEmbed *self,const char *name);

int  LuaCEmbed_get_global_evaluation_type(LuaCEmbed *self, char *code);

char * LuaCEmbed_get_global_evaluation_string(LuaCEmbed *self, char *code);

long LuaCEmbed_get_global_evaluation_size(LuaCEmbed *self, char *code);

long LuaCEmbed_get_global_evaluation_long(LuaCEmbed *self, char *code);

double LuaCEmbed_get_global_evaluation_double(LuaCEmbed *self, char *code);

bool LuaCEmbed_get_global_evaluation_bool(LuaCEmbed *self, char *code);

