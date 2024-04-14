

void LuaCEmbed_set_global_string(LuaCEmbed *self, const char *name, const  char *value){
    lua_pushstring(self->state,value);
    lua_setglobal(self->state,name);
}

void LuaCEmbed_set_global_long(LuaCEmbed *self, const char *name, long value){
    lua_pushnumber(self->state,(double )value);
    lua_setglobal(self->state,name);
}

void LuaCEmbed_set_global_double(LuaCEmbed *self, const char *name, double value){
    lua_pushnumber(self->state,(double )value);
    lua_setglobal(self->state,name);
}

void LuaCEmbed_set_global_bool(LuaCEmbed *self, const char *name, bool value){
    lua_pushboolean(self->state,value);
    lua_setglobal(self->state,name);
}


