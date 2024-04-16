

int private_LuaCembed_run_code_with_args(LuaCEmbed *self,int index,char *code,va_list args){

    char formated_expresion[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    vsnprintf(formated_expresion, sizeof(formated_expresion),code,args);

    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(buffer,
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_EVALUATION_NAME,
            formated_expresion
    );

    if(LuaCEmbed_evaluate_string_no_return(self, buffer)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_EVALUATION_NAME);

    int type = lua_type(self->state,-1);

    if(type != LUA_CEMBED_FUNCTION){
        char buffer_func[LUA_CEMBED_ARGS_BUFFER_SIZE]  = {0};
        sprintf(buffer_func,PRIVATE_LUA_CEMBED_CODE_ITS_NOT_A_FUNCTION,formated_expresion);
    }

    lua_pushvalue(self->state,index+1);

    if(lua_pcall(self->state,1,1,0)){
        const char *generated_error = lua_tostring(self->state,-1);
        LuaCEmbed_raise_error(self,generated_error );
    }

    return LUA_CEMBED_OK;
}