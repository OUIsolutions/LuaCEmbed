

LuaCEmbed * newLuaCEmbed(){
    LuaCEmbed  *self = (LuaCEmbed*) malloc(sizeof (LuaCEmbed));
    *self = (LuaCEmbed){0};
    self->state = luaL_newstate();
    return self;
}


int privateLuaCEmbed_main_callback_handler(lua_State  *L){

    LuaCEmbedReturn* (*callback)(LuaCEmbed *args);
    callback = lua_touserdata(L,PRIVATE_LUACEMBED_FUNCTION_INDEX);

    LuaCEmbed  *self = (LuaCEmbed*)lua_touserdata(L,PRIVATE_LUACEMBED_EMBED_OBJECT);


    //evaluating callback
    LuaCEmbedReturn *possible_return = callback(self);
    if(!possible_return){
        return PRIVATE_LUACEMBED_NO_RETURN;
    }
    return PRIVATE_LUACEMBED_NO_RETURN;

}

void LuaCEmbed_push_function(LuaCEmbed *self,const char *callback_name,LuaCEmbedReturn* (*callback)(LuaCEmbed *args) ){
    lua_pushlightuserdata(self->state,(void*)callback);
    lua_pushcclosure(self->state,privateLuaCEmbed_main_callback_handler,1);
    lua_setglobal(self->state, callback_name);
}


void LuaCEmbed_evaluate_string(LuaCEmbed *self, const char *str){
    luaL_dostring(self->state,str);
}

void LuaCEmbed_evaluete_file(LuaCEmbed *self, const char *file){
    luaL_dofile(self->state,file);
}

void LuaCEmbed_free(LuaCEmbed *self){
    lua_close(self->state); // Fecha o estado Lua
    free(self);
}
