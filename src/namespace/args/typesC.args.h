//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesB.h"
//silver_chain_scope_end


typedef struct {


    lua_Integer  (*size)(LuaCEmbed *self);
    lua_Integer  (*get_type)(LuaCEmbed *self,lua_Integer index);
   lua_Integer (*get_long)(LuaCEmbed *self, lua_Integer index);
    double (*get_double)(LuaCEmbed *self, lua_Integer index);
    bool (*get_bool)(LuaCEmbed *self, lua_Integer index);
    char * (*get_raw_str)(LuaCEmbed *self, lua_Integer *size, lua_Integer index);
    char * (*get_str)(LuaCEmbed *self, lua_Integer index);
    LuaCEmbedTable  * (*get_table)(LuaCEmbed *self,lua_Integer index);
    lua_Integer  (*generate_arg_clojure_evalation)(LuaCEmbed *self,lua_Integer index,const char *code,...);
    lua_Integer  (*get_type_clojure_evalation)(LuaCEmbed *self,lua_Integer index,const char *code,...);
    lua_Integer  (*get_long_arg_clojure_evalation)(LuaCEmbed *self,lua_Integer index,const char *code,...);
    double (*get_double_arg_clojure_evalation)(LuaCEmbed *self,lua_Integer index,const char *code,...);
    bool (*get_bool_arg_clojure_evalation)(LuaCEmbed *self,lua_Integer index,const char *code,...);
    char* (*get_string_arg_clojure_evalation)(LuaCEmbed *self,lua_Integer index,const char *code,...);
    LuaCEmbedTable* (*run_lambda)(LuaCEmbed *self, lua_Integer index, LuaCEmbedTable *args_to_call,lua_Integer total_returns);




} LuaCembedArgsModule;
