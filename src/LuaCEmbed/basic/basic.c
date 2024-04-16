

LuaCEmbed * newLuaCEmbedEvaluation(){
    LuaCEmbed  *self = (LuaCEmbed*) malloc(sizeof (LuaCEmbed));
    *self = (LuaCEmbed){0};
    self->state = luaL_newstate();
    return self;
}


void LuaCembed_set_delete_function(LuaCEmbed *self,void (*delelte_function)(struct  LuaCEmbed *self)){
    self->delelte_function = delelte_function;
}

int private_LuaCemb_internal_free(lua_State *L){
    LuaCEmbed  *self = (LuaCEmbed*)lua_touserdata(L, lua_upvalueindex(1));
    if(self->delelte_function){
        self->delelte_function(self);
    }
    LuaCEmbed_free(self);
    return 0;
}
LuaCEmbed * newLuaCEmbedLib(lua_State *state,bool public_functions){
    LuaCEmbed  *self = (LuaCEmbed*) malloc(sizeof (LuaCEmbed));
    *self = (LuaCEmbed){0};
    self->state = state;
    self->is_lib = true;
    self->public_functions = public_functions;



    //creating the metatable
    luaL_newmetatable(self->state,PRIVATE_LUA_CEMBED_META_TABLE);

    //seting the clojure key
    lua_pushstring(self->state,PRIVATE_LUA_CEMBED_DEL_PREFIX);


    //set self as first clojure argument
    lua_pushlightuserdata(self->state,(void*)self);
    lua_pushcclosure(self->state,private_LuaCemb_internal_free,1);

    lua_settable(self->state, -3);



    //creating the global table to store the elements
    lua_newtable(self->state);
    lua_setglobal(self->state,PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME);

    luaL_setmetatable(self->state, PRIVATE_LUA_CEMBED_META_TABLE);


    return  self;
}

void LuaCembed_perform(LuaCEmbed *self){
    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME);
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






void LuaCEmbed_free(LuaCEmbed *self){

    if(!self->is_lib){ //se for do próprio lua, o lua cuidará de limpar
        lua_close(self->state); // Fecha o estado Lua
    }
    if(self->error_message){
        free(self->error_message);
    }

    free(self);
}
