
LuaCEmbedTable  *privateLuaCEmbedTable_append_or_create(LuaCEmbedTable *self,const char *full_sub_name,const char *name){
    if(!self){
        return NULL;
    }
    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_prop_name(
            (privateLuaCEmbedTableArray *) self->sub_tables,
            name
    );
    if(possible){
        return possible;
    }

    LuaCEmbedTable  *creaeted = newLuaCembedTable(self->main_object,false, full_sub_name);
    creaeted->prop_name = strdup(name);

    privateLuaCEmbedTableArray_append(
            (privateLuaCEmbedTableArray*)self->sub_tables,
            creaeted
    );
    return creaeted;
}



LuaCEmbedTable  *LuaCEmbedTable_get_sub_table_auto_creating(LuaCEmbedTable *self, const char *name){
    if(!self){
        return NULL;
    }
    char *full_sub_table_name =private_LuaCembed_format(PRIVATE_LUA_CEMBED_SUB_TABLE_FORMAT, self->global_name, name);

    //checking if exist a global object
    lua_getglobal(self->main_object->state,full_sub_table_name);

    if(lua_type(self->main_object->state,-1) != LUA_CEMBED_TABLE){
        lua_newtable(self->main_object->state);
        lua_setglobal(self->main_object->state,full_sub_table_name);
    }

    //checking it its indexable by the current table
    lua_getglobal(self->main_object->state,self->global_name);
    lua_getfield(self->main_object->state,-1,name);

    if(lua_type(self->main_object->state,-1) !=LUA_CEMBED_TABLE){
        lua_getglobal(self->main_object->state,self->global_name);
        lua_pushstring(self->main_object->state,name);
        lua_getglobal(self->main_object->state,full_sub_table_name);

        lua_settable(self->main_object->state,-3);
    }
    LuaCEmbedTable  *created_table = privateLuaCEmbedTable_append_or_create(self,full_sub_table_name,name);
    free(full_sub_table_name);
    return created_table;
}

LuaCEmbedTable  *LuaCEmbedTable_new_sub_table(LuaCEmbedTable *self, const char *name){
    if(!self){
        return NULL;
    }
    char *full_sub_table_name = private_LuaCembed_format("%s%s", self->global_name, name);
    lua_newtable(self->main_object->state);
    lua_setglobal(self->main_object->state,full_sub_table_name);

    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_getglobal(self->main_object->state,full_sub_table_name);

    lua_settable(self->main_object->state,-3);

    LuaCEmbedTable *created = privateLuaCEmbedTable_append_or_create(self,full_sub_table_name,name);
    free(full_sub_table_name);
    return created;
}

void LuaCEmbedTable_set_sub_table(LuaCEmbedTable *self,const char *name,LuaCEmbedTable *sub_table){
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

    (void)privateLuaCEmbedTable_append_or_create(self,full_sub_table_name,name);
    free(full_sub_table_name);

}