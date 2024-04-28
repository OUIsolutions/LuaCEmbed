
LuaCEmbedTable  *LuaCEmbedTable_new_sub_table_appending(LuaCEmbedTable *self){

    if(!self){
        return NULL;
    }

    //equivalent of: table_sub_table = {}
    long index= LuaCEmbedTable_get_listable_size(self) +1;


    char *full_sub_table_name = private_LuaCembed_format("%s_%d", self->global_name, index);
    lua_newtable(self->main_object->state);
    lua_setglobal(self->main_object->state,full_sub_table_name);


    //equivalent of: table.sub_table = table_sub_table
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushnumber(self->main_object->state,(double)index);
    lua_getglobal(self->main_object->state,full_sub_table_name);
    lua_settable(self->main_object->state,-3);

    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_internal_index(
            (privateLuaCEmbedTableArray *) self->sub_tables,
            index
    );

    if(possible){
        free(full_sub_table_name);
        return possible;
    }

    LuaCEmbedTable  *created = newLuaCembedTable(self->main_object,false, full_sub_table_name);
    created->index = index;

    privateLuaCEmbedTableArray_append(
            (privateLuaCEmbedTableArray*)self->sub_tables,
            created
    );

    free(full_sub_table_name);
    return created;
}