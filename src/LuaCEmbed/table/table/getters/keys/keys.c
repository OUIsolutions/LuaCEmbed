
int  LuaCEmbedTable_get_type_prop(LuaCEmbedTable *self, const char *name){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_getfield(self->main_object->state,-1,name);
    return lua_type(self->main_object->state,-1);
}

char*  LuaCembedTable_get_string_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_getfield(self->main_object->state,-1,name);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_STRING)){
        return NULL;
    }
    return (char*)lua_tostring(self->main_object->state,-1);
}


long  LuaCembedTable_get_long_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_getfield(self->main_object->state,-1,name);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (long )lua_tonumber(self->main_object->state,-1);
}

double  LuaCembedTable_get_double_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_getfield(self->main_object->state,-1,name);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (double )lua_tonumber(self->main_object->state,-1);
}

bool  LuaCembedTable_get_bool_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_getfield(self->main_object->state,-1,name);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_BOOL)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return lua_toboolean(self->main_object->state,-1);
}
