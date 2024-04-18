


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

void privateLuaCembedTableIteration_run_iteration(privateLuaCembedTableIteration *self, int index){
    lua_pushnil(self->embed_obj->state); // Coloca a chave nula na pilha
    int i = 0;
    long total_elements =  (long)lua_rawlen(self->embed_obj->state,index);


    while (lua_next(self->embed_obj->state, index) != 0) { // Enquanto houver elementos na tabela

        // Obtém a chave e o valor atual da tabela
        //printf("index %d\n",index);
        int key_type = lua_type(self->embed_obj->state,-2);
        const char *possible_key = NULL;
        if(key_type == LUA_CEMBED_STRING){
            possible_key = lua_tostring(self->embed_obj->state,-2);
        }

        if(!privateLuaEmbedTableArgs_is_the_current_index(self->args,i,total_elements,possible_key)){
            lua_pop(self->embed_obj->state, 1);
            i+=1;

            continue;
        }
        //here it means its the correct key/index

        int value_type = lua_type(self->embed_obj->state,-1);
        int is_last_index = private_LuaCembed_is_the_last_index(self->args);

        if(!is_last_index && value_type !=LUA_CEMBED_TABLE){
            LuaCEmbed_raise_internal_error(
                    self->embed_obj,
                    PRIVATE_LUA_CEMBED_PATH_TABLE_NOT_EXIST,
                    self->args->formated_code,
                    self->location
            );
            return;
        }

        //means its the last iteration
        if(!is_last_index){
            privateLuaEmbedTableArgs_next(self->args);
            privateLuaCembedTableIteration_run_iteration(self, lua_gettop(self->embed_obj->state));
            lua_pop(self->embed_obj->state, 1); // Remove o valor, mantendo a chave na pilha para a próxima iteração
            return ;
        }

        self->callback(self);
        lua_pop(self->embed_obj->state, 1); // Remove o valor, mantendo a chave na pilha para a próxima iteração
        return ;
    }

    LuaCEmbed_raise_internal_error(
            self->embed_obj,
            PRIVATE_LUA_CEMBED_PATH_TABLE_NOT_EXIST,
            self->args->formated_code,
            self->location
    );

}

char * privateLuaCembedTableIteration_get_str(privateLuaCembedTableIteration *self,int index ){

}

void privateLuaCembedTableIteration_free(privateLuaCembedTableIteration *self){
    free(self->location);
    privateLuaEmbedTableArgs_free(self->args);
    free(self);

}