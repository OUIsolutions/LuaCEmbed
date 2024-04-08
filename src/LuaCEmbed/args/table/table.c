
int  LuaCEmbed_get_table_arg_type(LuaCEmbed *self, int index,const char *expresion,...){
va_list args;
va_start(args, expresion);
privateLuaCEmbed_evaluate_arg_expresion(self,index,expresion,args);
va_end(args);
return lua_type(self->state, -1);
}

char *  LuaCEmbed_get_table_arg_string(LuaCEmbed *self, int index,const char *expresion,...){
    va_list args;
    va_start(args, expresion);
    privateLuaCEmbed_evaluate_arg_expresion(self,index,expresion,args);
    va_end(args);

    return (char*)lua_tostring(self->state, -1);


}