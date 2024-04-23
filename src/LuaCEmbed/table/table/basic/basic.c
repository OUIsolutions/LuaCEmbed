



LuaCEmbedTable * newLuaCembedTable(LuaCEmbed *main_embed, bool always_recreate, const char *format, ...){
    LuaCEmbedTable  *self = (LuaCEmbedTable*)malloc(sizeof (LuaCEmbedTable));
    *self = (LuaCEmbedTable){0};
    self->main_object =main_embed;

    char name[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    va_list  args;
    va_start(args,format);
    vsnprintf(name, sizeof(name), format, args);
    va_end(args);

    char meta_name[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    sprintf(meta_name,PRIVATE_LUA_CEMBED_METANAME,name);

    self->meta_name = strdup(meta_name);
    self->global_name = strdup(name);

    self->sub_tables = (void*)newprivateLuaCEmbedTableArray();


    //create the tables if not exist
    lua_getglobal(main_embed->state,name);
    if(lua_type(main_embed->state,-1) != LUA_CEMBED_TABLE || always_recreate){
        lua_newtable(main_embed->state);
        lua_setglobal(main_embed->state,name);
    }

    lua_getglobal(main_embed->state,meta_name);
    if(lua_type(main_embed->state,-1) != LUA_CEMBED_TABLE || always_recreate){
        lua_newtable(main_embed->state);
        lua_setglobal(main_embed->state,meta_name);
    }

    return self;
}


void privateLuaCEmbedTable_free(LuaCEmbedTable *self){
    free(self->global_name);
    free(self->meta_name);

    if(self->prop_name){
        free(self->prop_name);
    }

    privateLuaCEmbedTableArray_free((privateLuaCEmbedTableArray*)self->sub_tables);
    free(self);
}
