
int  LuaCEmbed_get_total_args(LuaCEmbed *self){
    return self->total_args;
}


int  LuaCEmbed_get_arg_type(LuaCEmbed *self,int index){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    int formatted_index = index + LUA_CEMBED_INDEX_DIF;
    return  lua_type(self->state, formatted_index);
}


long LuaCEmbed_get_long_arg(LuaCEmbed *self, int index){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    int formatted_index = index + LUA_CEMBED_INDEX_DIF;

    if(LuaCEmbed_ensure_arg_type(self,formatted_index,LUA_CEMBED_NUMBER)){
        return (long )LUA_CEMBED_NOT_FOUND;
    }
    return (long)lua_tonumber(self->state,formatted_index);
}


double LuaCEmbed_get_double_arg(LuaCEmbed *self, int index){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    int formatted_index = index + LUA_CEMBED_INDEX_DIF;

    if(LuaCEmbed_ensure_arg_type(self,formatted_index,LUA_CEMBED_NUMBER)){
        return (double )LUA_CEMBED_NOT_FOUND;
    }

    return (double )lua_tonumber(self->state,formatted_index);
}

bool LuaCEmbed_get_bool_arg(LuaCEmbed *self, int index){
    PRIVATE_LUA_CEMBED_PROTECT_BOOL
    int formatted_index = index + LUA_CEMBED_INDEX_DIF;

    if(LuaCEmbed_ensure_arg_type(self,formatted_index,LUA_CEMBED_BOOL)){
        return false;
    }
    return (bool)lua_toboolean(self->state,formatted_index);
}

char * LuaCEmbed_get_str_arg(LuaCEmbed *self, int index){
    PRIVATE_LUA_CEMBED_PROTECT_NULL
    int formatted_index = index + LUA_CEMBED_INDEX_DIF;

    if(LuaCEmbed_ensure_arg_type(self,formatted_index,LUA_CEMBED_STRING)){
        return NULL;
    }
    return (char*)lua_tostring(self->state,formatted_index);
}

LuaCEmbedTable  * LuaCEmbed_get_arg_table(LuaCEmbed *self,int index){
    PRIVATE_LUA_CEMBED_PROTECT_NULL

    int formatted_index = index + LUA_CEMBED_INDEX_DIF;
    if(LuaCEmbed_ensure_arg_type(self,formatted_index,LUA_CEMBED_TABLE)){
        return NULL;
    }

    char *full_table_name = private_LuaCembed_format(PRIVATE_LUA_CEMBE_SUB_ARG_TABLE,self->current_function,formatted_index);

    lua_pushvalue(self->state,formatted_index);
    lua_setglobal(self->state,full_table_name);


    privateLuaCEmbedTableArray *target = (privateLuaCEmbedTableArray*)privateLuaCEmbed_get_current_table_array(self);


    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_global_name(target,full_table_name);
    if(possible){
        free(full_table_name);
        return possible;
    }

    LuaCEmbedTable  *creaeted = private_newLuaCembedTable(self, "%s", full_table_name);

    privateLuaCEmbedTableArray_append(
            target,
            creaeted
    );
    free(full_table_name);
    return creaeted;
}

LuaCEmbedTable* LuaCEmbed_run_callback_lambda(LuaCEmbed *self, int index, LuaCEmbedTable *args_to_call,int total_returns){
    PRIVATE_LUA_CEMBED_PROTECT_NULL

    int formatted_index = index + LUA_CEMBED_INDEX_DIF;
    if(LuaCEmbed_ensure_arg_type(self,formatted_index,LUA_CEMBED_FUNCTION)){
        return NULL;
    }
    int total_args = 0;
    if(args_to_call){

       total_args = private_lua_cEmbed_unpack(args_to_call);
    }

    if(lua_pcall(self->state,total_args,total_returns,0)){
        //LuaCEmbed_r
    }

}
