#include "table.h"


#ifndef PRIVATE_LUACEMBED_TABLE_ARRAY
#define PRIVATE_LUACEMBED_TABLE_ARRAY
typedef struct {

    LuaCEmbedTable **tables;
    long size;

}privateLuaCEmbedTableArray;
#endif
