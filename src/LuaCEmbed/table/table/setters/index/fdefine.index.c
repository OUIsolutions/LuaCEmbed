//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../../../imports/imports.dep_define.h"
//silver_chain_scope_end



void  LuaCEmbedTable_set_string_by_index(LuaCEmbedTable *self, lua_Integer index, const char *value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    char *possible_key = LuaCembedTable_get_key_by_index(self,index);
    if(possible_key){
        LuaCEmbedTable_set_string_prop(self,possible_key,value);
        return;
    }
    long formatted_index = index + LUA_CEMBED_INDEX_DIF;
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushnumber(self->main_object->state,(double)formatted_index);
    lua_pushstring(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);
}


void  LuaCEmbedTable_set_raw_string_by_index(LuaCEmbedTable *self, lua_Integer index, const char *value,lua_Integer size){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    char *possible_key = LuaCembedTable_get_key_by_index(self,index);
    if(possible_key){
        LuaCEmbedTable_set_string_prop(self,possible_key,value);
        return;
    }
    long formatted_index = index + LUA_CEMBED_INDEX_DIF;
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushnumber(self->main_object->state,(double)formatted_index);
    lua_pushlstring(self->main_object->state,value,size);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);
}



void  LuaCEmbedTable_set_long_by_index(LuaCEmbedTable *self, lua_Integer  index, lua_Integer  value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    char *possible_key = LuaCembedTable_get_key_by_index(self,index);
    if(possible_key){
        LuaCEmbedTable_set_long_prop(self,possible_key,value);
        return;
    }
    lua_Integer formatted_index = index + LUA_CEMBED_INDEX_DIF;
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,formatted_index);
    lua_pushinteger(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void  LuaCEmbedTable_set_double_by_index(LuaCEmbedTable *self, lua_Integer index, double  value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    char *possible_key = LuaCembedTable_get_key_by_index(self,index);
    if(possible_key){
        LuaCEmbedTable_set_double_prop(self,possible_key,value);
        return;
    }

    long formatted_index = index + LUA_CEMBED_INDEX_DIF;
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,formatted_index);
    lua_pushnumber(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void  LuaCEmbedTable_set_bool_by_index(LuaCEmbedTable *self, lua_Integer index, bool value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    char *possible_key = LuaCembedTable_get_key_by_index(self,index);
    if(possible_key){
        LuaCEmbedTable_set_bool_prop(self,possible_key,value);
        return;
    }

    long formatted_index = index + LUA_CEMBED_INDEX_DIF;
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,formatted_index);
    lua_pushboolean(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}


void  LuaCEmbedTable_set_evaluation_by_index(LuaCEmbedTable *self, lua_Integer index, const char *code, ...){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    long formatted_index = index + LUA_CEMBED_INDEX_DIF;
    va_list  args;
    va_start(args,code);
    char *  buffer = private_LuaCembed_format_vaarg(code,args);
    va_end(args);

    LuaCEmbed_evaluate(self->main_object,
                       PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
                       PRIVATE_LUA_CEMBED_EVALUATION_NAME,
                       buffer
    );
    free(buffer);
    if(LuaCEmbed_has_errors(self->main_object)){
        return;
    }
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,formatted_index);
    lua_getglobal(self->main_object->state,PRIVATE_LUA_CEMBED_EVALUATION_NAME);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void LuaCEmbedTable_copy_index_to_global_var(LuaCEmbedTable *self,lua_Integer index, const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_VOID
 
    long formatted_index = index + LUA_CEMBED_INDEX_DIF;
    long converted_index = privateLuaCEmbedTable_convert_index(self,formatted_index);
 
    lua_getglobal(self->main_object->state,self->global_name);
    int table_index = lua_gettop(self->main_object->state);

    int total = 1;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,table_index)){
        if(total == converted_index){
            lua_setglobal(self->main_object->state,name);
            lua_pop(self->main_object->state,1);
            PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
            return;
        }

        lua_pop(self->main_object->state,1);
        total+=1;

    }
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
}
void LuaCEmbedTable_set_table_index_with_table_prop(LuaCEmbedTable *self, lua_Integer self_index, LuaCEmbedTable *table,const char * table_prop ){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID
    LuaCEmbed_evaluate(self->main_object,"%s[%d] = %s['%s']",
                       self->global_name,
                       self_index,
                       table->global_name,
                       table_prop
    );
}

void LuaCEmbedTable_set_table_index_with_table_index(LuaCEmbedTable *self, lua_Integer self_index, LuaCEmbedTable *table,const char * table_index ){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID
    LuaCEmbed_evaluate(self->main_object,"%s[%d] = %s[%d]",
                       self->global_name,
                       self_index,
                       table->global_name,
                       table_index
    );
}
