//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../../../imports/imports.dep_define.h"
//silver_chain_scope_end





void LuaCEmbedTable_set_method(LuaCEmbedTable *self , const char *name, LuaCEmbedResponse *(*callback)(LuaCEmbedTable  *self, LuaCEmbed *args)){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID


    bool is_meta = false;

    if(strlen(name) > 3){
        if(name[0] == '_' && name[1] == '_' ){
            is_meta = true;
        }
    }
    lua_getglobal(self->main_object->state,self->global_name);

    if(is_meta){


        int found =lua_getmetatable(self->main_object->state,-1);
        if(!found){

            //equivalent of meta ={} ;setmetatable(table,meta)
            lua_getglobal(self->main_object->state,self->global_name);
            lua_newtable(self->main_object->state);
            lua_setmetatable(self->main_object->state,-2);

            lua_getglobal(self->main_object->state,self->global_name);
            lua_getmetatable(self->main_object->state,-1);
        }
    }


    lua_pushstring(self->main_object->state,name);
    //creating the clojure

    lua_pushboolean(self->main_object->state,true);//is a method

    lua_pushlightuserdata(self->main_object->state,(void*)self->main_object); //self
    lua_pushstring(self->main_object->state,name);//calback name
    lua_getglobal(self->main_object->state,self->global_name);//table
    lua_pushlightuserdata(self->main_object->state,(void*)callback);

    //add these clojure to be handled by the callbacks
    lua_pushcclosure(self->main_object->state,privateLuaCEmbed_main_callback_handler,5);
    lua_settable(self->main_object->state,-3);

    if(is_meta){
        //equivalent of meta ={} ;setmetatable(table,meta)
        lua_getglobal(self->main_object->state,self->global_name);
       lua_getmetatable(self->main_object->state,-1);
        lua_setmetatable(self->main_object->state,-2);
    }
    lua_settop(self->main_object->state, 0);

}

void  LuaCEmbedTable_set_string_prop(LuaCEmbedTable *self , const char *name, const char *value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_pushstring(self->main_object->state,value);

    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}
void  LuaCEmbedTable_set_raw_string_prop(LuaCEmbedTable *self , const char *name, const char *value,lua_Integer size){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_pushlstring(self->main_object->state,value,size);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void  LuaCEmbedTable_set_long_prop(LuaCEmbedTable *self , const char *name,lua_Integer   value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_pushinteger(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void  LuaCEmbedTable_set_double_prop(LuaCEmbedTable *self , const char *name, double  value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_pushnumber(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void  LuaCEmbedTable_set_bool_prop(LuaCEmbedTable *self , const char *name, bool value){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID

    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_pushboolean(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void  LuaCEmbedTable_set_evaluation_prop(LuaCEmbedTable *self, const char *name, const char *code, ...){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID


    va_list  args;
    va_start(args,code);
    char *buffer = private_LuaCembed_format_vaarg(code,args);
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
    lua_pushstring(self->main_object->state,name);
    lua_getglobal(self->main_object->state,PRIVATE_LUA_CEMBED_EVALUATION_NAME);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

}

void LuaCEmbedTable_copy_prop_to_global_var(LuaCEmbedTable *self,const char *prop,const char *name){
    PRIVATE_LUA_CEMBED_PROTECT_VOID
    lua_getglobal(self->main_object->state,self->global_name);
    privateLuaCEmbd_get_field_protected(self->main_object,prop);
    lua_setglobal(self->main_object->state,name);
}
void LuaCEmbedTable_set_table_prop_with_table_prop(LuaCEmbedTable *self, const char *self_prop, LuaCEmbedTable *table,const char * table_prop ){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID
    LuaCEmbed_evaluate(self->main_object,"%s['%s'] = %s['%s'];",
                       self->global_name,
                       self_prop,
                       table->global_name,
                       table_prop
    );
}

void LuaCEmbedTable_set_table_prop_with_table_index(LuaCEmbedTable *self, const char *self_prop, LuaCEmbedTable *table,const char * table_index ){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID
    LuaCEmbed_evaluate(self->main_object,"%s['%s'] = %s[%d];",
                       self->global_name,
                       self_prop,
                       table->global_name,
                       table_index
    );
}
void LuaCEmbedTable_set_table_prop_with_global(LuaCEmbedTable *self, const char *self_prop, const char *global_name){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID
    LuaCEmbed_evaluate(self->main_object,"%s['%s'] = %s;",
                       self->global_name,
                       self_prop,
                       global_name
    );
}