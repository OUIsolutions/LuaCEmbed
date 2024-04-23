
void  LuaCEmbedTable_append_string(LuaCEmbedTable *self,  const char *value){

    long size = LuaCEmbedTable_get_size(self);
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,size+1);
    lua_pushstring(self->main_object->state,value);

    lua_rawset(self->main_object->state,-3);
}
