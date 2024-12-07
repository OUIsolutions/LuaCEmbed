
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.macros.h"
//silver_chain_scope_end

typedef struct {

    int type;
    double num_val;
    bool its_string_ref;
    lua_Integer string_size;
    char *string_val;

}LuaCEmbedResponse;
