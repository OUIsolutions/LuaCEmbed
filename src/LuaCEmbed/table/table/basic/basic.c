



LuaCEmbedTable * private_newLuaCembedTable(LuaCEmbed *main_embed, const char *format, ...){

    LuaCEmbedTable  *self = (LuaCEmbedTable*)malloc(sizeof (LuaCEmbedTable));
    *self = (LuaCEmbedTable){0};
    self->main_object =main_embed;

    va_list  args;
    va_start(args,format);
    self->global_name = private_LuaCembed_format_vaarg(format,args);
    va_end(args);

    self->sub_tables = (void*)newprivateLuaCEmbedTableArray();

    return self;
}

 int  private_lua_cEmbed_unpack(LuaCEmbedTable *self){
    long size = LuaCEmbedTable_get_listable_size(self);

    for(int i = 0; i < size; i++){

        int type = LuaCEmbedTable_get_type_by_index(self,i);
        if(type == LUA_CEMBED_NUMBER){
            double value = LuaCEmbedTable_get_double_by_index(self,i);
            lua_pushnumber(self->main_object->state,value);
        }

        if(type == LUA_CEMBED_BOOL){
            bool value = LuaCEmbedTable_get_bool_by_index(self,i);
            lua_pushboolean(self->main_object->state,value);
        }
        if(type == LUA_CEMBED_STRING){
            char*  value = LuaCEmbedTable_get_string_by_index(self,i);
            lua_pushstring(self->main_object->state,value);
        }

        if(type == LUA_CEMBED_TABLE){
            LuaCEmbedTable * sub = LuaCEmbedTable_get_sub_table_by_index(self,i);
            lua_getglobal(self->main_object->state,sub->global_name);
        }

        char *formated = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MULTIRETURN,i);
        lua_setglobal(self->main_object->state,formated);
        free(formated);
    }

    for(int i = 0; i < size; i++){
        char *formated = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MULTIRETURN,i);
        lua_getglobal(self->main_object->state,formated);
        free(formated);
    }


    return (int)size;
}

void privateLuaCEmbedTable_free(LuaCEmbedTable *self){


    free(self->global_name);

    if(self->prop_name){
        free(self->prop_name);
    }

    privateLuaCEmbedTableArray_free((privateLuaCEmbedTableArray*)self->sub_tables);
    free(self);
}
