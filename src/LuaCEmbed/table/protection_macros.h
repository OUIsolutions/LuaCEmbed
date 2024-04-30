#define PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID \
    if(!self){                          \
    return;                              \
    }                                     \
    if(LuaCEmbed_has_errors(self->main_object)){     \
        return;                         \
    }

#define PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM \
    if(!self){                          \
    return LUA_CEMBED_GENERIC_ERROR;      \
    }                                     \
    if(LuaCEmbed_has_errors(self->main_object)){     \
        return LUA_CEMBED_GENERIC_ERROR; \
    }

#define PRIVATE_LUA_CEMBED_TABLE_PROTECT_BOOL \
    if(!self){                          \
    return false;      \
    }                                     \
    if(LuaCEmbed_has_errors(self->main_object)){     \
        return false; \
    }


#define PRIVATE_LUA_CEMBED_TABLE_PROTECT_NULL \
    if(!self){                          \
    return NULL;      \
    }                                     \
    if(LuaCEmbed_has_errors(self->main_object)){     \
        return NULL; \
    }

