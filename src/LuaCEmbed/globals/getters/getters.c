

int LuaCEmbed_get_global_type(LuaCEmbed *self,const char *name){
    lua_getglobal(self->state, name);
    return lua_type(self->state,-1);
}

long LuaCEmbed_get_global_long(LuaCEmbed *self,const char *name){
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_NUMBER)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    lua_getglobal(self->state, name);
    return (long )lua_tonumber(self->state,-1);
}

double LuaCEmbed_get_global_double(LuaCEmbed *self,const char *name){
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_NUMBER)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    lua_getglobal(self->state, name);
    return (double )lua_tonumber(self->state,-1);
}

bool LuaCEmbed_get_global_bool(LuaCEmbed *self,const char *name){
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_BOOL)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    lua_getglobal(self->state, name);
    return lua_toboolean(self->state,-1);
}


char * LuaCEmbed_get_global_string(LuaCEmbed *self,const char *name){
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_STRING)){
        return  NULL;
    }
    lua_getglobal(self->state, name);
    return (char*)lua_tostring(self->state,-1);
}

LuaCEmbedTable * LuaCembed_new_anonymous_table(LuaCEmbed *self){

    privateLuaCEmbedTableArray *target = (privateLuaCEmbedTableArray*)self->global_tables;

    if(self->current_function){
        target =  (privateLuaCEmbedTableArray*)self->func_tables;
    }
    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};

    sprintf(buffer,PRIVATE_LUA_CEMBED_ANONYMOUS_TABLE,target->size);

    lua_newtable(self->state);
    lua_setglobal(self->state,buffer);
    return (LuaCEmbedTable*)private_LuaCembed_get_table_or_create_internal(self,buffer);
}


LuaCEmbedTable * LuaCembed_get_global_table_auto_creating(LuaCEmbed *self, const char *name){
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_TABLE)){
        return  LuaCembed_new_global_table(self,name);
    }
    return (LuaCEmbedTable*)private_LuaCembed_get_table_or_create_internal(self,name);
}

LuaCEmbedTable * LuaCembed_new_global_table(LuaCEmbed *self, const char *name){


    lua_newtable(self->state);
    lua_setglobal(self->state,name);

    return (LuaCEmbedTable*)private_LuaCembed_get_table_or_create_internal(self,name);
}
