
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../../../imports/imports.macros.h"
//silver_chain_scope_end


char *LuaCembedTable_get_key_by_index(LuaCEmbedTable *self, lua_Integer index);

bool LuaCembedTable_has_key_at_index(LuaCEmbedTable *self, lua_Integer index);

lua_Integer  LuaCEmbedTable_get_full_size(LuaCEmbedTable *self);

lua_Integer  LuaCEmbedTable_get_listable_size(LuaCEmbedTable *self);


lua_Integer  privateLuaCEmbedTable_convert_index(LuaCEmbedTable *self, private_lua_cembed_incremented_arg index);

int LuaCEmbedTable_get_type_by_index(LuaCEmbedTable *self, lua_Integer index);

lua_Integer LuaCEmbedTable_get_long_by_index(LuaCEmbedTable *self, lua_Integer index);

double LuaCEmbedTable_get_double_by_index(LuaCEmbedTable *self, lua_Integer index);

char * LuaCEmbedTable_get_string_by_index(LuaCEmbedTable *self, lua_Integer index);

char * LuaCEmbedTable_get_raw_string_by_index(LuaCEmbedTable *self, lua_Integer index, lua_Integer *size);

bool LuaCEmbedTable_get_bool_by_index(LuaCEmbedTable *self, lua_Integer index);
