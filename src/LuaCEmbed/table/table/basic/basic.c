



LuaCEmbedTable * newLuaCembedTable(LuaCEmbed *main_embed, bool always_recreate, const char *format, ...){
    LuaCEmbedTable  *self = (LuaCEmbedTable*)malloc(sizeof (LuaCEmbedTable));
    *self = (LuaCEmbedTable){0};
    self->main_object =main_embed;

    va_list  args;
    va_start(args,format);
    self->global_name = private_LuaCembed_format_vaarg(format,args);
    va_end(args);

    self->meta_name = private_LuaCembed_format(PRIVATE_LUA_CEMBED_METANAME,self->global_name);

    self->sub_tables = (void*)newprivateLuaCEmbedTableArray();


    //create the tables if not exist
    lua_getglobal(main_embed->state,self->global_name);
    if(lua_type(main_embed->state,-1) != LUA_CEMBED_TABLE || always_recreate){
        lua_newtable(main_embed->state);
        lua_setglobal(main_embed->state,self->global_name);
    }

    lua_getglobal(main_embed->state,self->meta_name);
    if(lua_type(main_embed->state,-1) != LUA_CEMBED_TABLE || always_recreate){
        lua_newtable(main_embed->state);
        lua_setglobal(main_embed->state,self->meta_name
        );
    }

    return self;
}


void privateLuaCEmbedTable_free(LuaCEmbedTable *self){
    if(!self){
        return ;
    }
    free(self->global_name);
    free(self->meta_name);

    if(self->prop_name){
        free(self->prop_name);
    }

    privateLuaCEmbedTableArray_free((privateLuaCEmbedTableArray*)self->sub_tables);
    free(self);
}
