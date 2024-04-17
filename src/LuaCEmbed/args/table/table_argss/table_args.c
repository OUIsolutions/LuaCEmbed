

privateLuaEmbedTableArgs * newprivateLuaEmbedTableArgs(const char *code,va_list  args){

    privateLuaEmbedTableArgs *self = (privateLuaEmbedTableArgs*) malloc(sizeof (privateLuaEmbedTableArgs));
    *self = (privateLuaEmbedTableArgs){0};


    char formated_expresion[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    vsnprintf(formated_expresion, sizeof(formated_expresion),code,args);
    self->element =  newLuaCEmbedEvaluation();

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
    return self;

}

void privateLuaEmbedTableArgs_free(privateLuaEmbedTableArgs *self){
    LuaCEmbed_free(self->element);
    free(self);
}
