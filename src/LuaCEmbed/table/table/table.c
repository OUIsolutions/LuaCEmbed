

LuaCEmbedTable * newLuaCembedTable(LuaCEmbed *main_embed, const char *format, ...){
    LuaCEmbedTable  *self = (LuaCEmbedTable*)malloc(sizeof (LuaCEmbedTable));
    *self = (LuaCEmbedTable){0};
    self->main_object =main_embed;
    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    va_list  args;
    va_start(args,format);
    vsnprintf(buffer,sizeof(buffer),format,args);
    va_end(args);
    self->global_buffer = strdup(buffer);
    return self;
}


void LuaCEmbedTable_set_method(LuaCEmbedTable *self , const char *name, LuaCEmbedResponse *(*callback)(LuaCEmbedTable  *self, LuaCEmbed *args)){

    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);

    //creating the clojure
    lua_pushlightuserdata(self->main_object->state,(void*)true);//is a method
    lua_pushlightuserdata(self->main_object->state,(void*)self->main_object); //self
    lua_pushlightuserdata(self->main_object->state,(void*)name);//calback name
    lua_pushlightuserdata(self->main_object->state,(void*)self);//table
    lua_pushlightuserdata(self->main_object->state,(void*)callback);

    //add these clojure to be handled by the callbacks
    lua_pushcclosure(self->main_object->state,privateLuaCEmbed_main_callback_handler,5);
    lua_settable(self->main_object->state,-3);
}

void  LuaCEmbedTable_set_string_prop(LuaCEmbedTable *self , const char *name, const char *value){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);
    lua_pushstring(self->main_object->state,value);

    lua_settable(self->main_object->state,-3);
}

void  LuaCEmbedTable_set_long_prop(LuaCEmbedTable *self , const char *name, long  value){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);
    lua_pushnumber(self->main_object->state,(double)value);
    lua_settable(self->main_object->state,-3);
}

void  LuaCEmbedTable_set_double_prop(LuaCEmbedTable *self , const char *name, double  value){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);
    lua_pushnumber(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
}

void  LuaCEmbedTable_set_bool_prop(LuaCEmbedTable *self , const char *name, bool value){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);
    lua_pushboolean(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
}



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
    if(!privateLuaCEmbedTable_ensure_type(self,name,LUA_CEMBED_STRING)){
        return NULL;
    }
    return (char*)lua_tostring(self->main_object->state,-1);
}


long  LuaCembedTable_get_long_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_getfield(self->main_object->state,-1,name);
    if(!privateLuaCEmbedTable_ensure_type(self,name,LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (long )lua_tonumber(self->main_object->state,-1);
}

double  LuaCembedTable_get_double_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_getfield(self->main_object->state,-1,name);
    if(!privateLuaCEmbedTable_ensure_type(self,name,LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (double )lua_tonumber(self->main_object->state,-1);
}

bool  LuaCembedTable_get_bool_prop(LuaCEmbedTable *self , const char *name){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_getfield(self->main_object->state,-1,name);
    if(!privateLuaCEmbedTable_ensure_type(self,name,LUA_CEMBED_BOOL)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return lua_toboolean(self->main_object->state,-1);
}


