

const char * LuaCembed_convert_arg_code(int arg_code){
    if(arg_code == LUA_CEMBED_NOT_FOUND){
        return PRIVATE_LUA_CEMBED_NOT_FOUND_STRING;
    }

    if(arg_code == LUA_CEMBED_STRING){
        return PRIVATE_LUA_CEMBED_STRING_STRING;

    }
    if(arg_code == LUA_CEMBED_NUMBER){
        return PRIVATE_LUA_CEMBED_NUMBER_STRING;
    }
    if(arg_code == LUA_CEMBED_BOOL){
        return  PRIVATE_LUA_CEMBED_BOOL_STRING;
    }
    if(arg_code == LUA_CEMBED_NIL){
        return  PRIVATE_LUA_CEMBED_NIL_STRING;
    }
    if(arg_code == LUA_CEMBED_TABLE){
        return  PRIVATE_LUA_CEMBED_TABLE_STRING;
    }

    return PRIVATE_LUA_CEMBED_UNKNOW_STRING;
}

char * private_LuaCembed_format(char *expresion, va_list args){
//    long required_size = vsnprintf(NULL, 0,expresion,args);
    return NULL;
}