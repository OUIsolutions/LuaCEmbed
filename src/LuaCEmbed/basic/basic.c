

LuaCEmbed * newLuaCEmbedEvaluation(){
    LuaCEmbed  *self = (LuaCEmbed*) malloc(sizeof (LuaCEmbed));
    *self = (LuaCEmbed){0};
    self->state = luaL_newstate();
    int used_memory = 0;
    if(LUA_CEMBED_MAX_MEMORY_LIMIT > 0){
        lua_setallocf(self->state, private_LuaCembed_custom_allocator, &used_memory);
    }

    self->global_tables = (void*)newprivateLuaCEmbedTableArray();
    self->timeout = LUA_CEMBED_DEFAULT_TIMEOUT;
    return self;
}


void LuaCembed_set_delete_function(LuaCEmbed *self,void (*delelte_function)(struct  LuaCEmbed *self)){
    self->delete_function = delelte_function;
}

int private_LuaCemb_internal_free(lua_State *L){

    LuaCEmbed  *self = (LuaCEmbed*)lua_touserdata(L, lua_upvalueindex(1));
    if(self->delete_function){
        self->delete_function(self);
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
    self->global_tables = (void*)newprivateLuaCEmbedTableArray();



    //creating the metatable
    luaL_newmetatable(self->state, PRIVATE_LUA_CEMBED_MAIN_META_TABLE);

    //seting the clojure key
    lua_pushstring(self->state,PRIVATE_LUA_CEMBED_DEL_PREFIX);


    //set self as first clojure argument
    lua_pushlightuserdata(self->state,(void*)self);
    lua_pushcclosure(self->state,private_LuaCemb_internal_free,1);

    lua_settable(self->state, -3);



    //creating the global table to store the elements
    lua_newtable(self->state);
    lua_setglobal(self->state,PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME);

    luaL_setmetatable(self->state, PRIVATE_LUA_CEMBED_MAIN_META_TABLE);


    return  self;
}

int LuaCembed_perform(LuaCEmbed *self){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME);
    return 1;
}


void LuaCEmbed_set_timeout(LuaCEmbed *self,int seconds){
    self->timeout = seconds;
}

char * LuaCEmbed_get_error_message(LuaCEmbed *self){
    if(!self){
        return NULL;
    }

    return self->error_msg;
}
void LuaCEmbed_clear_errors(LuaCEmbed *self){
    if(!self){
        return;
    }

    if(self->error_msg){
        free(self->error_msg);
        self->error_msg = NULL;
    }
}
void * privateLuaCEmbed_get_current_table_array(LuaCEmbed *self){
    if(self->current_function){
       return  self->func_tables;
    }
    return self->global_tables;
}
void privateLuaCEmbed_raise_error_not_jumping(LuaCEmbed *self, const char *error, ...){
    if(!self){
        return;
    }
    LuaCEmbed_clear_errors(self);
    va_list args;
    va_start(args,error);
    self->error_msg = private_LuaCembed_format_vaarg(error, args);
    va_end(args);

}



bool LuaCEmbed_has_errors(LuaCEmbed *self){
    if(!self){
        return true;
    }

    if(self->error_msg){
        return  true;
    }

    return false;
}





void LuaCEmbed_free(LuaCEmbed *self){
    privateLuaCEmbedTableArray_free((privateLuaCEmbedTableArray*)self->global_tables);
    if(!self->is_lib){ //se for do próprio lua, o lua cuidará de limpar
        lua_close(self->state); // Fecha o estado Lua
    }
    if(self->error_msg){
        free(self->error_msg);
    }

    free(self);
}
