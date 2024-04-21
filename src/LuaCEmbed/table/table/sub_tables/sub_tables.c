
LuaCEmbedTable  *privateLuaCEmbedTable_append_or_create(LuaCEmbedTable *self,const char *full_sub_name,const char *name){

    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_prop_name(
            (privateLuaCEmbedTableArray *) self->sub_tables,
            name
    );
    if(possible){
        return possible;
    }

    LuaCEmbedTable  *creaeted = newLuaCembedTable(self->main_object,full_sub_name);
    creaeted->prop_name = strdup(name);

    privateLuaCEmbedTableArray_append(
            (privateLuaCEmbedTableArray*)self->sub_tables,
            creaeted
    );
    return creaeted;
}



LuaCEmbedTable  *LuaCEmbedTable_get_sub_table_auto_creating(LuaCEmbedTable *self, const char *name){

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

    return privateLuaCEmbedTable_append_or_create(self,full_sub_table_name,name);
}

LuaCEmbedTable  *LuaCEmbedTable_new_sub_table(LuaCEmbedTable *self, const char *name){
    char full_sub_table_name[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(full_sub_table_name,PRIVATE_LUA_CEMBED_SUB_TABLE_FORMAT,self->global_buffer,name);


    lua_newtable(self->main_object->state);
    lua_setglobal(self->main_object->state,full_sub_table_name);


    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);
    lua_getglobal(self->main_object->state,full_sub_table_name);

    lua_settable(self->main_object->state,-3);

    return privateLuaCEmbedTable_append_or_create(self,full_sub_table_name,name);

}

void LuaCEmbedTable_set_sub_table(LuaCEmbedTable *self,const char *name,LuaCEmbedTable *sub_table){

    char full_sub_table_name[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(full_sub_table_name,PRIVATE_LUA_CEMBED_SUB_TABLE_FORMAT,self->global_buffer,name);


    //assagnin these prop as the same as sub table
    lua_getglobal(self->main_object->state,sub_table->global_buffer);
    lua_setglobal(self->main_object->state,full_sub_table_name);


    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);
    lua_getglobal(self->main_object->state,full_sub_table_name);

    lua_settable(self->main_object->state,-3);

    (void)privateLuaCEmbedTable_append_or_create(self,full_sub_table_name,name);

}