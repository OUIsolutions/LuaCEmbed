



void LuaCEmbedTable_set_method(LuaCEmbedTable *self , const char *name, LuaCEmbedResponse *(*callback)(LuaCEmbedTable  *self, LuaCEmbed *args)){

    bool its_meta_method = false;


    if(strlen(name) > 2){
        if (name[0] == '_' && name[1] == '_'){
            its_meta_method = true;
        }
    }
    bool its_normal_method = !its_meta_method;

    if(its_normal_method){
        lua_getglobal(self->main_object->state,self->global_name);
    }

    if(its_meta_method){
        lua_getglobal(self->main_object->state,self->meta_name);
    }

    lua_pushstring(self->main_object->state,name);

    //creating the clojure
    lua_pushboolean(self->main_object->state,true);//is a method
    lua_pushlightuserdata(self->main_object->state,(void*)self->main_object); //self
    lua_pushstring(self->main_object->state,name);//calback name
    lua_getglobal(self->main_object->state,self->prop_name);//table
    lua_pushlightuserdata(self->main_object->state,(void*)callback);

    //add these clojure to be handled by the callbacks
    lua_pushcclosure(self->main_object->state,privateLuaCEmbed_main_callback_handler,5);
    lua_settable(self->main_object->state,-3);

    if(its_meta_method){
        lua_getglobal(self->main_object->state,self->global_name);
        lua_pushvalue(self->main_object->state,-2);

        lua_setmetatable(self->main_object->state,-2);
    }

}

void  LuaCEmbedTable_set_string_prop(LuaCEmbedTable *self , const char *name, const char *value){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_pushstring(self->main_object->state,value);

    lua_settable(self->main_object->state,-3);
}

void  LuaCEmbedTable_set_long_prop(LuaCEmbedTable *self , const char *name, long  value){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_pushnumber(self->main_object->state,(double)value);
    lua_settable(self->main_object->state,-3);
}

void  LuaCEmbedTable_set_double_prop(LuaCEmbedTable *self , const char *name, double  value){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_pushnumber(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
}

void  LuaCEmbedTable_set_bool_prop(LuaCEmbedTable *self , const char *name, bool value){
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_pushboolean(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
}
void  LuaCEmbedTable_set_evaluation_prop(LuaCEmbedTable *self, const char *name, const char *code, ...){

    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    va_list  args;
    va_start(args,code);
    vsnprintf(buffer,sizeof(buffer),code,args);
    va_end(args);

    LuaCEmbed_evaluate_string_no_return(self->main_object,
            PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
            PRIVATE_LUA_CEMBED_EVALUATION_NAME,
            buffer
    );
    if(LuaCEmbed_has_errors(self->main_object)){
        return;
    }
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushstring(self->main_object->state,name);
    lua_getglobal(self->main_object->state,PRIVATE_LUA_CEMBED_EVALUATION_NAME);
    lua_settable(self->main_object->state,-3);
}