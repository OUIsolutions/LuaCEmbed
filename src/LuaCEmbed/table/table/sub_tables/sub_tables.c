


LuaCEmbedTable  *LuaCEmbedTable_get_sub_table(LuaCEmbedTable *self, const char *name){

    char full_sub_table_name[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(full_sub_table_name,PRIVATE_LUA_CEMBED_SUB_TABLE_FORMAT,self->global_buffer,name);

    //checking if exist a global object
    lua_getglobal(self->main_object->state,full_sub_table_name);
    if(lua_type(self->main_object->state,-1) != LUA_CEMBED_TABLE){
        lua_newtable(self->main_object->state);
        lua_setglobal(self->main_object->state,full_sub_table_name);
    }

    //checking it its indexable by the current table
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_getfield(self->main_object->state,-1,name);

    if(lua_type(self->main_object->state,-1) !=LUA_CEMBED_TABLE){
        lua_getglobal(self->main_object->state,self->global_buffer);
        lua_pushstring(self->main_object->state,name);
        lua_getglobal(self->main_object->state,full_sub_table_name);

        lua_settable(self->main_object->state,-3);
    }


    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_name(
            (privateLuaCEmbedTableArray*)self->sub_tables,
            name
    );
    if(possible){
        return possible;
    }

    LuaCEmbedTable  *creaeted = newLuaCembedTable(self->main_object,full_sub_table_name);
    creaeted->prop_name = strdup(name);

    privateLuaCEmbedTableArray_append(
            (privateLuaCEmbedTableArray*)self->sub_tables,
            creaeted
    );
    return creaeted;
}
