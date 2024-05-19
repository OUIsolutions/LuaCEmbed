

void LuaCEmbed_set_long_lib_prop(LuaCEmbed *self,const char *name,int64_t value){
    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME);
    lua_pushvalue(self->state,-1);
    //set the function name
    lua_pushstring(self->state,name);
    lua_pushinteger(self->state,value);
    lua_settable(self->state,-3);
}

void LuaCEmbed_set_double_lib_prop(LuaCEmbed *self,const char *name,double value){
    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME);
    lua_pushvalue(self->state,-1);
    //set the function name
    lua_pushstring(self->state,name);
    lua_pushnumber(self->state,value);
    lua_settable(self->state,-3);
}

void LuaCEmbed_set_bool_lib_prop(LuaCEmbed *self,const char *name,bool value){
    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME);
    lua_pushvalue(self->state,-1);
    //set the function name
    lua_pushstring(self->state,name);
    lua_pushboolean(self->state,value);
    lua_settable(self->state,-3);
}

void LuaCEmbed_set_string_lib_prop(LuaCEmbed *self,const char *name,const char * value){
    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME);
    lua_pushvalue(self->state,-1);
    //set the function name
    lua_pushstring(self->state,name);
    lua_pushstring(self->state,value);
    lua_settable(self->state,-3);
}

void LuaCEmbed_set_table_lib_prop(LuaCEmbed *self,const char *name,LuaCEmbedTable *value){
    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME);
    lua_pushvalue(self->state,-1);
    lua_pushstring(self->state,name);
    lua_getglobal(self->state,value->global_name);
    lua_settable(self->state,-3);
}
