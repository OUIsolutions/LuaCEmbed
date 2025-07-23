//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../../../imports/imports.consts.h"
//silver_chain_scope_end






void LuaCEmbedTable_set_method(LuaCEmbedTable *self, const char *name, LuaCEmbedResponse *(*callback)(LuaCEmbedTable  *self, LuaCEmbed *args));

void  LuaCEmbedTable_set_string_prop(LuaCEmbedTable *self, const char *name, const char *value);

void  LuaCEmbedTable_set_raw_string_prop(LuaCEmbedTable *self , const char *name, const char *value,lua_Integer size);

void  LuaCEmbedTable_set_long_prop(LuaCEmbedTable *self, const char *name,lua_Integer   value);

void  LuaCEmbedTable_set_double_prop(LuaCEmbedTable *self, const char *name, double  value);

void  LuaCEmbedTable_set_bool_prop(LuaCEmbedTable *self, const char *name, bool value);


void  LuaCEmbedTable_set_evaluation_prop(LuaCEmbedTable *self, const char *name, const char *code, ...);

void LuaCEmbedTable_copy_prop_to_global_var(LuaCEmbedTable *self,const char *prop,const char *name);

void LuaCEmbedTable_set_table_prop_with_table_prop(LuaCEmbedTable *self, const char *self_prop, LuaCEmbedTable *table,const char * table_prop );

void LuaCEmbedTable_set_table_prop_with_table_index(LuaCEmbedTable *self, const char *self_prop, LuaCEmbedTable *table,const char * table_index );

void LuaCEmbedTable_set_table_prop_with_global(LuaCEmbedTable *self, const char *self_prop, const char *global_name);