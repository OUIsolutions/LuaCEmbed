


int  LuaCEmbed_get_table_arg_type(LuaCEmbed *self, int index,const char *expresion,...){
    return -1;

}

void privateLuaEmbed_table_iteration(LuaCEmbed *self,privateLuaEmbedTableArgs *args,int index){
    lua_pushnil(self->state); // Coloca a chave nula na pilha
    int i = 0;
    long total_elements =  (long)lua_rawlen(self->state,index);


    while (lua_next(self->state, index) != 0) { // Enquanto houver elementos na tabela
        i+=1;

        // Obtém a chave e o valor atual da tabela
        //printf("index %d\n",index);
        int key_type = lua_type(self->state,-2);
        const char *possible_key = NULL;
        if(key_type == LUA_CEMBED_STRING){
            possible_key = lua_tostring(self->state,-2);
        }
        if(!privateLuaEmbedTableArgs_is_the_current_index(args,i,total_elements,possible_key)){
            lua_pop(self->state, 1);
            continue;
        }
        int value_type = lua_type(self->state,-1);

        
        lua_pop(self->state, 1); // Remove o valor, mantendo a chave na pilha para a próxima iteração
    }


}
char *  LuaCEmbed_get_table_arg_string(LuaCEmbed *self, int index,const char *code,...){

    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return  NULL;
    }
    va_list args;
    va_start(args,code);
    privateLuaEmbedTableArgs *table_args = newprivateLuaEmbedTableArgs(code,args);
    va_end(args);
    if(!table_args){
        LuaCEmbed_raise_error(self,
                              PRIVATE_LUA_CEMBED_TABLE_ARGS_ERROR,
                              self->current_function,
                              index
                              );
        return NULL;
    }

    privateLuaEmbed_table_iteration(self,table_args,index+1);



    return NULL;
}

long LuaCEmbed_get_table_arg_long(LuaCEmbed *self, int index,const char *expresion,...){

    return -1;
}

long LuaCEmbed_get_table_arg_size(LuaCEmbed *self, int index,const char *expresion,...){
return -1;
}

double LuaCEmbed_get_table_arg_double(LuaCEmbed *self, int index,const char *expresion,...){
return -1;
}

bool LuaCEmbed_get_table_arg_bool(LuaCEmbed *self, int index,const char *expresion,...){
    return false;
}
