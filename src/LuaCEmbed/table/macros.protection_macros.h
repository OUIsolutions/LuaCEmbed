//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dep_declare.h"
//silver_chain_scope_end

#define PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID \
    if(!self){                          \
    return;                              \
    }

#define PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM \
    if(!self){                          \
    return LUA_CEMBED_GENERIC_ERROR;      \
    }

#define PRIVATE_LUA_CEMBED_TABLE_PROTECT_BOOL \
    if(!self){                          \
    return false;      \
    }

#define PRIVATE_LUA_CEMBED_TABLE_PROTECT_NULL \
    if(!self){                          \
    return NULL;      \
    }
