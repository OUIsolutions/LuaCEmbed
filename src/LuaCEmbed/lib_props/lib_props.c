

void LuaCEmbed_set_long_lib_prop(LuaCEmbed *self,const char *name,long long value){
    char *main_lib_table = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME__,privata_LuaCEmbed_get_total_runing_libs(self));

    lua_getglobal(self->state,main_lib_table);
    lua_pushvalue(self->state,-1);
    //set the function name
    lua_pushstring(self->state,name);
    lua_pushinteger(self->state,value);
    lua_settable(self->state,-3);
    free(main_lib_table);
}

void LuaCEmbed_set_double_lib_prop(LuaCEmbed *self,const char *name,double value){
    char *main_lib_table = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME__,privata_LuaCEmbed_get_total_runing_libs(self));

    lua_getglobal(self->state,main_lib_table);
    lua_pushvalue(self->state,-1);
    //set the function name
    lua_pushstring(self->state,name);
    lua_pushnumber(self->state,value);
    lua_settable(self->state,-3);
    free(main_lib_table);

}

void LuaCEmbed_set_bool_lib_prop(LuaCEmbed *self,const char *name,bool value){
    char *main_lib_table = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME__,privata_LuaCEmbed_get_total_runing_libs(self));

    lua_getglobal(self->state,main_lib_table);
    lua_pushvalue(self->state,-1);
    //set the function name
    lua_pushstring(self->state,name);
    lua_pushboolean(self->state,value);
    lua_settable(self->state,-3);
    free(main_lib_table);

}

void LuaCEmbed_set_string_lib_prop(LuaCEmbed *self,const char *name,const char * value){
    char *main_lib_table = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME__,privata_LuaCEmbed_get_total_runing_libs(self));

    lua_getglobal(self->state,main_lib_table);
    lua_pushvalue(self->state,-1);
    //set the function name
    lua_pushstring(self->state,name);
    lua_pushstring(self->state,value);
    lua_settable(self->state,-3);
    free(main_lib_table);

}

void LuaCEmbed_set_table_lib_prop(LuaCEmbed *self,const char *name,LuaCEmbedTable *value){
    char *main_lib_table = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME__,privata_LuaCEmbed_get_total_runing_libs(self));

    lua_getglobal(self->state,main_lib_table);
    lua_pushvalue(self->state,-1);
    lua_pushstring(self->state,name);
    lua_getglobal(self->state,value->global_name);
    lua_settable(self->state,-3);
    free(main_lib_table);

}
