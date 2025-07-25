//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.dep_define.h"
//silver_chain_scope_end


lua_Integer  privateLuaCEmbed_put_arg_on_top(LuaCEmbed *self, lua_Integer index){
    PRIVATE_LUA_CEMBED_PROTECT_NUM
    int  formatted_index = index + LUA_CEMBED_INDEX_DIF;

    if(formatted_index > self->total_args){
        privateLuaCEmbed_raise_error_not_jumping(self,PRIVATE_LUA_CEMBED_ARG_NOT_PROVIDED,formatted_index,self->current_function);
        return LUA_CEMBED_GENERIC_ERROR;
     }

    char *formated_arg = private_LuaCembed_format(PRIVATE_LUA_CEMBED_ARGS_,self->stack_leve,formatted_index-1);
    lua_getglobal(self->state,formated_arg);
    int type = lua_type(self->state,-1);
    if(type == LUA_CEMBED_NOT_FOUND || type == LUA_CEMBED_NIL){
        privateLuaCEmbed_raise_error_not_jumping(self,PRIVATE_LUA_CEMBED_ARG_NOT_PROVIDED,formatted_index,self->current_function);
        free(formated_arg);
        return LUA_CEMBED_GENERIC_ERROR;
    }

    free(formated_arg);
    return LUA_OK;
}

lua_Integer  LuaCEmbed_get_total_args(LuaCEmbed *self){
    return self->total_args;
}



lua_Integer  LuaCEmbed_get_arg_type(LuaCEmbed *self,lua_Integer index){

    int  formatted_index = index + LUA_CEMBED_INDEX_DIF;

    if(formatted_index > self->total_args){
        return LUA_CEMBED_NIL;
    }

    char *formated_arg = private_LuaCembed_format(PRIVATE_LUA_CEMBED_ARGS_,self->stack_leve,formatted_index-1);
    lua_getglobal(self->state,formated_arg);
    int type = lua_type(self->state, -1);
    free(formated_arg);
    PRIVATE_LUA_CEMBED_CLEAR_STACK
    return type;
}


lua_Integer LuaCEmbed_get_long_arg(LuaCEmbed *self, lua_Integer index){
    PRIVATE_LUA_CEMBED_PROTECT_NUM


    if(privateLuaCEmbed_put_arg_on_top(self,index)){
        PRIVATE_LUA_CEMBED_CLEAR_STACK
       return (lua_Integer )LUA_CEMBED_NOT_FOUND;
    }

    if(private_LuaCEmbed_ensure_top_stack_arg_type(self,index,LUA_CEMBED_NUMBER)){
        PRIVATE_LUA_CEMBED_CLEAR_STACK
        return (lua_Integer )LUA_CEMBED_NOT_FOUND;
    }

    lua_Integer result =  lua_tointeger(self->state,-1);
    PRIVATE_LUA_CEMBED_CLEAR_STACK
    return result;
}


double LuaCEmbed_get_double_arg(LuaCEmbed *self, lua_Integer index){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    if(privateLuaCEmbed_put_arg_on_top(self,index)){
        PRIVATE_LUA_CEMBED_CLEAR_STACK
       return LUA_CEMBED_NOT_FOUND;
    }
    if(private_LuaCEmbed_ensure_top_stack_arg_type(self,index,LUA_CEMBED_NUMBER)){
        PRIVATE_LUA_CEMBED_CLEAR_STACK
        return LUA_CEMBED_NOT_FOUND;
    }
    double result = lua_tonumber(self->state,-1);
    PRIVATE_LUA_CEMBED_CLEAR_STACK
    return result;
}

bool LuaCEmbed_get_bool_arg(LuaCEmbed *self, lua_Integer index){
    PRIVATE_LUA_CEMBED_PROTECT_BOOL

    if(privateLuaCEmbed_put_arg_on_top(self,index)){
        PRIVATE_LUA_CEMBED_CLEAR_STACK
       return LUA_CEMBED_NOT_FOUND;
    }
    if(private_LuaCEmbed_ensure_top_stack_arg_type(self,index,LUA_CEMBED_BOOL)){
    PRIVATE_LUA_CEMBED_CLEAR_STACK
        return LUA_CEMBED_NOT_FOUND;
    }
    bool result = lua_toboolean(self->state,-1);
    PRIVATE_LUA_CEMBED_CLEAR_STACK
    return result;
}


