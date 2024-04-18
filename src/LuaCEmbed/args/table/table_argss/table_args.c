
privateLuaEmbedTableArgs * newprivateLuaEmbedTableArgs(const char *code,va_list  args){

    privateLuaEmbedTableArgs *self = (privateLuaEmbedTableArgs*) malloc(sizeof (privateLuaEmbedTableArgs));
    *self = (privateLuaEmbedTableArgs){0};


    char formated_expresion[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    vsnprintf(formated_expresion, sizeof(formated_expresion),code,args);
    self->element =  newLuaCEmbedEvaluation();
    self->formated_code = strdup(formated_expresion);

    LuaCEmbed_evaluate_string_no_return(
            self->element,
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_TABLE_ARGS_INTERNAL_NAME,
             formated_expresion
   );

    if(LuaCEmbed_has_errors(self->element)){
        privateLuaEmbedTableArgs_free(self);

        return NULL;
    }


    self->size = (int)LuaCEmbed_get_evaluation_table_size(self->element,PRIVATE_LUA_CEMBED_TABLE_ARGS_INTERNAL_NAME);
    if(LuaCEmbed_has_errors(self->element)){
        privateLuaEmbedTableArgs_free(self);

        return NULL;
    }

    for(int i = 0; i < self->size; i++){
        int type = LuaCEmbed_get_evaluation_type(
                    self->element,
                    PRIVATE_LUA_CEMBED_TABLE_INDEXATION,
                    PRIVATE_LUA_CEMBED_TABLE_ARGS_INTERNAL_NAME,
                    i+1
        );


        if(type != LUA_CEMBED_STRING && type != LUA_CEMBED_NUMBER){
            privateLuaEmbedTableArgs_free(self);
            return NULL;
        }

    }
    privateLuaEmbedTableArgs_next(self);
    return self;

}
void privateLuaEmbedTableArgs_next(privateLuaEmbedTableArgs *self){
    self->current_type = LuaCEmbed_get_evaluation_type(
            self->element,
            PRIVATE_LUA_CEMBED_TABLE_INDEXATION,
            PRIVATE_LUA_CEMBED_TABLE_ARGS_INTERNAL_NAME,
            self->index+1
    );
    if(self->current_type == LUA_CEMBED_NUMBER){
        self->current_value = LuaCEmbed_get_evaluation_long(
                self->element,
                PRIVATE_LUA_CEMBED_TABLE_INDEXATION,
                PRIVATE_LUA_CEMBED_TABLE_ARGS_INTERNAL_NAME
                );
    }
    if(self->current_type == LUA_CEMBED_STRING){
        self->current_value_str = LuaCEmbed_get_evaluation_string(
                self->element,
                PRIVATE_LUA_CEMBED_TABLE_INDEXATION,
                PRIVATE_LUA_CEMBED_TABLE_ARGS_INTERNAL_NAME
        );
    }
    self->index+=1;

}
bool private_LuaCembed_is_the_last_index(privateLuaEmbedTableArgs *self){
    if(self->index == self->size){
        return  true;
    }
    return  false;
}


bool privateLuaEmbedTableArgs_is_the_current_index(
        privateLuaEmbedTableArgs *self,
        long current_iteration,
        long total_elements,
        const char *possible_key
){
    if(self->current_type == LUA_CEMBED_STRING){
        if(!possible_key){
            return  false;
        }
        if(strcmp(possible_key,self->current_value_str) == 0){
            return  true;
        }
        return false;
    }

    if(self->current_type == LUA_CEMBED_NUMBER){
        long converted = self->current_value;
        if(self->current_value <0){
            converted = total_elements + self->current_value;
        }
        if(converted == current_iteration){
            return true;
        }
    }

    return false;
}
void privateLuaEmbedTableArgs_free(privateLuaEmbedTableArgs *self){
    LuaCEmbed_free(self->element);
    free(self->formated_code);
    free(self);
}
