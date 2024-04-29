



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


void privateLuaCEmbedTable_free(LuaCEmbedTable *self){
    if(!self){
        return ;
    }
    free(self->global_name);

    if(self->prop_name){
        free(self->prop_name);
    }

    privateLuaCEmbedTableArray_free((privateLuaCEmbedTableArray*)self->sub_tables);
    free(self);
}
