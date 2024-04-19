

int private_LuaCembed_run_code_with_args(LuaCEmbed *self,int index,char *code,va_list args){

    if(LuaCEmbed_ensure_arg_exist(self,index)){
        return LUA_CEMBED_GENERIC_ERROR;
    }

    char formated_expresion[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    vsnprintf(formated_expresion, sizeof(formated_expresion),code,args);

    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE + 1000] = {0};
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
        char buffer_func[LUA_CEMBED_ARGS_BUFFER_SIZE +1000]  = {0};
        sprintf(buffer_func,PRIVATE_LUA_CEMBED_CODE_ITS_NOT_A_FUNCTION,formated_expresion);
    }

    lua_pushvalue(self->state,index+1);

    if(lua_pcall(self->state,1,1,0)){
        const char *generated_error = lua_tostring(self->state,-1);
        privateLuaCEmbed_raise_error_not_jumping(self, generated_error);
    }

    return LUA_CEMBED_OK;
}

int privateLuaCembed_ensure_arg_evaluation_type(LuaCEmbed *self,int index,int expected_type){
    int actual_type = lua_type(self->state,-1);
    if(actual_type== expected_type){
        return LUA_CEMBED_OK;
    }
    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(buffer,
            PRIVATE_LUA_CEMBED_RESULT_EVALUATION_ARG_WRONG_TYPE,
            self->current_function,
            index,
            LuaCembed_convert_arg_code(actual_type),
            LuaCembed_convert_arg_code(expected_type)
    );
    privateLuaCEmbed_raise_error_not_jumping(self, buffer);
    return LUA_CEMBED_GENERIC_ERROR;
}
long LuaCEmbed_get_type_clojure_evalation(LuaCEmbed *self,int index,char *code,...){

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCembed_run_code_with_args(self,index,code,args);
    va_end(args);
    if(possible_error){
        return possible_error;
    }
    return lua_type(self->state,-1);
}
long LuaCEmbed_generate_arg_clojure_evalation(LuaCEmbed *self,int index,char *code,...){
    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCembed_run_code_with_args(self,index,code,args);
    va_end(args);
    if(possible_error){
        return possible_error;
    }
    return LUA_CEMBED_OK;
}
long LuaCEmbed_get_long_arg_clojure_evalation(LuaCEmbed *self,int index,char *code,...){

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCembed_run_code_with_args(self,index,code,args);
    va_end(args);
    if(possible_error){
        return possible_error;
    }
    if(privateLuaCembed_ensure_arg_evaluation_type(self,index,LUA_CEMBED_NUMBER)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    return (long) lua_tonumber(self->state,-1);

}


double LuaCEmbed_get_double_arg_clojure_evalation(LuaCEmbed *self,int index,char *code,...){
    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCembed_run_code_with_args(self,index,code,args);
    va_end(args);
    if(possible_error){
        return possible_error;
    }
    if(privateLuaCembed_ensure_arg_evaluation_type(self,index,LUA_CEMBED_NUMBER)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    return (double ) lua_tonumber(self->state,-1);

}

bool LuaCEmbed_get_bool_arg_clojure_evalation(LuaCEmbed *self,int index,char *code,...){
    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCembed_run_code_with_args(self,index,code,args);
    va_end(args);
    if(possible_error){
        return possible_error;
    }
    if(privateLuaCembed_ensure_arg_evaluation_type(self,index,LUA_CEMBED_NUMBER)){
        return  false;
    }
    return lua_toboolean(self->state,-1);

}

char* LuaCEmbed_get_string_arg_clojure_evalation(LuaCEmbed *self,int index,char *code,...){
    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCembed_run_code_with_args(self,index,code,args);
    va_end(args);
    if(possible_error){
        return  NULL;
    }
    if(privateLuaCembed_ensure_arg_evaluation_type(self,index,LUA_CEMBED_NUMBER)){
        return  NULL;
    }
    return (char*)lua_tostring(self->state,-1);

}

