

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
    if(arg_code == LUA_CEMBED_FUNCTION){
        return PRIVATE_LUA_CEMBED_FUNCTION_STRING;
    }

    return PRIVATE_LUA_CEMBED_UNKNOW_STRING;
}

char * private_LuaCembed_format(const char *expresion, va_list args){

    va_list args_copy;
    va_copy(args_copy, args);
    long required_size = vsnprintf(NULL, 0,expresion,args_copy);
    va_end(args_copy);

    char *buffer = (char*)malloc(sizeof(char) * required_size + 1);
    vsnprintf(buffer, required_size,expresion,args);
    return buffer;
}