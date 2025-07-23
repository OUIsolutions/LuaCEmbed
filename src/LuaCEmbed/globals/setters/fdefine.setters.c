//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.dep_define.h"
//silver_chain_scope_end



void LuaCEmbed_set_global_string(LuaCEmbed *self, const char *name, const  char *value){
    PRIVATE_LUA_CEMBED_PROTECT_VOID

    lua_pushstring(self->state,value);
    lua_setglobal(self->state,name);
}
void LuaCEmbed_set_global_raw_string(LuaCEmbed *self, const char *name, const  char *value,long size){
    PRIVATE_LUA_CEMBED_PROTECT_VOID

    lua_pushlstring(self->state,value,size);
    lua_setglobal(self->state,name);
}


void LuaCEmbed_set_global_long(LuaCEmbed *self, const char *name, lua_Integer  value){
    PRIVATE_LUA_CEMBED_PROTECT_VOID

    lua_pushinteger(self->state,value);
    lua_setglobal(self->state,name);
}

void LuaCEmbed_set_global_double(LuaCEmbed *self, const char *name, double value){
    PRIVATE_LUA_CEMBED_PROTECT_VOID

    lua_pushnumber(self->state,(double )value);
    lua_setglobal(self->state,name);
}

void LuaCEmbed_set_global_bool(LuaCEmbed *self, const char *name, bool value){
    PRIVATE_LUA_CEMBED_PROTECT_VOID
    lua_pushboolean(self->state,value);
    lua_setglobal(self->state,name);
}


void LuaCEmbed_set_global_table(LuaCEmbed *self, const char *name, LuaCEmbedTable *table){
    PRIVATE_LUA_CEMBED_PROTECT_VOID

    lua_getglobal(self->state,table->global_name);
    lua_setglobal(self->state,name);
}

void LuaCEmbed_set_global_table_prop(LuaCEmbed *self, const char *name, LuaCEmbedTable *table,const char *prop){
    PRIVATE_LUA_CEMBED_PROTECT_VOID
    lua_getglobal(self->state,table->global_name);
    privateLuaCEmbd_get_field_protected(self,prop);
    lua_setglobal(self->state,name);
}

void LuaCEmbed_set_global_table_prop(LuaCEmbed *self, const char *name, LuaCEmbedTable *table,const char *prop){
    PRIVATE_LUA_CEMBED_PROTECT_VOID
    lua_getglobal(self->state,table->global_name);
    privateLuaCEmbd_get_field_protected(self,prop);
    lua_setglobal(self->state,name);
}
void LuaCEmbed_set_global_table_index(LuaCEmbed *self, const char *name, LuaCEmbedTable *table,lua_Integer index){
    PRIVATE_LUA_CEMBED_PROTECT_VOID
 
    long formatted_index = index + LUA_CEMBED_INDEX_DIF;
    long converted_index = privateLuaCEmbedTable_convert_index(table,formatted_index);
 

    lua_getglobal(self->state,table->global_name);
    int table_index = lua_gettop(self->state);
    int total = 1;
    lua_pushnil(self->state);
    while(lua_next(self->state,table_index)){
        if(total == converted_index){
            lua_setglobal(self->state,name);
            lua_pop(self->state,1);
            PRIVATE_LUA_CEMBED_CLEAR_STACK
            return;
        }
        lua_pop(self->state,1);
        total+=1;

    }
    PRIVATE_LUA_CEMBED_CLEAR_STACK
}
