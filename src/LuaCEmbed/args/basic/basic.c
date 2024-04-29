
int  LuaCEmbed_get_total_args(LuaCEmbed *self){
    return self->total_args;
}


int  LuaCEmbed_get_arg_type(LuaCEmbed *self,int index){
    int formatted_index = index + LUA_CEMBED_INDEX_DIF;
    return  lua_type(self->state, formatted_index);
}


long LuaCEmbed_get_long_arg(LuaCEmbed *self, int index){
    int formatted_index = index + LUA_CEMBED_INDEX_DIF;

    if(LuaCEmbed_ensure_arg_type(self,formatted_index,LUA_CEMBED_NUMBER)){
        return (long )LUA_CEMBED_NOT_FOUND;
    }
    return (long)lua_tonumber(self->state,formatted_index);
}


double LuaCEmbed_get_double_arg(LuaCEmbed *self, int index){
    int formatted_index = index + LUA_CEMBED_INDEX_DIF;

    if(LuaCEmbed_ensure_arg_type(self,formatted_index,LUA_CEMBED_NUMBER)){
        return (double )LUA_CEMBED_NOT_FOUND;
    }

    return (double )lua_tonumber(self->state,formatted_index);
}

bool LuaCEmbed_get_bool_arg(LuaCEmbed *self, int index){
    int formatted_index = index + LUA_CEMBED_INDEX_DIF;

    if(LuaCEmbed_ensure_arg_type(self,formatted_index,LUA_CEMBED_BOOL)){
        return false;
    }
    return (bool)lua_toboolean(self->state,formatted_index);
}

char * LuaCEmbed_get_str_arg(LuaCEmbed *self, int index){
    int formatted_index = index + LUA_CEMBED_INDEX_DIF;

    if(LuaCEmbed_ensure_arg_type(self,formatted_index,LUA_CEMBED_STRING)){
        return NULL;
    }
    return (char*)lua_tostring(self->state,formatted_index);
}

LuaCEmbedTable  * LuaCEmbed_get_arg_table(LuaCEmbed *self,int index){
    int formatted_index = index + LUA_CEMBED_INDEX_DIF;
    if(LuaCEmbed_ensure_arg_type(self,formatted_index,LUA_CEMBED_TABLE)){
        return NULL;
    }

    char *full_table_name = private_LuaCembed_format(PRIVATE_LUA_CEMBE_SUB_ARG_TABLE,self->current_function,formatted_index);

    lua_pushvalue(self->state,formatted_index);
    lua_setglobal(self->state,full_table_name);


    privateLuaCEmbedTableArray *target = (privateLuaCEmbedTableArray*)self->global_tables;

    if(self->current_function){
        target =  (privateLuaCEmbedTableArray*)self->func_tables;
    }


    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_prop_name(target,full_table_name);
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