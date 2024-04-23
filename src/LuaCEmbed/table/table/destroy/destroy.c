

void LuaCembedTable_destroy_prop(LuaCEmbedTable *self, const char *name){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_pushnil(self->main_object->state);
    lua_settable(self->main_object->state,-3);
}
void LuaCEmbedTable_destroy_by_index(LuaCEmbedTable *self, long index){
/*
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushnumber(self->main_object->state,(double)(converted_index));
    lua_pushnil(self->main_object->state);
    lua_settable(self->main_object->state,-3);
  */
    lua_getglobal(self->main_object->state,self->global_name);

    long converted_index = privateLuaCEmbedTable_convert_index(self,index+1);
    int table_index = lua_gettop(self->main_object->state);
    int total = 0;

    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,table_index)){
        if(total >= converted_index){

            lua_getglobal(self->main_object->state,self->global_name);
            lua_pushnumber(self->main_object->state,(double)(total));
            lua_pushvalue(self->main_object->state,-3);
            lua_settable(self->main_object->state,-3);
            lua_pop(self->main_object->state,1);

        }
        lua_pop(self->main_object->state,1);
        total+=1;

    }





}