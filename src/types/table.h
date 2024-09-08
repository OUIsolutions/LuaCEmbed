#include "luacembed.h"
#ifndef PRIVATE_LUACEMBED_TABLE
#define PRIVATE_LUACEMBED_TABLE
typedef struct {
    LuaCEmbed  *main_object;
    char *prop_name;
    char  *global_name;
    void *sub_tables;
    long index;

}LuaCEmbedTable;
#endif
