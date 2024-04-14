
int private_LuaCEmbed_ensure_table_arg_type(LuaCEmbed *self,int index,int expected_type){
    int type = lua_type(self->state,-1);
    if(type != expected_type){
        char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
        sprintf(buffer,PRIVATE_LUA_CEMBED_TABLE_ARG_WRONG_TYPE,
                index,
                self->current_function,
                LuaCembed_convert_arg_code(type),
                LuaCembed_convert_arg_code(expected_type)
        );
        LuaCEmbed_raise_error(self,buffer);
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return  LUA_OK;
}
int  LuaCEmbed_get_table_arg_type(LuaCEmbed *self, int index,const char *expresion,...){

    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return LUA_CEMBED_NOT_FOUND;
    }

    va_list args;
va_start(args, expresion);
int error_code = privateLuaCEmbed_evaluate_arg_expresion(self,index,expresion,args);
va_end(args);
if(error_code){
    return  error_code;
}

return lua_type(self->state, -1);

}

char *  LuaCEmbed_get_table_arg_string(LuaCEmbed *self, int index,const char *expresion,...){

    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return NULL;
    }

    va_list args;
    va_start(args, expresion);
    int error_code = privateLuaCEmbed_evaluate_arg_expresion(self,index,expresion,args);
    va_end(args);
    if(error_code){
        return NULL;
    }
    if(private_LuaCEmbed_ensure_table_arg_type(self,index,LUA_CEMBED_STRING)){
        return NULL;
    }
    return (char*)lua_tostring(self->state, -1);


}

long LuaCEmbed_get_table_arg_long(LuaCEmbed *self, int index,const char *expresion,...){

    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return LUA_CEMBED_GENERIC_ERROR;
    }

    va_list args;
    va_start(args, expresion);
    int error_code = privateLuaCEmbed_evaluate_arg_expresion(self,index,expresion,args);
    va_end(args);
    if(error_code){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    if(private_LuaCEmbed_ensure_table_arg_type(self,index,LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (long )lua_tonumber(self->state, -1);

}

long LuaCEmbed_get_table_arg_size(LuaCEmbed *self, int index,const char *expresion,...){
    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return LUA_CEMBED_GENERIC_ERROR;
    }

    va_list args;
    va_start(args, expresion);
    int error_code = privateLuaCEmbed_evaluate_arg_expresion(self,index,expresion,args);
    va_end(args);
    if(error_code){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    if(private_LuaCEmbed_ensure_table_arg_type(self,index,LUA_CEMBED_TABLE)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (long)lua_rawlen(self->state,-1);
}

double LuaCEmbed_get_table_arg_double(LuaCEmbed *self, int index,const char *expresion,...){
    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return LUA_CEMBED_GENERIC_ERROR;
    }

    va_list args;
    va_start(args, expresion);
    int error_code = privateLuaCEmbed_evaluate_arg_expresion(self,index,expresion,args);
    va_end(args);
    if(error_code){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    if(private_LuaCEmbed_ensure_table_arg_type(self,index,LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (double)lua_tonumber(self->state, -1);

}

bool LuaCEmbed_get_table_arg_bool(LuaCEmbed *self, int index,const char *expresion,...){
    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return false;
    }

    va_list args;
    va_start(args, expresion);
    int error_code = privateLuaCEmbed_evaluate_arg_expresion(self,index,expresion,args);
    va_end(args);
    if(error_code){
        return false;
    }
    if(private_LuaCEmbed_ensure_table_arg_type(self,index,LUA_CEMBED_BOOL)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return lua_toboolean(self->state, -1);

}
