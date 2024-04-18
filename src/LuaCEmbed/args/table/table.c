


int  LuaCEmbed_get_table_arg_type(LuaCEmbed *self, int index,const char *expresion,...){
    return -1;

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
