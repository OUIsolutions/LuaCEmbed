

int LuaCEmbed_ensure_arg_exist(LuaCEmbed *self, int index){

    if(LuaCEmbed_has_errors(self)){
        return LUA_CEMBED_GENERIC_ERROR;
    }

    if(index >= LuaCEmbed_get_total_args(self) ){
        char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
        sprintf(buffer,PRIVATE_LUA_CEMBED_ARG_NOT_PROVIDED,index,self->current_function);
        privateLuaCEmbed_raise_internal_error(self, buffer);
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return LUA_CEMBED_OK;

}

int LuaCEmbed_ensure_arg_type(LuaCEmbed *self,int index, int arg_type) {

    if (LuaCEmbed_ensure_arg_exist(self, index)) {
        return LUA_CEMBED_GENERIC_ERROR;
    }
    int type = LuaCEmbed_get_arg_type(self, index);
    if (type != arg_type) {

        privateLuaCEmbed_raise_internal_error(self,
                                              PRIVATE_LUA_CEMBED_ARG_WRONG_TYPE,
                                              index + 1,
                                              self->current_function,
                                              LuaCembed_convert_arg_code(type),
                                              LuaCembed_convert_arg_code(arg_type)
        );
        return LUA_CEMBED_GENERIC_ERROR;
    }

    return LUA_CEMBED_OK;

}

