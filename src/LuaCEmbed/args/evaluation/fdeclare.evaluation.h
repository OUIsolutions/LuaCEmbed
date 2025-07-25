//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.consts.h"
//silver_chain_scope_end



lua_Integer private_LuaCembed_run_code_with_args(LuaCEmbed *self,lua_Integer index,const char *code,va_list args);

lua_Integer privateLuaCembed_ensure_arg_evaluation_type(LuaCEmbed *self,lua_Integer index,lua_Integer expected_type);

lua_Integer LuaCEmbed_get_type_clojure_evalation(LuaCEmbed *self,lua_Integer index,const char *code,...);

lua_Integer LuaCEmbed_generate_arg_clojure_evalation(LuaCEmbed *self,lua_Integer index,const char *code,...);

lua_Integer LuaCEmbed_get_long_arg_clojure_evalation(LuaCEmbed *self,lua_Integer index,const char *code,...);


double LuaCEmbed_get_double_arg_clojure_evalation(LuaCEmbed *self,lua_Integer index,const char *code,...);

bool LuaCEmbed_get_bool_arg_clojure_evalation(LuaCEmbed *self,lua_Integer index,const char *code,...);

char* LuaCEmbed_get_string_arg_clojure_evalation(LuaCEmbed *self,lua_Integer index,const char *code,...);
