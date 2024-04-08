
int  LuaCEmbed_get_total_args(LuaCEmbed *self){
    return lua_gettop(self->state);
}

int  LuaCEmbed_get_arg_type(LuaCEmbed *self,int index){
    return  lua_type(self->state, index+1);
}

bool LuaCEmbed_has_errors(LuaCEmbed *self){

}

long LuaCEmbed_get_long_arg(LuaCEmbed *self, int index){
    if(LuaCEmbed_get_arg_type(self,index) != LUA_CEMBED_NUMBER){
        return LUA_CEMBED_NOT_FOUND;
    }
    return (long)lua_tonumber(self->state,index+1);
}


double LuaCEmbed_get_double_arg(LuaCEmbed *self, int index){
    if(LuaCEmbed_get_arg_type(self,index) != LUA_CEMBED_NUMBER){
        return LUA_CEMBED_NOT_FOUND;
    }
    return (double )lua_tonumber(self->state,index+1);
}

bool LuaCEmbed_get_bool_arg(LuaCEmbed *self, int index){
    if(LuaCEmbed_get_arg_type(self,index) != LUA_CEMBED_BOOL){
        return LUA_CEMBED_NOT_FOUND;
    }
    return (bool)lua_toboolean(self->state,index+1);
}

char * LuaCEmbed_get_str_arg(LuaCEmbed *self, int index){
    if(LuaCEmbed_get_arg_type(self,index) != LUA_CEMBED_STRING){
        return NULL;
    }
    return (char*)lua_tostring(self->state,index+1);
}

void privateLuaCEmbed_evaluate_arg_expresion(LuaCEmbed *self,int index,const char *expresion, va_list args){

    char formated_expresion[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    vsnprintf(formated_expresion, sizeof(formated_expresion),expresion,args);

    char formated_function[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    snprintf(formated_function, sizeof(formated_function),
            PRIVATE_LUA_CEMBED_FUNCTION_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_FUNCTION_EVALUATION_NAME,
             formated_expresion
            );

    LuaCEmbed_evaluate_string(self,formated_function);

    lua_getglobal(self->state, PRIVATE_LUA_CEMBED_FUNCTION_EVALUATION_NAME);
    lua_pushvalue(self->state,index);
    const int TOTAL_ARGS =1;
    const int TOTAL_RETURNS =1;
    //calling the function
    lua_pcall(self->state,TOTAL_ARGS,TOTAL_RETURNS,0);


}
