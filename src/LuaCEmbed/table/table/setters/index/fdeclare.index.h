
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../../../imports/imports.typesD.h"
//silver_chain_scope_end

void  LuaCEmbedTable_set_string_by_index(LuaCEmbedTable *self, long index, const char *value);

void  LuaCEmbedTable_set_raw_string_by_index(LuaCEmbedTable *self, long index, const char *value,long size);

void  LuaCEmbedTable_set_long_by_index(LuaCEmbedTable *self, long long  index, long  value);

void  LuaCEmbedTable_set_double_by_index(LuaCEmbedTable *self, long index, double  value);

void  LuaCEmbedTable_set_bool_by_index(LuaCEmbedTable *self, long index, bool value);


void  LuaCEmbedTable_set_evaluation_by_index(LuaCEmbedTable *self, long index, const char *code, ...);
