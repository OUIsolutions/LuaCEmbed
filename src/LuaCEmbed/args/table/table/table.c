


int  LuaCEmbed_get_table_arg_type(LuaCEmbed *self, int index,const char *expresion,...){
    return -1;

}

char * privateLuaEmbed_table_iteration(LuaCEmbed *self,privateLuaEmbedTableArgs *args,int index,int started_index){
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
        int is_last_index = private_LuaCembed_is_the_last_index(args);

        if(!is_last_index && value_type !=LUA_CEMBED_TABLE){
            LuaCEmbed_raise_internal_error(self,"wrong path");
            return NULL;
        }

        //means its the last iteration
        if(!is_last_index){
            privateLuaEmbedTableArgs_next(args);
            char *result = privateLuaEmbed_table_iteration(self,args, lua_gettop(self->state),started_index);
            lua_pop(self->state, 1); // Remove o valor, mantendo a chave na pilha para a próxima iteração
            return result;
        }

        if(value_type != LUA_CEMBED_STRING){

            LuaCEmbed_raise_internal_error(self,
                   PRIVATE_LUA_CEMBED_VALUE_TABLE_WITH_WRONG_TYPE,
                   args->formated_code,
                   self->current_function,
                   LuaCembed_convert_arg_code(value_type),
                   LuaCembed_convert_arg_code(LUA_CEMBED_STRING)
            );
            return  NULL;
        }
        char *result =  (char*)lua_tostring(self->state,-1);
        lua_pop(self->state, 1); // Remove o valor, mantendo a chave na pilha para a próxima iteração
        return  result;
    }

    LuaCEmbed_raise_internal_error(
            self,
            PRIVATE_LUA_CEMBED_PATH_TABLE_NOT_EXIST,
            args->formated_code,
            self->current_function,
            started_index
    );

    return NULL;
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
        LuaCEmbed_raise_internal_error(self,
                                       PRIVATE_LUA_CEMBED_TABLE_ARGS_ERROR,
                                       self->current_function,
                                       index
        );
        return NULL;
    }

    char *result =  privateLuaEmbed_table_iteration(self,table_args,index+1,index+1);
    privateLuaEmbedTableArgs_free(table_args);
    return result;
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
