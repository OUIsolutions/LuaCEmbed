#include "../unique.declaration_requirements.h"



privateLuaCEmbedTableArray *newprivateLuaCEmbedTableArray();

void privateLuaCEmbedTableArray_append(privateLuaCEmbedTableArray *self,LuaCEmbedTable *element);

LuaCEmbedTable  *privateLuaCEmbedTableArray_find_by_global_name(privateLuaCEmbedTableArray *self, const char *name);

LuaCEmbedTable  *privateLuaCEmbedTableArray_find_by_prop_name(privateLuaCEmbedTableArray *self, const char *name);

LuaCEmbedTable  *privateLuaCEmbedTableArray_find_by_internal_index(privateLuaCEmbedTableArray *self, long internal_index);

void  privateLuaCEmbedTableArray_free(privateLuaCEmbedTableArray *self);
