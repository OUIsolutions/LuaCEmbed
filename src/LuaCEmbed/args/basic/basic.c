
int  LuaCEmbed_get_total_args(LuaCEmbed *self){
    return self->total_args;
}


int  LuaCEmbed_get_arg_type(LuaCEmbed *self,int index){
    return  lua_type(self->state, index+1);
}


long LuaCEmbed_get_long_arg(LuaCEmbed *self, int index){
    if(LuaCEmbed_ensure_arg_type(self,index+1,LUA_CEMBED_NUMBER)){
        return (long )LUA_CEMBED_NOT_FOUND;
    }
    return (long)lua_tonumber(self->state,index+1);
}


double LuaCEmbed_get_double_arg(LuaCEmbed *self, int index){
    if(LuaCEmbed_ensure_arg_type(self,index+1,LUA_CEMBED_NUMBER)){
        return (double )LUA_CEMBED_NOT_FOUND;
    }

    return (double )lua_tonumber(self->state,index+1);
}

bool LuaCEmbed_get_bool_arg(LuaCEmbed *self, int index){
    if(LuaCEmbed_ensure_arg_type(self,index+1,LUA_CEMBED_BOOL)){
        return false;
    }
    return (bool)lua_toboolean(self->state,index+1);
}

char * LuaCEmbed_get_str_arg(LuaCEmbed *self, int index){
    if(LuaCEmbed_ensure_arg_type(self,index+1,LUA_CEMBED_STRING)){
        return NULL;
    }
    return (char*)lua_tostring(self->state,index+1);
}

LuaCEmbedTable  * LuaCEmbed_get_arg_table(LuaCEmbed *self,int index){
    if(LuaCEmbed_ensure_arg_type(self,index+1,LUA_CEMBED_TABLE)){
        return NULL;
    }

    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(buffer,PRIVATE_LUA_CEMBE_SUB_ARG_TABLE,self->current_function,index+1);

    lua_pushvalue(self->state,index+1);
    lua_setglobal(self->state,buffer);
    return (LuaCEmbedTable*)private_LuaCembed_get_table_or_create_internal(self,buffer);
}