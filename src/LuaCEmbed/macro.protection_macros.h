
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.consts.h"
//silver_chain_scope_end
#define PRIVATE_LUA_CEMBED_PROTECT_VOID \
    if(!self){                          \
    return;                              \
    }


#define PRIVATE_LUA_CEMBED_PROTECT_NUM \
    if(!self){                          \
    return LUA_CEMBED_GENERIC_ERROR;      \
    }

#define PRIVATE_LUA_CEMBED_PROTECT_BOOL \
    if(!self){                          \
    return false;      \
    }

#define PRIVATE_LUA_CEMBED_PROTECT_NULL \
    if(!self){                          \
    return NULL;      \
    }

#define PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK     if(lua_gettop(self->main_object->state)){lua_settop(self->main_object->state,0);}

#define PRIVATE_LUA_CEMBED_CLEAR_STACK     if(lua_gettop(self->state)){lua_settop(self->state,0);}
