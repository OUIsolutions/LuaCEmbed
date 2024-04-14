

int LuaCEmbed_get_global_type(LuaCEmbed *self,const char *name){

    return lua_type(self->state,-1);
}

long LuaCEmbed_get_global_long(LuaCEmbed *self,const char *name){
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_NUMBER)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    lua_getglobal(self->state, name);
    return (long )lua_tonumber(self->state,-1);
}

double LuaCEmbed_get_global_double(LuaCEmbed *self,const char *name){
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_NUMBER)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    lua_getglobal(self->state, name);
    return (double )lua_tonumber(self->state,-1);
}

bool LuaCEmbed_get_global_bool(LuaCEmbed *self,const char *name){
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_BOOL)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }
    lua_getglobal(self->state, name);
    return lua_toboolean(self->state,-1);
}


char * LuaCEmbed_get_global_string(LuaCEmbed *self,const char *name){
    if(LuaCEmbed_ensure_global_type(self,name,LUA_CEMBED_STRING)){
        return  NULL;
    }
    lua_getglobal(self->state, name);
    return (char*)lua_tostring(self->state,-1);
}


int  LuaCEmbed_get_global_evaluation_type(LuaCEmbed *self, char *code){
    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(buffer,
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_EVALUATION_NAME,
            code
    );

    if(LuaCEmbed_evaluate_string(self,buffer)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    return LuaCEmbed_get_global_type(self,PRIVATE_LUA_CEMBED_EVALUATION_NAME);

}
char * LuaCEmbed_get_global_evaluation_string(LuaCEmbed *self, char *code){

    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(buffer,
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_EVALUATION_NAME,
            code
            );

    if(LuaCEmbed_evaluate_string(self,buffer)){
        return  NULL;
    }

    return LuaCEmbed_get_global_string(self,PRIVATE_LUA_CEMBED_EVALUATION_NAME);

}


long LuaCEmbed_get_global_evaluation_long(LuaCEmbed *self, char *code){

    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(buffer,
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_EVALUATION_NAME,
            code
    );

    if(LuaCEmbed_evaluate_string(self,buffer)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    return LuaCEmbed_get_global_long(self,PRIVATE_LUA_CEMBED_EVALUATION_NAME);
}

double LuaCEmbed_get_global_evaluation_double(LuaCEmbed *self, char *code){
    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(buffer,
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_EVALUATION_NAME,
            code
    );

    if(LuaCEmbed_evaluate_string(self,buffer)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    return LuaCEmbed_get_global_double(self,PRIVATE_LUA_CEMBED_EVALUATION_NAME);
}

bool LuaCEmbed_get_global_evaluation_bool(LuaCEmbed *self, char *code){
    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(buffer,
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_EVALUATION_NAME,
            code
    );

    if(LuaCEmbed_evaluate_string(self,buffer)){
        return  LUA_CEMBED_GENERIC_ERROR;
    }

    return LuaCEmbed_get_global_bool(self,PRIVATE_LUA_CEMBED_EVALUATION_NAME);
}