char * LuaCEmbed_get_str_arg(LuaCEmbed *self, lua_Integer index){
    PRIVATE_LUA_CEMBED_PROTECT_NULL
    PRIVATE_LUA_CEMBED_CLEAR_STACK

    if(privateLuaCEmbed_put_arg_on_top(self,index)){
        PRIVATE_LUA_CEMBED_CLEAR_STACK
        return NULL;
    }

    if(private_LuaCEmbed_ensure_top_stack_arg_type(self,index,LUA_CEMBED_STRING)){
        return NULL;
    }
    char *result =  (char*)lua_tostring(self->state,-1);
    PRIVATE_LUA_CEMBED_CLEAR_STACK
    return result;
}
char * LuaCEmbed_get_raw_str_arg(LuaCEmbed *self,lua_Integer *size, lua_Integer index){
    PRIVATE_LUA_CEMBED_PROTECT_NULL
    PRIVATE_LUA_CEMBED_CLEAR_STACK

    if(privateLuaCEmbed_put_arg_on_top(self,index)){
        PRIVATE_LUA_CEMBED_CLEAR_STACK
       return NULL;
    }

    if(private_LuaCEmbed_ensure_top_stack_arg_type(self,index,LUA_CEMBED_STRING)){
        return NULL;
    }
    char *result =  (char*)lua_tolstring(self->state,-1,(size_t*)size);
    PRIVATE_LUA_CEMBED_CLEAR_STACK
    return result;
}

LuaCEmbedTable  * LuaCEmbed_get_arg_table(LuaCEmbed *self,lua_Integer index){
    PRIVATE_LUA_CEMBED_PROTECT_NULL

    if(privateLuaCEmbed_put_arg_on_top(self,index)){
        PRIVATE_LUA_CEMBED_CLEAR_STACK
       return NULL;
    }

    if(private_LuaCEmbed_ensure_top_stack_arg_type(self,index,LUA_CEMBED_TABLE)){
        return NULL;
    }

    int formatted_index = index + LUA_CEMBED_INDEX_DIF;
    char *formated_arg = private_LuaCembed_format(PRIVATE_LUA_CEMBED_ARGS_,self->stack_leve,formatted_index-1);
    LuaCEmbedTable  *created = LuaCembed_get_global_table(self,formated_arg);
    free(formated_arg);
    PRIVATE_LUA_CEMBED_CLEAR_STACK
    return created;

}

LuaCEmbedTable* LuaCEmbed_run_args_lambda(LuaCEmbed *self, lua_Integer index, LuaCEmbedTable *args_to_call, lua_Integer total_returns){

    int  formatted_index = index + LUA_CEMBED_INDEX_DIF;
    char *formatted_arg = private_LuaCembed_format(PRIVATE_LUA_CEMBED_ARGS_,self->stack_leve,formatted_index-1);

    if(privateLuaCEmbed_put_arg_on_top(self,index)){
        PRIVATE_LUA_CEMBED_CLEAR_STACK
        free(formatted_arg);
       return NULL;
    }

    if(private_LuaCEmbed_ensure_top_stack_arg_type(self,index,LUA_CEMBED_FUNCTION)){
        free(formatted_arg);
        PRIVATE_LUA_CEMBED_CLEAR_STACK
        return  NULL;
    }

    int total_args = private_lua_cEmbed_unpack(args_to_call,formatted_arg);
    if(lua_pcall(self->state,total_args,total_returns,0)){

        privateLuaCEmbed_raise_error_not_jumping(self, lua_tostring(self->state,-1));
        free(formatted_arg);

        PRIVATE_LUA_CEMBED_CLEAR_STACK
        return  NULL;
    }


    for(int i = 0; i < total_returns; i++){
        char *formatted = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MULTIRETURN_,self->stack_leve,i);
        int position = (i +1) * -1;
        lua_pushvalue(self->state,position);
        lua_setglobal(self->state,formatted);
        free(formatted);
    }



    LuaCEmbedTable  *result = LuaCembed_new_anonymous_table(self);
    for(int i = 0; i < total_returns; i++){
        lua_getglobal(self->state,result->global_name);
        lua_pushinteger(self->state,i+1);
        char *formatted = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MULTIRETURN_,self->stack_leve,i);
        lua_getglobal(self->state,formatted);
        lua_settable(self->state,-3);
        free(formatted);
    }
    free(formatted_arg);
    PRIVATE_LUA_CEMBED_CLEAR_STACK
    return result;

}
LuaCEmbedTable  * LuaCEmbed_transform_args_in_table(LuaCEmbed *self){
    LuaCEmbedTable  *result = LuaCembed_new_anonymous_table(self);
    for(int i = 0; i < self->total_args; i++){
        LuaCEmbedTable_append_arg(result,i);
    }
    return result;
}