

int LuaCEmbed_ensure_arg_exist(LuaCEmbed *self, int index){


    if(LuaCEmbed_get_arg_type(self,index) == LUA_CEMBED_NOT_FOUND){
        char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
        sprintf(buffer,PRIVATE_LUA_CEMBED_ARG_NOT_PROVIDED,index,self->current_function);
        LuaCEmbed_raise_error(self,buffer);
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return LUA_CEMBED_OK;

}

int LuaCEmbed_ensure_arg_type(LuaCEmbed *self,int index, int arg_type) {

    if (LuaCEmbed_ensure_arg_exist(self, index)) {
        return LUA_CEMBED_GENERIC_ERROR;
    }

    if (LuaCEmbed_get_arg_type(self, index) != arg_type) {
        char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
        sprintf(buffer, PRIVATE_LUA_CEMBED_ARG_WRONG_TYPE, index, self->current_function, LuaCembed_convert_arg_code(arg_type));
        LuaCEmbed_raise_error(self, buffer);
        return LUA_CEMBED_GENERIC_ERROR;
    }

    return LUA_CEMBED_OK;

}