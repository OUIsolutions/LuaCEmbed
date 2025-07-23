//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../../../imports/imports.dep_define.h"
//silver_chain_scope_end


lua_Integer  LuaCEmbedTable_run_prop_function(LuaCEmbedTable *self,const char *prop,LuaCEmbedTable *args_to_call,int total_returns){

    /*

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
    */
   return 0;
}