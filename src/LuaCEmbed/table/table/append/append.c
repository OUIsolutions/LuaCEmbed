void  LuaCEmbedTable_append_table(LuaCEmbedTable *self, LuaCEmbedTable *table){
    if(!self){
        return ;
    }
    long size = LuaCEmbedTable_get_listable_size(self);
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,size+1);
    lua_getglobal(self->main_object->state,table->global_name);
    lua_rawset(self->main_object->state,-3);
}

void  LuaCEmbedTable_append_string(LuaCEmbedTable *self,  const char *value){
    if(!self){
        return ;
    }
    long size = LuaCEmbedTable_get_listable_size(self);
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,size+1);
    lua_pushstring(self->main_object->state,value);
    lua_rawset(self->main_object->state,-3);
}

void  LuaCEmbedTable_append_long(LuaCEmbedTable *self,  long  value){
    if(!self){
        return ;
    }
    long size = LuaCEmbedTable_get_listable_size(self);
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,size+1);
    lua_pushnumber(self->main_object->state,(double)value);
    lua_rawset(self->main_object->state,-3);
}

void  LuaCEmbedTable_append_double(LuaCEmbedTable *self, double  value){
    if(!self){
        return ;
    }
    long size = LuaCEmbedTable_get_listable_size(self);
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,size+1);
    lua_pushnumber(self->main_object->state,value);
    lua_rawset(self->main_object->state,-3);
}

void  LuaCEmbedTable_append_bool(LuaCEmbedTable *self,  bool value){
    if(!self){
        return ;
    }
    long size = LuaCEmbedTable_get_listable_size(self);
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,size+1);
    lua_pushboolean(self->main_object->state,value);
    lua_rawset(self->main_object->state,-3);
}

void  LuaCEmbedTable_append_evaluation(LuaCEmbedTable *self, const char *code, ...){
    if(!self){
        return ;
    }
    va_list  args;
    va_start(args,code);
     char *buffer = private_LuaCembed_format_vaarg(code,args);
    va_end(args);

    LuaCEmbed_evaluate_string_no_return(
            self->main_object,
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_EVALUATION_NAME,
            buffer
    );
    free(buffer);
    if(LuaCEmbed_has_errors(self->main_object)){
        return;
    }
    long size = LuaCEmbedTable_get_listable_size(self);
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,size+1);
    lua_getglobal(self->main_object->state,PRIVATE_LUA_CEMBED_EVALUATION_NAME);
    lua_rawset(self->main_object->state,-3);
}