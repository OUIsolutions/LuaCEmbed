

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

char * LuaCEmbed_get_global_evaluation_string(LuaCEmbed *self, char *path){

    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(buffer,
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_EVALUATION_NAME,
            path
            );

    printf("codigo : %s",buffer);
    if(LuaCEmbed_evaluate_string(self,buffer)){
        return  NULL;
    }

    return LuaCEmbed_get_global_string(self,PRIVATE_LUA_CEMBED_EVALUATION_NAME);

}


