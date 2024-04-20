

int privateLuaCembedTableIteration_get_type(privateLuaCembedTableIteration *self,int index ){
    int i = 0;
    long total_elements =  0;
    //printf("total %ld\n",total_elements);

    if(private_LuaCembed_require_total(self->args)){
        lua_pushnil(self->embed_obj->state); // Coloca a chave nula na pilha
        while (lua_next(self->embed_obj->state, index) != 0) { // Enquanto houver elementos na tabela
            lua_pop(self->embed_obj->state, 1);
            total_elements+=1;
        }
    }


    lua_pushnil(self->embed_obj->state); // Coloca a chave nula na pilha

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
            lua_pop(self->embed_obj->state, 1); // Remove o valor, mantendo a chave na pilha para a próxima iteração

            return LUA_CEMBED_NOT_FOUND;
        }

        //means its the last iteration
        if(!is_last_index){
            privateLuaEmbedTableArgs_next(self->args);
            int result = privateLuaCembedTableIteration_get_type(self, lua_gettop(self->embed_obj->state));
            lua_pop(self->embed_obj->state, 1); // Remove o valor, mantendo a chave na pilha para a próxima iteração
            return result;
        }

        int result = lua_type(self->embed_obj->state,-1);
        lua_pop(self->embed_obj->state, 1); // Remove o valor, mantendo a chave na pilha para a próxima iteração
        return result;
    }

    return LUA_CEMBED_NOT_FOUND;

}
