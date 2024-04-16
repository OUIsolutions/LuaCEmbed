



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


char * LuaCEmbed_evaluate_string_returning_string(LuaCEmbed *self, char *code, ...){

    va_list args;
    va_start(args,code);
    char formated_expresion[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    vsnprintf(formated_expresion, sizeof(formated_expresion),code,args);
    va_end(args);

    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(buffer,
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_EVALUATION_NAME,
            formated_expresion
    );

    if(LuaCEmbed_evaluate_string_no_return(self, buffer)){
        return  NULL;
    }

    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_EVALUATION_NAME);

    int type = lua_type(self->state,-1);

    if(type ==LUA_CEMBED_STRING ){
        return (char*)lua_tostring(self->state,-1);
    }



    return LuaCEmbed_get_global_string(self,PRIVATE_LUA_CEMBED_EVALUATION_NAME);

}

