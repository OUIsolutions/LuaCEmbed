
int privateLuaCEmbed_put_arg_on_top(LuaCEmbed *self, int index){
    long  formatted_index = index + LUA_CEMBED_INDEX_DIF;
    char *formated_arg = private_LuaCembed_format(PRIVATE_LUA_CEMBED_ARGS,formatted_index);
    lua_getglobal(self->state,formated_arg);

    if(lua_type(self->state,-1) == LUA_CEMBED_NOT_FOUND){

        char *error = private_LuaCembed_format(PRIVATE_LUA_CEMBED_ARG_NOT_PROVIDED,formatted_index,self->current_function);

        privateLuaCEmbed_raise_error_not_jumping(self,error);
        free(error);
        free(formated_arg);

        return LUA_CEMBED_GENERIC_ERROR;
    }
    free(formated_arg);
    return LUA_OK;
}

int  LuaCEmbed_get_total_args(LuaCEmbed *self){
    return self->total_args;
}



int  LuaCEmbed_get_arg_type(LuaCEmbed *self,int index){
    PRIVATE_LUA_CEMBED_PROTECT_NUM
    privateLuaCEmbed_put_arg_on_top(self,index);
    return  lua_type(self->state, -1);
}


long LuaCEmbed_get_long_arg(LuaCEmbed *self, int index){
    PRIVATE_LUA_CEMBED_PROTECT_NUM
    privateLuaCEmbed_put_arg_on_top(self,index);
    if(private_LuaCEmbed_ensure_arg_type(self,LUA_CEMBED_NUMBER)){
        return (long )LUA_CEMBED_NOT_FOUND;
    }
    return (long)lua_tonumber(self->state,-1);
}


double LuaCEmbed_get_double_arg(LuaCEmbed *self, int index){
    PRIVATE_LUA_CEMBED_PROTECT_NUM
    privateLuaCEmbed_put_arg_on_top(self,index);
    if(private_LuaCEmbed_ensure_arg_type(self,LUA_CEMBED_NUMBER)){
        return (long )LUA_CEMBED_NOT_FOUND;
    }
    return lua_tonumber(self->state,-1);
}

bool LuaCEmbed_get_bool_arg(LuaCEmbed *self, int index){
    PRIVATE_LUA_CEMBED_PROTECT_BOOL
    privateLuaCEmbed_put_arg_on_top(self,index);
    if(private_LuaCEmbed_ensure_arg_type(self,LUA_CEMBED_BOOL)){
        return (long )LUA_CEMBED_NOT_FOUND;
    }
    return lua_toboolean(self->state,-1);
}


char * LuaCEmbed_get_str_arg(LuaCEmbed *self, int index){
    PRIVATE_LUA_CEMBED_PROTECT_NULL
    privateLuaCEmbed_put_arg_on_top(self,index);
    if(private_LuaCEmbed_ensure_arg_type(self,LUA_CEMBED_STRING)){
        return NULL;
    }
    return (char*)lua_tostring(self->state,-1);
}

LuaCEmbedTable  * LuaCEmbed_get_arg_table(LuaCEmbed *self,int index){
    PRIVATE_LUA_CEMBED_PROTECT_NULL
    privateLuaCEmbed_put_arg_on_top(self,index);
    if(private_LuaCEmbed_ensure_arg_type(self,LUA_CEMBED_TABLE)){
        return NULL;
    }

    int formatted_index = index + LUA_CEMBED_INDEX_DIF;
    char *formated_arg = private_LuaCembed_format(PRIVATE_LUA_CEMBED_ARGS,formatted_index);
    LuaCEmbedTable  *created = LuaCembed_get_global_table(self,formated_arg);
    free(formated_arg);
    return created;
}

LuaCEmbedTable* LuaCEmbed_run_args_lambda(LuaCEmbed *self, int index, LuaCEmbedTable *args_to_call, int total_returns){



    return NULL;
}
