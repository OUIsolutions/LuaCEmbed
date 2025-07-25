//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../../../imports/imports.dep_define.h"
//silver_chain_scope_end


int  LuaCEmbedTable_get_type_prop(LuaCEmbedTable *self, const char *name){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM
    lua_getglobal(self->main_object->state,self->global_name);
    privateLuaCEmbd_get_field_protected(self->main_object,name);
    return lua_type(self->main_object->state,-1);

}

char*  LuaCembedTable_get_string_prop(LuaCEmbedTable *self , const char *name){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NULL



    lua_getglobal(self->main_object->state,self->global_name);
    privateLuaCEmbd_get_field_protected(self->main_object,name);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_STRING)){
        return NULL;
    }

    char *value = (char*)lua_tostring(self->main_object->state,-1);
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return value;
}

char*  LuaCembedTable_get_raw_string_prop(LuaCEmbedTable *self, const char *name,lua_Integer *size){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NULL

    lua_getglobal(self->main_object->state,self->global_name);
    privateLuaCEmbd_get_field_protected(self->main_object,name);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_STRING)){
        return NULL;
    }

    char *value = (char*)lua_tolstring(self->main_object->state,-1,(size_t*)size);
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return value;
}

lua_Integer LuaCembedTable_get_long_prop(LuaCEmbedTable *self , const char *name){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM

    lua_getglobal(self->main_object->state,self->global_name);
    privateLuaCEmbd_get_field_protected(self->main_object,name);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    lua_Integer value = lua_tointeger(self->main_object->state,-1);
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return value;
}

double  LuaCembedTable_get_double_prop(LuaCEmbedTable *self , const char *name){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM



    lua_getglobal(self->main_object->state,self->global_name);
    privateLuaCEmbd_get_field_protected(self->main_object,name);

    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_NUMBER)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    double value  = (double )lua_tonumber(self->main_object->state,-1);
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return value;
}

bool  LuaCembedTable_get_bool_prop(LuaCEmbedTable *self , const char *name){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_BOOL



    lua_getglobal(self->main_object->state,self->global_name);
    privateLuaCEmbd_get_field_protected(self->main_object,name);
    if(privateLuaCEmbedTable_ensure_type_with_key(self, name, LUA_CEMBED_BOOL)){
        return LUA_CEMBED_GENERIC_ERROR;
    }
    bool value =  lua_toboolean(self->main_object->state,-1);
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return value;
}
