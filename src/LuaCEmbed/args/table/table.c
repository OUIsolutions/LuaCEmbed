


int  LuaCEmbed_get_table_arg_type(LuaCEmbed *self, int index,const char *code,...){
    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    privateLuaCembedTableIteration * iterator = nwqprivateLuaCembedTableIteration(self);
    va_list  args;
    va_start(args,code);
    int args_result = privateLuaCembedTableIteration_set_args_code(iterator,code,args);
    va_end(args);

    if(args_result){
        privateLuaCembedTableIteration_free(iterator);
        return LUA_CEMBED_GENERIC_ERROR;
    }
    privateLuaCembedTableIteration_set_location(iterator,PRIVATE_LUA_CEMBED_ARG_LOCATION,self->current_function,index+1);


    int  result = privateLuaCembedTableIteration_get_type(iterator,index+1);
    privateLuaCembedTableIteration_free(iterator);
    return result;
}


char *  LuaCEmbed_get_table_arg_string(LuaCEmbed *self, int index,const char *code,...){


    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return  NULL;
    }

    privateLuaCembedTableIteration * iterator = nwqprivateLuaCembedTableIteration(self);
    va_list  args;
    va_start(args,code);
    int args_result = privateLuaCembedTableIteration_set_args_code(iterator,code,args);
    va_end(args);

    if(args_result){
        privateLuaCembedTableIteration_free(iterator);
        return NULL;
    }
    privateLuaCembedTableIteration_set_location(iterator,PRIVATE_LUA_CEMBED_ARG_LOCATION,self->current_function,index+1);


    char *result = privateLuaCembedTableIteration_get_str(iterator,index+1);
    privateLuaCembedTableIteration_free(iterator);
    return result;
}



long LuaCEmbed_get_table_arg_long(LuaCEmbed *self, int index,const char *code,...){
    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    privateLuaCembedTableIteration * iterator = nwqprivateLuaCembedTableIteration(self);
    va_list  args;
    va_start(args,code);
    int args_result = privateLuaCembedTableIteration_set_args_code(iterator,code,args);
    va_end(args);

    if(args_result){
        privateLuaCembedTableIteration_free(iterator);
        return LUA_CEMBED_GENERIC_ERROR;
    }
    privateLuaCembedTableIteration_set_location(iterator,PRIVATE_LUA_CEMBED_ARG_LOCATION,self->current_function,index+1);


   long  result = privateLuaCembedTableIteration_get_long(iterator,index+1);
    privateLuaCembedTableIteration_free(iterator);
    return result;
}

long LuaCEmbed_get_table_arg_size(LuaCEmbed *self, int index,const char *code,...){
    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    privateLuaCembedTableIteration * iterator = nwqprivateLuaCembedTableIteration(self);
    va_list  args;
    va_start(args,code);
    int args_result = privateLuaCembedTableIteration_set_args_code(iterator,code,args);
    va_end(args);

    if(args_result){
        privateLuaCembedTableIteration_free(iterator);
        return LUA_CEMBED_GENERIC_ERROR;
    }
    privateLuaCembedTableIteration_set_location(iterator,PRIVATE_LUA_CEMBED_ARG_LOCATION,self->current_function,index+1);


    long  result = privateLuaCembedTableIteration_get_size(iterator,index+1);
    privateLuaCembedTableIteration_free(iterator);
    return result;
}

double LuaCEmbed_get_table_arg_double(LuaCEmbed *self, int index,const char *code,...){
    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    privateLuaCembedTableIteration * iterator = nwqprivateLuaCembedTableIteration(self);
    va_list  args;
    va_start(args,code);
    int args_result = privateLuaCembedTableIteration_set_args_code(iterator,code,args);
    va_end(args);

    if(args_result){
        privateLuaCembedTableIteration_free(iterator);
        return LUA_CEMBED_GENERIC_ERROR;
    }
    privateLuaCembedTableIteration_set_location(iterator,PRIVATE_LUA_CEMBED_ARG_LOCATION,self->current_function,index+1);


    double  result = privateLuaCembedTableIteration_get_double(iterator,index+1);
    privateLuaCembedTableIteration_free(iterator);
    return result;
}


bool LuaCEmbed_get_table_arg_bool(LuaCEmbed *self, int index,const char *code,...){
    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    privateLuaCembedTableIteration * iterator = nwqprivateLuaCembedTableIteration(self);
    va_list  args;
    va_start(args,code);
    int args_result = privateLuaCembedTableIteration_set_args_code(iterator,code,args);
    va_end(args);

    if(args_result){
        privateLuaCembedTableIteration_free(iterator);
        return LUA_CEMBED_GENERIC_ERROR;
    }
    privateLuaCembedTableIteration_set_location(iterator,PRIVATE_LUA_CEMBED_ARG_LOCATION,self->current_function,index+1);


    bool  result = privateLuaCembedTableIteration_get_bool(iterator,index+1);
    privateLuaCembedTableIteration_free(iterator);
    return result;
}
