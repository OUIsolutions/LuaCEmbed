


int LuaCEmbed_evaluate_string_no_return(LuaCEmbed *self, const char *code,...);

int LuaCEmbed_evaluete_file(LuaCEmbed *self, const char *file);


int private_LuaCEmbed_ensure_evaluation_type(LuaCEmbed *self,int type);

int private_LuaCEmbed_evaluate_puting_on_top_of_stack(LuaCEmbed *self,char *code, va_list args);

char * LuaCEmbed_get_evaluation_string(LuaCEmbed *self, char *code, ...);


int  LuaCEmbed_get_evaluation_type(LuaCEmbed *self, char *code, ...);


long LuaCEmbed_get_evaluation_table_size(LuaCEmbed *self, char *code, ...);

long LuaCEmbed_get_evaluation_long(LuaCEmbed *self, char *code, ...);

double LuaCEmbed_get_evaluation_double(LuaCEmbed *self, char *code, ...);

bool LuaCEmbed_get_evaluation_bool(LuaCEmbed *self, char *code, ...);


