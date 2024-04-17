


int  LuaCEmbed_get_table_arg_type(LuaCEmbed *self, int index,const char *expresion,...){


}

char *  LuaCEmbed_get_table_arg_string(LuaCEmbed *self, int index,const char *code,...){

    va_list args;
    va_start(args,code);
    char formated_expresion[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    vsnprintf(formated_expresion, sizeof(formated_expresion),code,args);
    va_end(args);

    LuaCEmbed  * testage = newLuaCEmbedEvaluation();
    LuaCEmbed_evaluate_string_no_return(testage,"TABLE_ARGS  = {%s}",formated_expresion);

    if(LuaCEmbed_has_errors(testage)){
        LuaCEmbed_free(testage);
        LuaCEmbed_raise_error(self,
                              "arguments of function %s at index %d its not a valid lua code",
                                self->current_function,
                                index
        );
        return NULL;
    }

    long size = LuaCEmbed_get_evaluation_table_size(testage,"TABLE_ARGS");
    if(LuaCEmbed_has_errors(testage)){
        LuaCEmbed_free(testage);
        LuaCEmbed_raise_error(self,
                              "arguments of function %s at index %d its not a valid table",
                              self->current_function,
                              index
        );
        return NULL;
    }
    printf("size: %ld\n",size);

    LuaCEmbed_free(testage);


}

long LuaCEmbed_get_table_arg_long(LuaCEmbed *self, int index,const char *expresion,...){


}

long LuaCEmbed_get_table_arg_size(LuaCEmbed *self, int index,const char *expresion,...){

}

double LuaCEmbed_get_table_arg_double(LuaCEmbed *self, int index,const char *expresion,...){

}

bool LuaCEmbed_get_table_arg_bool(LuaCEmbed *self, int index,const char *expresion,...){

}
