//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../../imports/imports.dep_define.h"
//silver_chain_scope_end

void  LuaCEmbedTable_append_table(LuaCEmbedTable *self, LuaCEmbedTable *table){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    long size = LuaCEmbedTable_get_listable_size(self);
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,size+1);
    lua_getglobal(self->main_object->state,table->global_name);
    lua_rawset(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void  LuaCEmbedTable_append_string(LuaCEmbedTable *self,  const char *value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    long size = LuaCEmbedTable_get_listable_size(self);
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,size+1);
    lua_pushstring(self->main_object->state,value);
    lua_rawset(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}



void  LuaCEmbedTable_append_long(LuaCEmbedTable *self,  lua_Integer value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    long size = LuaCEmbedTable_get_listable_size(self);
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,size+1);
    lua_pushinteger(self->main_object->state,value);
    lua_rawset(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void  LuaCEmbedTable_append_double(LuaCEmbedTable *self, double  value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    long size = LuaCEmbedTable_get_listable_size(self);
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,size+1);
    lua_pushnumber(self->main_object->state,value);
    lua_rawset(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void  LuaCEmbedTable_append_bool(LuaCEmbedTable *self,  bool value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    long size = LuaCEmbedTable_get_listable_size(self);
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,size+1);
    lua_pushboolean(self->main_object->state,value);
    lua_rawset(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void  LuaCEmbedTable_append_evaluation(LuaCEmbedTable *self, const char *code, ...){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    va_list  args;
    va_start(args,code);
     char *buffer = private_LuaCembed_format_vaarg(code,args);
    va_end(args);

    LuaCEmbed_evaluate(
            self->main_object,
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_EVALUATION_NAME,
            buffer
    );
    free(buffer);
    if(LuaCEmbed_has_errors(self->main_object)){
        return;
    }
    long size = LuaCEmbedTable_get_listable_size(self);
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,size+1);
    lua_getglobal(self->main_object->state,PRIVATE_LUA_CEMBED_EVALUATION_NAME);
    lua_rawset(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);
}

void  LuaCEmbedTable_append_global(LuaCEmbedTable *self,  const char *global_name){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    long size = LuaCEmbedTable_get_listable_size(self);
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,size+1);
    lua_getglobal(self->main_object->state,global_name);
    lua_rawset(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}
void  LuaCEmbedTable_append_arg(LuaCEmbedTable *self, int index){
    int  formatted_index = index + LUA_CEMBED_INDEX_DIF;

    if(formatted_index > self->main_object->total_args){
        return ;
    }

    char *formated_arg = private_LuaCembed_format(PRIVATE_LUA_CEMBED_ARGS_,self->main_object->stack_leve,formatted_index-1);
    LuaCEmbedTable_append_global(self,formated_arg);
    free(formated_arg);
}