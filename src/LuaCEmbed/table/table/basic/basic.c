



LuaCEmbedTable * newLuaCembedTable(LuaCEmbed *main_embed, const char *format, ...){
    LuaCEmbedTable  *self = (LuaCEmbedTable*)malloc(sizeof (LuaCEmbedTable));
    *self = (LuaCEmbedTable){0};
    self->main_object =main_embed;
    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    va_list  args;
    va_start(args,format);
    vsnprintf(buffer,sizeof(buffer),format,args);
    va_end(args);
    self->global_buffer = strdup(buffer);
    self->sub_tables = (void*)newprivateLuaCEmbedTableArray();
    return self;
}


void privateLuaCEmbedTable_free(LuaCEmbedTable *self){
    free(self->global_buffer);
    if(self->prop_name){
        free(self->prop_name);
    }
    privateLuaCEmbedTableArray_free((privateLuaCEmbedTableArray*)self->sub_tables);
    free(self);
}
