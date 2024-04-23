

void LuaCembedTable_destroy_prop(LuaCEmbedTable *self, const char *name){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_pushnil(self->main_object->state);
    lua_settable(self->main_object->state,-3);
}
