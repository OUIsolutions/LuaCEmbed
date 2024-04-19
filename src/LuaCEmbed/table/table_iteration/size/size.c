

void privateLuaCembedTableIteration_size_callback(privateLuaCembedTableIteration *self ){
    int value_type = lua_type(self->embed_obj->state,-1);
    if(value_type != LUA_CEMBED_TABLE){

        privateLuaCEmbed_raise_error_not_jumping(
                self->embed_obj,
                PRIVATE_LUA_CEMBED_VALUE_TABLE_WITH_WRONG_TYPE,
                self->args->formated_code,
                self->location,
                LuaCembed_convert_arg_code(value_type),
                LuaCembed_convert_arg_code(LUA_CEMBED_TABLE)
        );
        return;
    }


    self->num_result = 0;

    lua_pushnil(self->embed_obj->state); // Coloca a chave nula na pilha
    while (lua_next(self->embed_obj->state, -1) != 0) { // Enquanto houver elementos na tabela
        lua_pop(self->embed_obj->state, 1);
        self->num_result+=1;
    }


}


long privateLuaCembedTableIteration_get_size(privateLuaCembedTableIteration *self,int index ){

    if(self->args->size == 0){
        int size = 0;
        lua_pushnil(self->embed_obj->state); // Coloca a chave nula na pilha
        while (lua_next(self->embed_obj->state, index) != 0) { // Enquanto houver elementos na tabela
            lua_pop(self->embed_obj->state, 1);
            size+=1;
        }
        return  size;
    }

    self->callback = privateLuaCembedTableIteration_size_callback;
    privateLuaCembedTableIteration_run_iteration(self,index);
    return (long )self->num_result;
}

