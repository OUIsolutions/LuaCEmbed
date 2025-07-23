//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.types.h"
//silver_chain_scope_end



typedef struct {
    LuaCEmbed  *main_object;
    char *prop_name;
    char  *global_name;
    void *sub_tables;
    long index;

}LuaCEmbedTable;
