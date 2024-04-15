

LuaCEmbed * newLuaCEmbedEvaluation(){
    LuaCEmbed  *self = (LuaCEmbed*) malloc(sizeof (LuaCEmbed));
    *self = (LuaCEmbed){0};
    self->state = luaL_newstate();
    return self;
}

LuaCEmbed * newLuaCEmbedLib(lua_State *state,bool public_functions){
    LuaCEmbed  *self = (LuaCEmbed*) malloc(sizeof (LuaCEmbed));
    *self = (LuaCEmbed){0};
    self->state = state;
    self->is_lib = true;
    self->public_functions = public_functions;


    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(buffer,PRIVATE_LUA_CEMBED_TABLE_CREATION,PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME);
    LuaCEmbed_evaluate_string(self,buffer);


    return  self;
}

void LuaCembed_perform(LuaCEmbed *self){
    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME);
    lua_pcall(self->state,0,1,0);
    lua_pushvalue(self->state,-1);
}

void private_LuaCembed_handle_timeout(int signum) {
    if(global_current_lua_embed_object->runing){
        LuaCEmbed_raise_error(global_current_lua_embed_object, PRIVATE_LUA_CEMBED_TIMEOUT_ERROR);
    }

}

void LuaCEmbed_set_timeout(LuaCEmbed *self,int seconds){
    global_current_lua_embed_object = self;
    signal(SIGALRM, private_LuaCembed_handle_timeout);
    alarm(seconds);
}

char * LuaCEmbed_get_error_message(LuaCEmbed *self){
    return self->error_message;
}


void LuaCEmbed_raise_error(LuaCEmbed *self, const char *error){
    if(LuaCEmbed_has_errors(self)){
        return;
    }
    if(self->current_function){ // means its in protected mode
        lua_pushstring(self->state,error);
        lua_error(self->state);
    }

    self->error_message = strdup(error);
}



bool LuaCEmbed_has_errors(LuaCEmbed *self){

    if(self->error_message){
        return  true;
    }

    return false;
}




int LuaCEmbed_evaluate_string(LuaCEmbed *self, const char *str){
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

void LuaCEmbed_free(LuaCEmbed *self){

    if(!self->is_lib){ //se for do próprio lua, o lua cuidará de limpar
        lua_close(self->state); // Fecha o estado Lua
    }
    if(self->error_message){
        free(self->error_message);
    }

    free(self);
}
