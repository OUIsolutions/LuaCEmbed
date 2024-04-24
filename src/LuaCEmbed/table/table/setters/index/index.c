

void  LuaCEmbedTable_set_string_by_index(LuaCEmbedTable *self, long index, const char *value){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushnumber(self->main_object->state,(double)index);
    lua_pushstring(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
}

void  LuaCEmbedTable_set_long_by_index(LuaCEmbedTable *self, long index, long  value){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushnumber(self->main_object->state,(double)index);
    lua_pushnumber(self->main_object->state,(double )value);
    lua_settable(self->main_object->state,-3);
}

void  LuaCEmbedTable_set_double_by_index(LuaCEmbedTable *self, long index, double  value){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushnumber(self->main_object->state,(double)index);
    lua_pushnumber(self->main_object->state,(double )value);
    lua_settable(self->main_object->state,-3);
}

void  LuaCEmbedTable_set_bool_by_index(LuaCEmbedTable *self, long index, bool value){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushnumber(self->main_object->state,(double)index);
    lua_pushboolean(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
}


void  LuaCEmbedTable_set_evaluation_by_index(LuaCEmbedTable *self, long index, const char *code, ...){

    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    va_list  args;
    va_start(args,code);
    vsnprintf(buffer,sizeof(buffer),code,args);
    va_end(args);

    LuaCEmbed_evaluate_string_no_return(self->main_object,
                                        PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
                                        PRIVATE_LUA_CEMBED_EVALUATION_NAME,
                                        buffer
    );
    if(LuaCEmbed_has_errors(self->main_object)){
        return;
    }
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushnumber(self->main_object->state,(double)index);
    lua_getglobal(self->main_object->state,PRIVATE_LUA_CEMBED_EVALUATION_NAME);
    lua_settable(self->main_object->state,-3);
}
