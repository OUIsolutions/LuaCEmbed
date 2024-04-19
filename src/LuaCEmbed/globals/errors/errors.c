



int LuaCEmbed_ensure_global_type(LuaCEmbed *self, const char *name,int expected_type){

    lua_getglobal(self->state,name);
    int type = lua_type(self->state,-1);


    if(type != expected_type){

        char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
        sprintf(
                buffer,
                PRIVATE_LUA_CEMBED_GLOBAL_WRONG_TYPE,
                name,
                LuaCembed_convert_arg_code(type),
                LuaCembed_convert_arg_code(expected_type)
        );

        privateLuaCEmbed_raise_error_not_jumping(self, buffer);
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    return LUA_CEMBED_OK;

}