
LuaCEmbedTable  *LuaCEmbedTable_new_sub_table_by_key(LuaCEmbedTable *self, const char *name){

    if(!self){
        return NULL;
    }

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

    LuaCEmbedTable  *created = newLuaCembedTable(self->main_object,false, full_sub_table_name);
    created->prop_name = strdup(name);

    privateLuaCEmbedTableArray_append(
            (privateLuaCEmbedTableArray*)self->sub_tables,
            created
    );

    free(full_sub_table_name);
    return created;
}


LuaCEmbedTable  *LuaCEmbedTable_get_sub_table_auto_creating_by_key(LuaCEmbedTable *self, const char *name){
    if(!self){
        return NULL;
    }

    lua_getglobal(self->main_object->state,self->global_name);
    lua_getfield(self->main_object->state,-1,name);
    bool sub_table_not_exist = lua_type(self->main_object->state,-1) !=LUA_CEMBED_TABLE;

    if(sub_table_not_exist){
        //equivalent of: table.sub_table = {}
        lua_getglobal(self->main_object->state,self->global_name);
        lua_pushstring(self->main_object->state,name);
        lua_newtable(self->main_object->state);
        lua_settable(self->main_object->state,-3);
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

    LuaCEmbedTable  *created = newLuaCembedTable(self->main_object,false, full_sub_table_name);
    created->prop_name = strdup(name);

    privateLuaCEmbedTableArray_append(
            (privateLuaCEmbedTableArray*)self->sub_tables,
            created
    );

    free(full_sub_table_name);
    return created;

}



void LuaCEmbedTable_set_sub_table_by_key(LuaCEmbedTable *self, const char *name, LuaCEmbedTable *sub_table){
    /*
    if(!self){
        return ;
    }
    char *full_sub_table_name =private_LuaCembed_format(PRIVATE_LUA_CEMBED_SUB_TABLE_FORMAT, self->global_name, name);


    //assagnin these prop as the same as sub table
    lua_getglobal(self->main_object->state,sub_table->global_name);
    lua_setglobal(self->main_object->state,full_sub_table_name);


    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_getglobal(self->main_object->state,full_sub_table_name);

    lua_settable(self->main_object->state,-3);

    (void) privateLuaCEmbedTable_append_or_create_by_name(self, full_sub_table_name, name);
    free(full_sub_table_name);
*/
}