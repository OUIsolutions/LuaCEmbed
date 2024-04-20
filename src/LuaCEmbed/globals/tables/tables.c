
long LuaCEmbed_get_global_table_long(LuaCEmbed *self,const char *name,const char *format, ...){
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_TABLE)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    lua_getglobal(self->state,name);

    privateLuaCembedTableIteration * iterator = nwqprivateLuaCembedTableIteration(self);
    va_list  args;
    va_start(args,format);
    int args_result = privateLuaCembedTableIteration_set_args_code(iterator,format,args);
    va_end(args);

    if(args_result){
        privateLuaCembedTableIteration_free(iterator);
        return LUA_CEMBED_GENERIC_ERROR;
    }
    privateLuaCembedTableIteration_set_location(iterator,PRIVATE_LUA_CEMBED_GLOBAL_LOCATION,name);


    long  result = privateLuaCembedTableIteration_get_long(iterator,1);
    privateLuaCembedTableIteration_free(iterator);
    return result;
}
double LuaCEmbed_get_global_table_double(LuaCEmbed *self,const char *name,const char *format, ...){
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_TABLE)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    lua_getglobal(self->state,name);

    privateLuaCembedTableIteration * iterator = nwqprivateLuaCembedTableIteration(self);
    va_list  args;
    va_start(args,format);
    int args_result = privateLuaCembedTableIteration_set_args_code(iterator,format,args);
    va_end(args);

    if(args_result){
        privateLuaCembedTableIteration_free(iterator);
        return LUA_CEMBED_GENERIC_ERROR;
    }
    privateLuaCembedTableIteration_set_location(iterator,PRIVATE_LUA_CEMBED_GLOBAL_LOCATION,name);


    double  result = privateLuaCembedTableIteration_get_double(iterator,1);
    privateLuaCembedTableIteration_free(iterator);
    return result;
}

char *LuaCEmbed_get_global_table_string(LuaCEmbed *self,const char *name,const char *format, ...){
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_TABLE)){
        return  NULL;
    }
    lua_getglobal(self->state,name);
    privateLuaCembedTableIteration * iterator = nwqprivateLuaCembedTableIteration(self);
    va_list  args;
    va_start(args,format);
    int args_result = privateLuaCembedTableIteration_set_args_code(iterator,format,args);
    va_end(args);

    if(args_result){
        privateLuaCembedTableIteration_free(iterator);
        return NULL;
    }
    privateLuaCembedTableIteration_set_location(iterator,PRIVATE_LUA_CEMBED_GLOBAL_LOCATION,name);

    char*  result = privateLuaCembedTableIteration_get_str(iterator,1);

    privateLuaCembedTableIteration_free(iterator);
    return result;
}

bool LuaCEmbed_get_global_table_bool(LuaCEmbed *self,const char *name,const char *format, ...){
    lua_getglobal(self->state,name);
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_TABLE)){
        return  false;
    }

    privateLuaCembedTableIteration * iterator = nwqprivateLuaCembedTableIteration(self);
    va_list  args;
    va_start(args,format);
    int args_result = privateLuaCembedTableIteration_set_args_code(iterator,format,args);
    va_end(args);

    if(args_result){
        privateLuaCembedTableIteration_free(iterator);
        return false;
    }
    privateLuaCembedTableIteration_set_location(iterator,PRIVATE_LUA_CEMBED_GLOBAL_LOCATION,name);


    bool result = privateLuaCembedTableIteration_get_bool(iterator,1);
    privateLuaCembedTableIteration_free(iterator);
    return result;
}

int  LuaCEmbed_get_global_table_type(LuaCEmbed *self,const char *name,const char *format, ...){
    lua_getglobal(self->state,name);
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_TABLE)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    privateLuaCembedTableIteration * iterator = nwqprivateLuaCembedTableIteration(self);
    va_list  args;
    va_start(args,format);
    int args_result = privateLuaCembedTableIteration_set_args_code(iterator,format,args);
    va_end(args);

    if(args_result){
        privateLuaCembedTableIteration_free(iterator);
        return LUA_CEMBED_GENERIC_ERROR;
    }
    privateLuaCembedTableIteration_set_location(iterator,PRIVATE_LUA_CEMBED_GLOBAL_LOCATION,name);


    int   result = privateLuaCembedTableIteration_get_type(iterator,1);
    privateLuaCembedTableIteration_free(iterator);
    return result;
}

long  LuaCEmbed_get_global_table_size(LuaCEmbed *self,const char *name,const char *format, ...){
    lua_getglobal(self->state,name);
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_TABLE)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    privateLuaCembedTableIteration * iterator = nwqprivateLuaCembedTableIteration(self);
    va_list  args;
    va_start(args,format);
    int args_result = privateLuaCembedTableIteration_set_args_code(iterator,format,args);
    va_end(args);

    if(args_result){
        privateLuaCembedTableIteration_free(iterator);
        return LUA_CEMBED_GENERIC_ERROR;
    }
    privateLuaCembedTableIteration_set_location(iterator,PRIVATE_LUA_CEMBED_GLOBAL_LOCATION,name);


    long   result = privateLuaCembedTableIteration_get_size(iterator,1);
    privateLuaCembedTableIteration_free(iterator);
    return result;
}
