
LuaCEmbedTable  *LuaCEmbedTable_new_sub_table_by_key(LuaCEmbedTable *self, const char *name){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NULL


    //equivalent of: table.sub_table = {}
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_newtable(self->main_object->state);
    lua_settable(self->main_object->state,-3);


    //equivalent of full_sub_table_name = table.sub_table
    lua_getglobal(self->main_object->state,self->global_name);
    lua_getfield(self->main_object->state,-1,name);
    char *full_sub_table_name = private_LuaCembed_format("%s_%s", self->global_name, name);
    lua_setglobal(self->main_object->state,full_sub_table_name);


    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_prop_name(
            (privateLuaCEmbedTableArray *) self->sub_tables,
            name
    );


    if(possible){
        free(full_sub_table_name);
        return possible;
    }

    LuaCEmbedTable  *created = private_newLuaCembedTable(self->main_object, full_sub_table_name);
    created->prop_name = strdup(name);

    privateLuaCEmbedTableArray_append(
            (privateLuaCEmbedTableArray*)self->sub_tables,
            created
    );

    free(full_sub_table_name);
    return created;
}


LuaCEmbedTable  *LuaCEmbedTable_get_sub_table_by_key(LuaCEmbedTable *self, const char *name){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NULL


    lua_getglobal(self->main_object->state,self->global_name);
    lua_getfield(self->main_object->state,-1,name);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_TABLE)){
        return NULL;
    }
    //equivalent of full_sub_table_name = table.sub_table
    lua_getglobal(self->main_object->state,self->global_name);
    lua_getfield(self->main_object->state,-1,name);
    char *full_sub_table_name = private_LuaCembed_format("%s_%s", self->global_name, name);
    lua_setglobal(self->main_object->state,full_sub_table_name);


    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_prop_name(
            (privateLuaCEmbedTableArray *) self->sub_tables,
            name
    );


    if(possible){
        free(full_sub_table_name);
        return possible;
    }

    LuaCEmbedTable  *created = private_newLuaCembedTable(self->main_object, full_sub_table_name);
    created->prop_name = strdup(name);

    privateLuaCEmbedTableArray_append(
            (privateLuaCEmbedTableArray*)self->sub_tables,
            created
    );

    free(full_sub_table_name);
    return created;

}



void LuaCEmbedTable_set_sub_table_prop(LuaCEmbedTable *self, const char *name, LuaCEmbedTable *sub_table){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    //equivalent of  table.name = sub_table;
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_getglobal(self->main_object->state,sub_table->global_name);
    lua_settable(self->main_object->state,-3);


    //equivalent of full_sub_table_name = table.sub_table
    lua_getglobal(self->main_object->state,self->global_name);
    lua_getfield(self->main_object->state,-1,name);
    char *full_sub_table_name = private_LuaCembed_format("%s_%s", self->global_name, name);
    lua_setglobal(self->main_object->state,full_sub_table_name);
    free(full_sub_table_name);

}