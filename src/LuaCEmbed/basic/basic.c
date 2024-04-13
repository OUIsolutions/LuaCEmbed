

LuaCEmbed * newLuaCEmbed(){
    LuaCEmbed  *self = (LuaCEmbed*) malloc(sizeof (LuaCEmbed));
    *self = (LuaCEmbed){0};
    self->state = luaL_newstate();
    return self;
}

char * LuaCEmbed_get_error_message(LuaCEmbed *self){
    return self->error_message;
}

bool LuaCEmbed_has_errors(LuaCEmbed *self){
    if(self->error_message){
        return  true;
    }
    return false;
}


int privateLuaCEmbed_main_callback_handler(lua_State  *L){

    LuaCEmbedResponse* (*callback)(LuaCEmbed *args);
    callback = (LuaCEmbedResponse* (*)(LuaCEmbed *args))lua_touserdata(L, lua_upvalueindex(PRIVATE_LUACEMBED_FUNCTION_INDEX));

    LuaCEmbed  *self = (LuaCEmbed*)lua_touserdata(L,lua_upvalueindex(PRIVATE_LUACEMBED_EMBED_OBJECT));


    //evaluating callback
    LuaCEmbedResponse *possible_return = callback(self);
    if(!possible_return){
        return PRIVATE_LUACEMBED_NO_RETURN;
    }
    return PRIVATE_LUACEMBED_NO_RETURN;

}


void LuaCEmbed_add_calback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) ){

    lua_pushlightuserdata(self->state,(void*)callback);
    lua_pushlightuserdata(self->state,(void*)self);

    lua_pushcclosure(self->state,privateLuaCEmbed_main_callback_handler,PRIVATE_LUACEMBED_TOTAL_MAIN_CALLBACK_ARGS);
    lua_setglobal(self->state, callback_name);

}


int LuaCEmbed_evaluate_string(LuaCEmbed *self, const char *str){
   int error = luaL_dostring(self->state,str);
   if(error){
       self->error_message = strdup(lua_tostring(self->state,-1));
   }
   return error;

}

int LuaCEmbed_evaluete_file(LuaCEmbed *self, const char *file){
    int error =luaL_dofile(self->state,file);
    if(error){
        self->error_message = strdup(lua_tostring(self->state,-1));
    }
    return error;

}

void LuaCEmbed_free(LuaCEmbed *self){
    lua_close(self->state); // Fecha o estado Lua
    if(self->error_message){
        free(self->error_message);
    }

    free(self);
}
