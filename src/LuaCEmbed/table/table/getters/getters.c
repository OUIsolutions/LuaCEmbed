



int  LuaCEmbedTable_get_type_prop(LuaCEmbedTable *self, const char *name){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_getfield(self->main_object->state,-1,name);
    return lua_type(self->main_object->state,-1);
}

char*  LuaCembedTable_get_string_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_getfield(self->main_object->state,-1,name);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_STRING)){
        return NULL;
    }
    return (char*)lua_tostring(self->main_object->state,-1);
}


long  LuaCembedTable_get_long_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_getfield(self->main_object->state,-1,name);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (long )lua_tonumber(self->main_object->state,-1);
}

double  LuaCembedTable_get_double_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_getfield(self->main_object->state,-1,name);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (double )lua_tonumber(self->main_object->state,-1);
}

bool  LuaCembedTable_get_bool_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_getfield(self->main_object->state,-1,name);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_BOOL)){
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
long  privateLuaCEmbedTable_convert_index(LuaCEmbedTable *self,long index){
    if(index >= 0){
        return  index;
    }

    return LuaCEmbedTable_get_size(self) + index;
}

int LuaCEmbedTable_get_type_by_index(LuaCEmbedTable *self, int index){
    lua_getglobal(self->main_object->state,self->global_buffer);
    long converted_index = privateLuaCEmbedTable_convert_index(self,index);
    int total = 0;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,1)){
        total+=1;
        if(total == converted_index){
            int type = lua_type(self->main_object->state,-1);
            lua_pop(self->main_object->state,1);
            return type;
        }
        lua_pop(self->main_object->state,1);
    }
    return LUA_CEMBED_NOT_FOUND;
}
char *LuaCembedTable_get_key_by_index(LuaCEmbedTable *self, long index){
    lua_getglobal(self->main_object->state,self->global_buffer);
    long converted_index = privateLuaCEmbedTable_convert_index(self,index);
    int total = 0;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,1)){
        if(total == converted_index){
            if(lua_type(self->main_object->state,-2) != LUA_CEMBED_STRING ){
                privateLuaCEmbed_raise_error_not_jumping(
                        self->main_object,
                        PRIVATE_LUA_CEMBED_ELEMENT_DOES_NOT_HAVE_KEY,
                        index,
                        self->global_buffer
                );
                lua_pop(self->main_object->state,1);
                return NULL;
            }
            char* result = (char*)lua_tostring(self->main_object->state,-2);
            lua_pop(self->main_object->state,1);
            return result;
        }

        lua_pop(self->main_object->state,1);
        total+=1;

    }

    privateLuaCEmbed_raise_error_not_jumping(
            self->main_object,
            PRIVATE_LUA_CEMBED_ELEMENT_DOES_NOT_HAVE_KEY,
            index,
            self->global_buffer
    );
    return NULL;
}
bool LuaCembedTable_has_key_at_index(LuaCEmbedTable *self, long index){
    lua_getglobal(self->main_object->state,self->global_buffer);
    long converted_index = privateLuaCEmbedTable_convert_index(self,index);
    int total = 0;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,1)){
        if(total == converted_index){
            if(lua_type(self->main_object->state,-2) != LUA_CEMBED_STRING ){
                return false;
            }
            return true;
        }

        lua_pop(self->main_object->state,1);
        total+=1;

    }

    return false;
}

long LuaCEmbedTable_get_long_by_index(LuaCEmbedTable *self, int index){
    lua_getglobal(self->main_object->state,self->global_buffer);
    long converted_index = privateLuaCEmbedTable_convert_index(self,index);
    int total = 0;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,1)){
        if(total == converted_index){
            if(privateLuaCEmbedTable_ensure_type_with_index(self,index,LUA_CEMBED_NUMBER)){
                lua_pop(self->main_object->state,1);
                return LUA_CEMBED_GENERIC_ERROR;
            }
            long result = (long)lua_tonumber(self->main_object->state,-1);
            lua_pop(self->main_object->state,1);
            return result;
        }
        lua_pop(self->main_object->state,1);
        total+=1;

    }

    privateLuaCEmbed_raise_error_not_jumping(
            self->main_object,
            PRIVATE_LUA_CEMBED_WRONG_TYPE_INDEX,
            index,
            self->global_buffer,
            LuaCembed_convert_arg_code(LUA_CEMBED_NIL),
            LuaCembed_convert_arg_code(LUA_CEMBED_NUMBER)
    );
    return LUA_CEMBED_GENERIC_ERROR;
}

