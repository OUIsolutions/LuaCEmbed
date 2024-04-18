


int  LuaCEmbed_get_table_arg_type(LuaCEmbed *self, int index,const char *expresion,...){
    return -1;

}


char *  LuaCEmbed_get_table_arg_string(LuaCEmbed *self, int index,const char *code,...){

    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return  NULL;
    }

    privateLuaCembedTableIteration * iterator = nwqprivateLuaCembedTableIteration(self);
    va_list  args;
    va_start(args,code);
    int args_result = privateLuaCembedTableIteration_set_args_code(iterator,code,args);
    va_end(args);

    if(args_result){
        privateLuaCembedTableIteration_free(iterator);
        return NULL;
    }
    privateLuaCembedTableIteration_set_location(iterator,PRIVATE_LUA_CEMBED_ARG_LOCATION,self->current_function,index+1);

    char *result = privateLuaCembedTableIteration_get_str(iterator,index+1);
    privateLuaCembedTableIteration_free(iterator);
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
