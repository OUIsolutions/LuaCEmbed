
void private_LuaCembed_handle_timeout(int signum) {

    privateLuaCEmbed_raise_error_not_jumping(global_current_lua_embed_object, PRIVATE_LUA_CEMBED_TIMEOUT_ERROR);


}

int privateLuaCEmbed_start_func_evaluation(lua_State *state){

    int evaluation_type = lua_tointeger(state, lua_upvalueindex(1));
    char *text_value = (char*)lua_touserdata(state,lua_upvalueindex(2));
    PRIVATE_LUA_CEMBED_PROTECT_VOID
    global_current_lua_embed_object = self;
    signal(SIGALRM, private_LuaCembed_handle_timeout);
    alarm(seconds);

}
int LuaCEmbed_evaluate(LuaCEmbed *self, const char *code, ...){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    va_list args;
    va_start(args,code);
    char * formated_expresion = private_LuaCembed_format_vaarg(code,args);
    va_end(args);

    int error = luaL_dostring(self->state,formated_expresion);
    if(error){
        privateLuaCEmbed_raise_error_not_jumping(self,lua_tostring(self->state,-1));
    }

    free(formated_expresion);
    return error;

}

int LuaCEmbed_evaluete_file(LuaCEmbed *self, const char *file){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    int error =luaL_dofile(self->state,file);
    if(error){
        privateLuaCEmbed_raise_error_not_jumping(self,lua_tostring(self->state,-1));
    }

    return error;

}

int private_LuaCEmbed_evaluate_puting_on_top_of_stack(LuaCEmbed *self,char *code, va_list args){

    char * formated_expresion =private_LuaCembed_format_vaarg(code,args);

    char * buffer =private_LuaCembed_format(
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_EVALUATION_NAME,
            formated_expresion
    );

    if(LuaCEmbed_evaluate(self, buffer)){
        free(formated_expresion);
        free(buffer);
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_EVALUATION_NAME);

    int type = lua_type(self->state,-1);

    if(type == LUA_CEMBED_FUNCTION){
        if(lua_pcall(self->state,0,1,0)){
            const char *generated_error = lua_tostring(self->state,-1);
            privateLuaCEmbed_raise_error_not_jumping(self, generated_error);
        }
    }
    free(formated_expresion);
    free(buffer);
    return LUA_CEMBED_OK;

}
int private_LuaCEmbed_ensure_evaluation_type(LuaCEmbed *self,int type){

    int actual_type = lua_type(self->state,-1);
    if(actual_type== type){
        return LUA_CEMBED_OK;
    }


    privateLuaCEmbed_raise_error_not_jumping(self,
         PRIVATE_LUA_CEMBED_RESULT_EVALUATION_WRONG_TYPE,
         LuaCembed_convert_arg_code(actual_type),
         LuaCembed_convert_arg_code(type)
    );

    return LUA_CEMBED_GENERIC_ERROR;
}

char * LuaCEmbed_get_evaluation_string(LuaCEmbed *self, char *code, ...){
    PRIVATE_LUA_CEMBED_PROTECT_NULL
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
    PRIVATE_LUA_CEMBED_PROTECT_NUM

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
    PRIVATE_LUA_CEMBED_PROTECT_NUM

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
    /*
    long  size = 0;
    lua_pushnil(self->state); // Coloca a chave nula na pilha
    while (lua_next(self->state, -1) != 0) { // Enquanto houver elementos na tabela
        size+=1;
        lua_pop(self->state, 1);
    }
     */

    return (long)lua_rawlen(self->state,-1);
}



long LuaCEmbed_get_evaluation_long(LuaCEmbed *self, char *code, ...){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

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
    PRIVATE_LUA_CEMBED_PROTECT_NUM

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
    PRIVATE_LUA_CEMBED_PROTECT_BOOL
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

