


privateLuaCembedTableIteration * nwqprivateLuaCembedTableIteration(LuaCEmbed *embed_obj){
    privateLuaCembedTableIteration *self = (privateLuaCembedTableIteration*) malloc(sizeof (privateLuaCembedTableIteration));
    *self = (privateLuaCembedTableIteration){0};
    self->embed_obj = embed_obj;
    return self;
}

int  privateLuaCembedTableIteration_set_args_code(privateLuaCembedTableIteration *self,const char *code,va_list args){
    privateLuaEmbedTableArgs *table_args = newprivateLuaEmbedTableArgs(code,args);
    if(!table_args){
        LuaCEmbed_raise_internal_error(self->embed_obj,
                                       PRIVATE_LUA_CEMBED_TABLE_ARGS_ERROR,
                                       self->embed_obj->current_function,
                                       index
        );

        return LUA_CEMBED_GENERIC_ERROR;
    }
    return LUA_CEMBED_OK;
}

void  privateLuaCembedTableIteration_set_location(privateLuaCembedTableIteration *self,const char *format,...){

    va_list args;
    va_start(args,format);
    char formated_expresion[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    vsnprintf(formated_expresion, sizeof(formated_expresion),format,args);
    va_end(args);

    self->location  = strdup(formated_expresion);

}


char * privateLuaCembedTableIteration_get_str(privateLuaCembedTableIteration *self,int index ){

}

void privateLuaCembedTableIteration_free(privateLuaCembedTableIteration *self){
    free(self->location);
    privateLuaEmbedTableArgs_free(self->args);
    free(self);

}