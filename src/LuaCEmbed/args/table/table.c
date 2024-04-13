
int  LuaCEmbed_get_table_arg_type(LuaCEmbed *self, int index,const char *expresion,...){

    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return LUA_CEMBED_NOT_FOUND;
    }

    va_list args;
va_start(args, expresion);
int error_code = privateLuaCEmbed_evaluate_arg_expresion(self,index,expresion,args);
va_end(args);
if(error_code){
    return  error_code;
}

return lua_type(self->state, -1);

}

char *  LuaCEmbed_get_table_arg_string(LuaCEmbed *self, int index,const char *expresion,...){

    if(LuaCEmbed_ensure_arg_type(self,index,LUA_CEMBED_TABLE)){
        return NULL;
    }

    va_list args;
    va_start(args, expresion);
    int error_code = privateLuaCEmbed_evaluate_arg_expresion(self,index,expresion,args);
    va_end(args);
    if(error_code){
        return NULL;
    }

    return (char*)lua_tostring(self->state, -1);


}