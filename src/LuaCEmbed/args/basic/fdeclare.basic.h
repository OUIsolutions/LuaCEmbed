
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.typesD.h"
//silver_chain_scope_end

lua_Integer privateLuaCEmbed_put_arg_on_top(LuaCEmbed *self, lua_Integer index);

lua_Integer  LuaCEmbed_get_total_args(LuaCEmbed *self);

lua_Integer  LuaCEmbed_get_arg_type(LuaCEmbed *self,lua_Integer index);



lua_Integer LuaCEmbed_get_long_arg(LuaCEmbed *self, lua_Integer index);

double LuaCEmbed_get_double_arg(LuaCEmbed *self, lua_Integer index);

bool LuaCEmbed_get_bool_arg(LuaCEmbed *self, lua_Integer index);

char * LuaCEmbed_get_str_arg(LuaCEmbed *self, lua_Integer index);

char * LuaCEmbed_get_raw_str_arg(LuaCEmbed *self,lua_Integer *size, lua_Integer index);

LuaCEmbedTable  * LuaCEmbed_get_arg_table(LuaCEmbed *self,lua_Integer index);

LuaCEmbedTable* LuaCEmbed_run_args_lambda(LuaCEmbed *self, lua_Integer index, LuaCEmbedTable *args_to_call, lua_Integer total_returns);