double LuaCEmbedTable_get_double_by_index(LuaCEmbedTable *self, int index){
    lua_getglobal(self->main_object->state,self->global_buffer);
    long converted_index = privateLuaCEmbedTable_convert_index(self,index);
    int total = 0;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,1)){
        if(total == converted_index){
            if(privateLuaCEmbedTable_ensure_type_with_index(self,index,LUA_CEMBED_NUMBER)){
                lua_pop(self->main_object->state,1);
                return LUA_CEMBED_GENERIC_ERROR;
            }
            double result = (double )lua_tonumber(self->main_object->state,-1);
            lua_pop(self->main_object->state,1);
            return result;
        }
        lua_pop(self->main_object->state,1);
        total+=1;

    }

    privateLuaCEmbed_raise_error_not_jumping(
            self->main_object,
            PRIVATE_LUA_CEMBED_WRONG_TYPE_INDEX,
            index,
            self->global_buffer,
            LuaCembed_convert_arg_code(LUA_CEMBED_NIL),
            LuaCembed_convert_arg_code(LUA_CEMBED_NUMBER)
    );
    return LUA_CEMBED_GENERIC_ERROR;
}

char * LuaCEmbedTable_get_string_by_index(LuaCEmbedTable *self, int index){
    lua_getglobal(self->main_object->state,self->global_buffer);
    int converted_index = privateLuaCEmbedTable_convert_index(self,index);
    int total = 0;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,1)){
        if(total == converted_index){
            if(privateLuaCEmbedTable_ensure_type_with_index(self,index,LUA_CEMBED_STRING)){
                lua_pop(self->main_object->state,1);
                return NULL;
            }
            char * result = (char*)lua_tostring(self->main_object->state,-1);
            lua_pop(self->main_object->state,1);
            return result;
        }
        lua_pop(self->main_object->state,1);
        total+=1;

    }

    privateLuaCEmbed_raise_error_not_jumping(
            self->main_object,
            PRIVATE_LUA_CEMBED_WRONG_TYPE_INDEX,
            index,
            self->global_buffer,
            LuaCembed_convert_arg_code(LUA_CEMBED_NIL),
            LuaCembed_convert_arg_code(LUA_CEMBED_STRING)
    );
    return NULL;
}

bool LuaCEmbedTable_get_bool_by_index(LuaCEmbedTable *self, int index){
    lua_getglobal(self->main_object->state,self->global_buffer);
    long converted_index = privateLuaCEmbedTable_convert_index(self,index);
    int total = 0;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,1)){
        if(total == converted_index){
            if(privateLuaCEmbedTable_ensure_type_with_index(self,index,LUA_CEMBED_BOOL)){
                lua_pop(self->main_object->state,1);
                return LUA_CEMBED_GENERIC_ERROR;
            }
            bool result = lua_toboolean(self->main_object->state,-1);
            lua_pop(self->main_object->state,1);
            return result;
        }
        lua_pop(self->main_object->state,1);
        total+=1;

    }

    privateLuaCEmbed_raise_error_not_jumping(
            self->main_object,
            PRIVATE_LUA_CEMBED_WRONG_TYPE_INDEX,
            index,
            self->global_buffer,
            LuaCembed_convert_arg_code(LUA_CEMBED_NIL),
            LuaCembed_convert_arg_code(LUA_CEMBED_BOOL)
    );
    return LUA_CEMBED_GENERIC_ERROR;
}