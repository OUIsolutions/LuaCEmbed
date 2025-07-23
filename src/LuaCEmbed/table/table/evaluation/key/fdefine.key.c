//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../../../imports/imports.dep_define.h"
//silver_chain_scope_end


LuaCEmbedTable *  LuaCEmbedTable_run_prop_function(LuaCEmbedTable *self,const char *prop,LuaCEmbedTable *args_to_call,int total_returns){

    char *callback_global_name = private_LuaCembed_format(PRIVATE_LUA_CEMBED_GENERAL_TEMP,self->main_object->stack_leve);
    LuaCEmbedTable_copy_prop_to_global_var(self,prop,callback_global_name);
    int total_args = private_lua_cEmbed_unpack(args_to_call,callback_global_name);
    free(callback_global_name);

    if(lua_pcall(self->main_object->state,total_args,total_returns,0)){

        privateLuaCEmbed_raise_error_not_jumping(self->main_object, lua_tostring(self->main_object->state,-1));

        PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
        return  NULL;
    }


    for(int i = 0; i < total_returns; i++){
        char *formatted = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MULTIRETURN_,self->main_object->stack_leve,i);
        int position = (i +1) * -1;
        lua_pushvalue(self->main_object->state,position);
        lua_setglobal(self->main_object->state,formatted);
        free(formatted);
    }



    LuaCEmbedTable  *result = LuaCembed_new_anonymous_table(self->main_object);
    for(int i = 0; i < total_returns; i++){
        lua_getglobal(self->main_object->state,result->global_name);
        lua_pushinteger(self->main_object->state,i+1);
        char *formatted = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MULTIRETURN_,self->main_object->stack_leve,i);
        lua_getglobal(self->main_object->state,formatted);
        lua_settable(self->main_object->state,-3);
        free(formatted);
    }
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return result;    
}