



LuaCEmbedTable  *LuaCEmbedTable_get_sub_table_auto_creating_by_key(LuaCEmbedTable *self, const char *name){
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
    LuaCEmbedTable  *created_table = privateLuaCEmbedTable_append_or_create_by_name(self, full_sub_table_name, name);
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

    LuaCEmbedTable *created = privateLuaCEmbedTable_append_or_create_by_name(self, full_sub_table_name, name);
    free(full_sub_table_name);
    return created;
}

LuaCEmbedTable  *LuaCEmbedTable_get_sub_table_by_index_auto_creating(LuaCEmbedTable *self, int index){
    if(!self){
        return NULL;
    }
    int formatted_index = index + LUA_CEMBED_INDEX_DIF;
    char *full_sub_table_name =private_LuaCembed_format(PRIVATE_LUA_CEMBED_SUB_TABLE_FORMAT_INDEX, self->global_name, index);

    //checking if exist a global object
    lua_getglobal(self->main_object->state,full_sub_table_name);

    if(lua_type(self->main_object->state,-1) != LUA_CEMBED_TABLE){
        lua_newtable(self->main_object->state);
        lua_setglobal(self->main_object->state,full_sub_table_name);
    }


    lua_getglobal(self->main_object->state,self->global_name);
    int table_index = lua_gettop(self->main_object->state);
    long converted_index = privateLuaCEmbedTable_convert_index(self,formatted_index);
    int total = 1;


    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,table_index)){
        if(total == converted_index){
            int type = lua_type(self->main_object->state,-1);

            if(type == LUA_CEMBED_TABLE){
                lua_pop(self->main_object->state,1);
                break;
            }
            lua_getglobal(self->main_object->state,self->global_name);
            lua_pushnumber(self->main_object->state,(double)converted_index);
            lua_getglobal(self->main_object->state,full_sub_table_name);
            lua_settable(self->main_object->state,-3);

        }
        lua_pop(self->main_object->state,1);
        total+=1;
    }

    LuaCEmbedTable  *created_table = privateLuaCEmbedTable_append_or_create_by_name(self, full_sub_table_name, name);
    free(full_sub_table_name);
    return created_table;
}

void LuaCEmbedTable_set_sub_table_by_key(LuaCEmbedTable *self, const char *name, LuaCEmbedTable *sub_table){
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

}