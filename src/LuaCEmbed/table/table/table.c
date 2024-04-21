

LuaCembedTable * newLuaCembedTable(LuaCEmbed *main_embed,const char *format, ...){
    LuaCembedTable  *self = (LuaCembedTable*)malloc(sizeof (LuaCembedTable));
    *self = (LuaCembedTable){0};
    self->main_object =main_embed;
    char buffer[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
    va_list  args;
    va_start(args,format);
    vsnprintf(buffer,sizeof(buffer),format,args);
    va_end(args);
    self->global_buffer = strdup(buffer);
    return self;
}


void LuaCembedTable_set_method(LuaCembedTable *self ,const char *name,LuaCEmbedResponse *(*callback)(LuaCembedTable  *self,LuaCEmbed *args)){

    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);

    //creating the clojure
    lua_pushlightuserdata(self->main_object->state,(void*)true);//is a method
    lua_pushlightuserdata(self->main_object->state,(void*)self->main_object); //self
    lua_pushlightuserdata(self->main_object->state,(void*)name);//calback name
    lua_pushlightuserdata(self->main_object->state,(void*)self);//table
    lua_pushlightuserdata(self->main_object->state,(void*)callback);

    //add these clojure to be handled by the callbacks
    lua_pushcclosure(self->main_object->state,privateLuaCEmbed_main_callback_handler,5);
    lua_settable(self->main_object->state,-3);
}

void  LuaCembedTable_set_string_prop(LuaCembedTable *self ,const char *name,const char *value){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);
    lua_pushstring(self->main_object->state,value);

    lua_settable(self->main_object->state,-3);
}

void  LuaCembedTable_set_long_prop(LuaCembedTable *self ,const char *name,long  value){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);
    lua_pushnumber(self->main_object->state,(double)value);
    lua_settable(self->main_object->state,-3);
}

void  LuaCembedTable_set_double_prop(LuaCembedTable *self ,const char *name,double  value){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);
    lua_pushnumber(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
}

void  LuaCembedTable_set_bool_prop(LuaCembedTable *self ,const char *name,bool value){
    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);
    lua_pushboolean(self->main_object->state,value);
    lua_settable(self->main_object->state,-3);
}

