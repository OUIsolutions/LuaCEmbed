

int private_LuaCembed_run_code_with_args(LuaCEmbed *self,int index,char *code,va_list args);

int privateLuaCembed_ensure_arg_evaluation_type(LuaCEmbed *self,int index,int expected_type);

long LuaCEmbed_get_type_clojure_evalation(LuaCEmbed *self,int index,char *code,...);

long LuaCEmbed_get_long_arg_clojure_evalation(LuaCEmbed *self,int index,char *code,...);


double LuaCEmbed_get_double_arg_clojure_evalation(LuaCEmbed *self,int index,char *code,...);

bool LuaCEmbed_get_bool_arg_clojure_evalation(LuaCEmbed *self,int index,char *code,...);

char* LuaCEmbed_get_string_arg_clojure_evalation(LuaCEmbed *self,int index,char *code,...);

