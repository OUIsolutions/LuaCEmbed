


int  LuaCEmbed_get_table_arg_type(LuaCEmbed *self, int index,const char *expresion,...){
    return -1;

}

char *  LuaCEmbed_get_table_arg_string(LuaCEmbed *self, int index,const char *code,...){

    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return  NULL;
    }

    va_list args;
    va_start(args,code);
    char formated_expresion[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    vsnprintf(formated_expresion, sizeof(formated_expresion),code,args);
    va_end(args);

    LuaCEmbed  * testage = newLuaCEmbedEvaluation();
    LuaCEmbed_evaluate_string_no_return(testage,"TABLE_ARGS  = %s",formated_expresion);

    if(LuaCEmbed_has_errors(testage)){
        LuaCEmbed_free(testage);
        LuaCEmbed_raise_error(self,
                              "arguments of function %s at index %d its not a valid lua code",
                                self->current_function,
                                index
        );
        return NULL;
    }

   // long size = LuaCEmbed_get_evaluation_table_size(testage,"TABLE_ARGS");
    if(LuaCEmbed_has_errors(testage)){
        LuaCEmbed_free(testage);
        LuaCEmbed_raise_error(self,
                              "arguments of function %s at index %d its not a valid table",
                              self->current_function,
                              index
        );
        return NULL;
    }

    
    lua_pushnil(self->state); // Coloca a chave nula na pilha
    index = index+1;
    while (lua_next(self->state, index) != 0) { // Enquanto houver elementos na tabela
        // Obtém a chave e o valor atual da tabela
        //printf("index %d\n",index);
        int key_type = lua_type(self->state,-2);
        int value_type = lua_type(self->state,-1);
        char *converted_key = NULL;
        char buffer[200]= {0};
        if(key_type == LUA_CEMBED_STRING){
            converted_key = (char*)lua_tostring(self->state,-2);
        }

        if(key_type == LUA_CEMBED_NUMBER){
            int key = lua_tonumber(self->state,-2);
            sprintf(buffer,"%d",key);
            converted_key = buffer;
        }

        if(value_type == LUA_CEMBED_STRING || value_type == LUA_CEMBED_NUMBER ){
            printf("%s:%s\n",converted_key, lua_tostring(self->state,-1));
        }

        if(value_type == LUA_CEMBED_BOOL){
            printf("%s:%s\n",converted_key, lua_toboolean(self->state,-1) ? "true":"false");
        }
        if(value_type == LUA_CEMBED_TABLE){
            printf("%s:(index:%d)\n",converted_key, lua_gettop(self->state));

        }
        lua_pop(self->state, 1); // Remove o valor, mantendo a chave na pilha para a próxima iteração
    }


    LuaCEmbed_free(testage);

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
