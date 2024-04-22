



void LuaCEmbedTable_set_method(LuaCEmbedTable *self , const char *name, LuaCEmbedResponse *(*callback)(LuaCEmbedTable  *self, LuaCEmbed *args)){

    bool its_meta_method = false;

    /*
    if(strlen(name) > 2){
        if (name[0] == '_' && name[1] == '_'){
            its_meta_method = true;
        }
    }
     */
    bool its_normal_method = !its_meta_method;

    if(its_normal_method){
        lua_getglobal(self->main_object->state,self->global_buffer);
    }

    if(its_meta_method){
        luaL_newmetatable(self->main_object->state,"a");
    }

    lua_pushstring(self->main_object->state,name);

    //creating the clojure
    lua_pushboolean(self->main_object->state,true);//is a method
    lua_pushlightuserdata(self->main_object->state,(void*)self->main_object); //self
    lua_pushstring(self->main_object->state,name);//calback name
    lua_pushstring(self->main_object->state,self->prop_name);//table
    lua_pushlightuserdata(self->main_object->state,(void*)callback);

    //add these clojure to be handled by the callbacks
    lua_pushcclosure(self->main_object->state,privateLuaCEmbed_main_callback_handler,5);
    lua_settable(self->main_object->state,-3);

    if(its_meta_method){
        lua_getglobal(self->main_object->state,self->global_buffer);
        luaL_setmetatable(self->main_object->state,"a");
    }

}

void  LuaCEmbedTable_set_string_prop(LuaCEmbedTable *self , const char *name, const char *value){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);
    lua_pushstring(self->main_object->state,value);

    lua_settable(self->main_object->state,-3);
}

void  LuaCEmbedTable_set_long_prop(LuaCEmbedTable *self , const char *name, long  value){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);
    lua_pushnumber(self->main_object->state,(double)value);
    lua_settable(self->main_object->state,-3);
}

void  LuaCEmbedTable_set_double_prop(LuaCEmbedTable *self , const char *name, double  value){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);
    lua_pushnumber(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
}

void  LuaCEmbedTable_set_bool_prop(LuaCEmbedTable *self , const char *name, bool value){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);
    lua_pushboolean(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
}
