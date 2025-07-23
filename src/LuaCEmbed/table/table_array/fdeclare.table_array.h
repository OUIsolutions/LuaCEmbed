//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.consts.h"
//silver_chain_scope_end



typedef struct {

    LuaCEmbedTable **tables;
    long size;

}privateLuaCEmbedTableArray;

privateLuaCEmbedTableArray *newprivateLuaCEmbedTableArray();

void privateLuaCEmbedTableArray_append(privateLuaCEmbedTableArray *self,LuaCEmbedTable *element);

LuaCEmbedTable  *privateLuaCEmbedTableArray_find_by_global_name(privateLuaCEmbedTableArray *self, const char *name);

LuaCEmbedTable  *privateLuaCEmbedTableArray_find_by_prop_name(privateLuaCEmbedTableArray *self, const char *name);

LuaCEmbedTable  *privateLuaCEmbedTableArray_find_by_internal_index(privateLuaCEmbedTableArray *self, lua_Integer internal_index);

void  privateLuaCEmbedTableArray_free(privateLuaCEmbedTableArray *self);
