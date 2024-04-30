

int LuaCEmbed_get_global_type(LuaCEmbed *self,const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_NUM
    private_lua_cembed_memory_limit = self->memory_limit;

    lua_getglobal(self->state, name);
    return lua_type(self->state,-1);
}

long LuaCEmbed_get_global_long(LuaCEmbed *self,const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_NUM
    private_lua_cembed_memory_limit = self->memory_limit;

    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_NUMBER)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    lua_getglobal(self->state, name);
    return (long )lua_tonumber(self->state,-1);
}

double LuaCEmbed_get_global_double(LuaCEmbed *self,const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_NUM
    private_lua_cembed_memory_limit = self->memory_limit;

    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_NUMBER)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    lua_getglobal(self->state, name);
    return (double )lua_tonumber(self->state,-1);
}

bool LuaCEmbed_get_global_bool(LuaCEmbed *self,const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_BOOL
    private_lua_cembed_memory_limit = self->memory_limit;

    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_BOOL)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    lua_getglobal(self->state, name);
    return lua_toboolean(self->state,-1);
}


char * LuaCEmbed_get_global_string(LuaCEmbed *self,const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_NULL
    private_lua_cembed_memory_limit = self->memory_limit;

    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_STRING)){
        return  NULL;
    }
    lua_getglobal(self->state, name);
    return (char*)lua_tostring(self->state,-1);
}

LuaCEmbedTable * LuaCembed_new_anonymous_table(LuaCEmbed *self){
    PRIVATE_LUA_CEMBED_PROTECT_NULL
    private_lua_cembed_memory_limit = self->memory_limit;

    privateLuaCEmbedTableArray *target = (privateLuaCEmbedTableArray*)privateLuaCEmbed_get_current_table_array(self);

    char *buffer= private_LuaCembed_format(PRIVATE_LUA_CEMBED_ANONYMOUS_TABLE, target->size);
    LuaCEmbedTable  *created_table =LuaCembed_new_global_table(self,buffer);
    free(buffer);
    return created_table;
}



LuaCEmbedTable * LuaCembed_get_global_table(LuaCEmbed *self, const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_NULL
    private_lua_cembed_memory_limit = self->memory_limit;

    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_TABLE)){
        return  NULL;
    }

    privateLuaCEmbedTableArray *target = (privateLuaCEmbedTableArray*)privateLuaCEmbed_get_current_table_array(self);

    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_global_name(target,name);
    if(possible){
        return possible;
    }

    LuaCEmbedTable  *creaeted = private_newLuaCembedTable(self, "%s", name);

    privateLuaCEmbedTableArray_append(
            target,
            creaeted
    );
    return creaeted;
}

LuaCEmbedTable * LuaCembed_new_global_table(LuaCEmbed *self, const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_NULL
    private_lua_cembed_memory_limit = self->memory_limit;

    lua_newtable(self->state);
    lua_setglobal(self->state,name);
    privateLuaCEmbedTableArray *target = (privateLuaCEmbedTableArray*)privateLuaCEmbed_get_current_table_array(self);

    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_global_name(target,name);
    if(possible){
        return possible;
    }

    LuaCEmbedTable  *creaeted = private_newLuaCembedTable(self, "%s", name);

    privateLuaCEmbedTableArray_append(
            target,
            creaeted
    );
    return creaeted;
}
