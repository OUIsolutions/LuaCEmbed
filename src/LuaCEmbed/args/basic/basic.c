
int  LuaCEmbed_get_total_args(LuaCEmbed *self){
    return lua_gettop(self->state);
}

int  LuaCEmbed_get_arg_type(LuaCEmbed *self,int index){
    return  lua_type(self->state, index+1);
}

bool LuaCEmbed_has_errors(LuaCEmbed *self){

}

long LuaCEmbed_get_long_arg(LuaCEmbed *self, int index){
    if(LuaCEmbed_get_arg_type(self,index) != LUA_CEMBED_NUMBER){
        return LUA_CEMBED_NOT_FOUND;
    }
    return (long)lua_tonumber(self->state,index+1);
}


double LuaCEmbed_get_double_arg(LuaCEmbed *self, int index){
    if(LuaCEmbed_get_arg_type(self,index) != LUA_CEMBED_NUMBER){
        return LUA_CEMBED_NOT_FOUND;
    }
    return (double )lua_tonumber(self->state,index+1);
}

bool LuaCEmbed_get_bool_arg(LuaCEmbed *self, int index){
    if(LuaCEmbed_get_arg_type(self,index) != LUA_CEMBED_BOOL){
        return LUA_CEMBED_NOT_FOUND;
    }
    return (bool)lua_toboolean(self->state,index+1);
}

char * LuaCEmbed_get_str_arg(LuaCEmbed *self, int index){
    if(LuaCEmbed_get_arg_type(self,index) != LUA_CEMBED_STRING){
        return NULL;
    }
    return (char*)lua_tostring(self->state,index+1);
}

