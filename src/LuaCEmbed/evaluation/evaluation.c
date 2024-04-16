



int LuaCEmbed_evaluate_string_no_return(LuaCEmbed *self, const char *str){
    self->runing = true;
    int error = luaL_dostring(self->state,str);
    self->runing = false;
    if(error){
        self->error_message = strdup(lua_tostring(self->state,-1));
    }
    return error;

}

int LuaCEmbed_evaluete_file(LuaCEmbed *self, const char *file){

    self->runing = true;
    int error =luaL_dofile(self->state,file);
    self->runing = false;
    if(error){
        self->error_message = strdup(lua_tostring(self->state,-1));
    }

    return error;

}

int private_LuaCEmbed_evaluate_puting_on_top_of_stack(LuaCEmbed *self,char *code, va_list args){

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

    if(type == LUA_CEMBED_FUNCTION){
        if(lua_pcall(self->state,0,1,0)){
            const char *generated_error = lua_tostring(self->state,-1);
            LuaCEmbed_raise_error(self,generated_error );
        }
    }
    return LUA_CEMBED_OK;

}
int private_LuaCEmbed_ensure_evaluation_type(LuaCEmbed *self,int type){
    int actual_type = lua_type(self->state,-1);
    if(actual_type== type){
        return LUA_CEMBED_OK;
    }
    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(buffer,
            RESULT_EVALUATION_WRONG_TYPE,
            LuaCembed_convert_arg_code(actual_type),
            LuaCembed_convert_arg_code(type)
            );
    LuaCEmbed_raise_error(self,buffer);
    return LUA_CEMBED_GENERIC_ERROR;
}

char * LuaCEmbed_evaluate_string_returning_string(LuaCEmbed *self, char *code, ...){

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCEmbed_evaluate_puting_on_top_of_stack(self,code,args);
    va_end(args);
    if(possible_error){
        return  NULL;
    }
    if(private_LuaCEmbed_ensure_evaluation_type(self,LUA_CEMBED_STRING)){
        return NULL;
    }
    return (char*)lua_tostring(self->state,-1);

}


int  LuaCEmbed_get_evaluation_type(LuaCEmbed *self, char *code, ...){
    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCEmbed_evaluate_puting_on_top_of_stack(self,code,args);
    va_end(args);
    if(possible_error){
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    return lua_type(self->state,-1);
}


long LuaCEmbed_get_evaluation_table_size(LuaCEmbed *self, char *code, ...){
    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCEmbed_evaluate_puting_on_top_of_stack(self,code,args);
    va_end(args);
    if(possible_error){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    if(private_LuaCEmbed_ensure_evaluation_type(self,LUA_CEMBED_TABLE)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (long)lua_rawlen(self->state,-1);
}


long LuaCEmbed_get_evaluation_long(LuaCEmbed *self, char *code, ...){

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCEmbed_evaluate_puting_on_top_of_stack(self,code,args);
    va_end(args);
    if(possible_error){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    if(private_LuaCEmbed_ensure_evaluation_type(self,LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (long)lua_tonumber(self->state,-1);

}

double LuaCEmbed_get_evaluation_double(LuaCEmbed *self, char *code, ...){

    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCEmbed_evaluate_puting_on_top_of_stack(self,code,args);
    va_end(args);
    if(possible_error){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    if(private_LuaCEmbed_ensure_evaluation_type(self,LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (double)lua_tonumber(self->state,-1);
}

bool LuaCEmbed_get_evaluation_bool(LuaCEmbed *self, char *code, ...){
    va_list args;
    va_start(args,code);
    int possible_error = private_LuaCEmbed_evaluate_puting_on_top_of_stack(self,code,args);
    va_end(args);
    if(possible_error){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    if(private_LuaCEmbed_ensure_evaluation_type(self,LUA_CEMBED_BOOL)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return (bool)lua_toboolean(self->state,-1);
}

