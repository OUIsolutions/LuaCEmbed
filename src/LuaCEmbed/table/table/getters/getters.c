



int privateLuaCEmbedTable_ensure_type(LuaCEmbedTable *self,const char *name, int expected_type){
    int type = lua_type(self->main_object->state,-1);
    if(type == expected_type){
        return  LUA_CEMBED_OK;
    }
    privateLuaCEmbed_raise_error_not_jumping(
            self->main_object,
            PRIVATE_LUA_CEMBED_WRONG_TYPE_PROPETY,
            name,
            self->global_buffer,
            LuaCembed_convert_arg_code(type),
            LuaCembed_convert_arg_code(expected_type)
    );
    return LUA_CEMBED_GENERIC_ERROR;
}




int  LuaCEmbedTable_get_type_prop(LuaCEmbedTable *self, const char *name){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_getfield(self->main_object->state,-1,name);
    return lua_type(self->main_object->state,-1);
}

char*  LuaCembedTable_get_string_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_getfield(self->main_object->state,-1,name);
    if(privateLuaCEmbedTable_ensure_type(self,name,LUA_CEMBED_STRING)){
        return NULL;
    }
    return (char*)lua_tostring(self->main_object->state,-1);
}


long  LuaCembedTable_get_long_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_getfield(self->main_object->state,-1,name);
    if(privateLuaCEmbedTable_ensure_type(self,name,LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (long )lua_tonumber(self->main_object->state,-1);
}

double  LuaCembedTable_get_double_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_getfield(self->main_object->state,-1,name);
    if(privateLuaCEmbedTable_ensure_type(self,name,LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (double )lua_tonumber(self->main_object->state,-1);
}

bool  LuaCembedTable_get_bool_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_getfield(self->main_object->state,-1,name);
    if(privateLuaCEmbedTable_ensure_type(self,name,LUA_CEMBED_BOOL)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return lua_toboolean(self->main_object->state,-1);
}

long  LuaCEmbedTable_get_size(LuaCEmbedTable *self){
    lua_getglobal(self->main_object->state,self->global_buffer);
    long total = 0;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,1)){
        total+=1;

        lua_pop(self->main_object->state,1);
    }
    return total;
}

int LuaCEmbedTable_get_type_by_index(LuaCEmbedTable *self, int index){
    lua_getglobal(self->main_object->state,self->global_buffer);

    int total = 0;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,1)){
        total+=1;
        lua_pop(self->main_object->state,1);
    }

    printf("total:%d\n",total);
    return -1;
}
