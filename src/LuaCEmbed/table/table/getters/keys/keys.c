
int  LuaCEmbedTable_get_type_prop(LuaCEmbedTable *self, const char *name){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM
    lua_settop(self->main_object->state,0);

    private_lua_cembed_memory_limit = self->main_object->memory_limit;

    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state, name);    // Empilha a chave "nome"
    lua_gettable(self->main_object->state, -2);
    int value =  lua_type(self->main_object->state,-1);
    PRIVATE_LUA_CEMBED_CLEAR_STACK
    return value;
}

char*  LuaCembedTable_get_string_prop(LuaCEmbedTable *self , const char *name){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NULL
    lua_settop(self->main_object->state,0);

    private_lua_cembed_memory_limit = self->main_object->memory_limit;


    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state, name);
    lua_gettable(self->main_object->state, -2);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_STRING)){
        return NULL;
    }

    char *value = (char*)lua_tostring(self->main_object->state,-1);
    PRIVATE_LUA_CEMBED_CLEAR_STACK
    return value;
}


long long   LuaCembedTable_get_long_prop(LuaCEmbedTable *self , const char *name){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM
    lua_settop(self->main_object->state,0);

    private_lua_cembed_memory_limit = self->main_object->memory_limit;
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state, name);
    lua_gettable(self->main_object->state, -2);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    long long value = (long long)lua_tonumber(self->main_object->state,-1);
    PRIVATE_LUA_CEMBED_CLEAR_STACK
    return value;
}

double  LuaCembedTable_get_double_prop(LuaCEmbedTable *self , const char *name){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM
    lua_settop(self->main_object->state,0);

    private_lua_cembed_memory_limit = self->main_object->memory_limit;


    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state, name);
    lua_gettable(self->main_object->state, -2);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    double value  = (double )lua_tonumber(self->main_object->state,-1);
    PRIVATE_LUA_CEMBED_CLEAR_STACK
    return value;
}

bool  LuaCembedTable_get_bool_prop(LuaCEmbedTable *self , const char *name){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_BOOL
    lua_settop(self->main_object->state,0);

    private_lua_cembed_memory_limit = self->main_object->memory_limit;


    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state, name);
    lua_gettable(self->main_object->state, -2);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_BOOL)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    bool value =  lua_toboolean(self->main_object->state,-1);
    PRIVATE_LUA_CEMBED_CLEAR_STACK
    return value;
}
