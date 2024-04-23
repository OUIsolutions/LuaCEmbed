

int LuaCEmbed_ensure_arg_exist(LuaCEmbed *self, private_lua_cembed_incremented_arg index){

    if(LuaCEmbed_has_errors(self)){
        return LUA_CEMBED_GENERIC_ERROR;
    }

    if(index > self->total_args){
        char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
        sprintf(buffer,PRIVATE_LUA_CEMBED_ARG_NOT_PROVIDED,index,self->current_function);
        privateLuaCEmbed_raise_error_not_jumping(self, buffer);
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return LUA_CEMBED_OK;

}

int LuaCEmbed_ensure_arg_type(LuaCEmbed *self, private_lua_cembed_incremented_arg index, int arg_type) {

    if (LuaCEmbed_ensure_arg_exist(self, index)) {
        return LUA_CEMBED_GENERIC_ERROR;
    }
    int type = lua_type(self->state, index);
    if (type != arg_type) {

        privateLuaCEmbed_raise_error_not_jumping(self,
                 PRIVATE_LUA_CEMBED_ARG_WRONG_TYPE,
                 index,
                 self->current_function,
                 LuaCembed_convert_arg_code(type),
                 LuaCembed_convert_arg_code(arg_type)
        );
        return LUA_CEMBED_GENERIC_ERROR;
    }

    return LUA_CEMBED_OK;

}

