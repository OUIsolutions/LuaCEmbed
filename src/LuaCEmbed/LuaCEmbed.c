

LuaCEmbed * newLuaCEmbed(){
    LuaCEmbed  *self = (LuaCEmbed*) malloc(sizeof (LuaCEmbed));
    *self = (LuaCEmbed){0};
    self->state = luaL_newstate();
    return self;
}
void LuaCEmbed_interpret_string(LuaCEmbed *self,const char *str){
    luaL_dostring(self->state,str);
}


void LuaCEmbed_interpret_file(LuaCEmbed *self,const char *file){
    luaL_dofile(self->state,file);
}


void LuaCEmbed_free(LuaCEmbed *self){

    lua_close(self->state); // Fecha o estado Lua
    free(self);
}
