

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

int  privateLuaCembedTable_handle_methods(lua_State  *L){

    LuaCEmbedResponse* (*callback)(LuaCembedTable *self,LuaCEmbed *args);
    callback = (LuaCEmbedResponse* (*)(LuaCembedTable *self,LuaCEmbed *args))lua_touserdata(L, lua_upvalueindex(1));
    LuaCEmbed  *main_object = (LuaCEmbed*)lua_touserdata(L, lua_upvalueindex(2));
    LuaCembedTable  *self =  (LuaCembedTable *)lua_touserdata(L, lua_upvalueindex(3));
    char *method_name =  (char*)lua_touserdata(L,lua_upvalueindex(4));
    main_object->current_function = method_name;


    //evaluating callback
    LuaCEmbedResponse *possible_return = callback(self,main_object);
    main_object->current_function = NULL;
    if(!possible_return){
        return PRIVATE_LUACEMBED_NO_RETURN;
    }

    if(possible_return->type == PRIVATE_LUA_CEMBED_LONG_RESPONSE){
        lua_pushinteger(L, (int)possible_return->num_val);
        private_LuaCEmbedResponse_free(possible_return);
        return PRIVATE_LUACEMBED_ONE_RETURN;
    }

    if(possible_return->type == PRIVATE_LUA_CEMBED_DOUBLE_RESPONSE){
        lua_pushnumber(L, possible_return->num_val);
        private_LuaCEmbedResponse_free(possible_return);
        return PRIVATE_LUACEMBED_ONE_RETURN;
    }

    if(possible_return->type == PRIVATE_LUA_CEMBED_STRING_RESPONSE){
        lua_pushstring(L, possible_return->string_val);
        private_LuaCEmbedResponse_free(possible_return);
        return PRIVATE_LUACEMBED_ONE_RETURN;
    }

    if(possible_return->type == PRIVATE_LUA_CEMBED_DOUBLE_RESPONSE){

        lua_pushboolean(L, (bool)possible_return->num_val);
        private_LuaCEmbedResponse_free(possible_return);
        return PRIVATE_LUACEMBED_ONE_RETURN;
    }

    if(possible_return->type == PRIVATE_LUA_CEMBED_TABLE_RESPONSE){

        char formated_function[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
        snprintf(
                formated_function, sizeof(formated_function),
                PRIVATE_LUA_CEMBED_FUNCTION_TABLE_RESPONSE_EVALUATION_CODE,
                PRIVATE_LUA_CEMBED_EVALUATION_NAME,
                possible_return->string_val
        );

        int error_code = LuaCEmbed_evaluate_string_no_return(main_object, formated_function);

        if(error_code){
            private_LuaCEmbedResponse_free(possible_return);
            return PRIVATE_LUACEMBED_NO_RETURN;
        }

        lua_getglobal(main_object->state, PRIVATE_LUA_CEMBED_EVALUATION_NAME);
        const int TOTAL_ARGS =0;
        const int TOTAL_RETURNS =1;
        //calling the function
        lua_pcall(main_object->state, TOTAL_ARGS, TOTAL_RETURNS, 0);
        //printf("v:%s\n", lua_tostring(self->state,-1));
        lua_pushvalue(main_object->state, -1);
        private_LuaCEmbedResponse_free(possible_return);
        return PRIVATE_LUACEMBED_ONE_RETURN;

    }

    if(possible_return->type == PRIVATE_LUA_CEMBED_EVALUATION_FUNCTION){
        char formated_function[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
        snprintf(
                formated_function, sizeof(formated_function),
                PRIVATE_LUA_CEMBED_GLOBAL_EVALUATION_CODE,
                PRIVATE_LUA_CEMBED_EVALUATION_NAME,
                possible_return->string_val
        );

        int error_code = LuaCEmbed_evaluate_string_no_return(main_object, formated_function);

        if(error_code){
            private_LuaCEmbedResponse_free(possible_return);
            return PRIVATE_LUACEMBED_NO_RETURN;
        }

        lua_getglobal(main_object->state, PRIVATE_LUA_CEMBED_EVALUATION_NAME);
        const int TOTAL_ARGS =0;
        const int TOTAL_RETURNS =1;
        //calling the function
        lua_pcall(main_object->state, TOTAL_ARGS, TOTAL_RETURNS, 0);
        //printf("v:%s\n", lua_tostring(self->state,-1));
        lua_pushvalue(main_object->state, -1);
        private_LuaCEmbedResponse_free(possible_return);
        return PRIVATE_LUACEMBED_ONE_RETURN;

    }

    private_LuaCEmbedResponse_free(possible_return);
    return PRIVATE_LUACEMBED_NO_RETURN;

}


void LuaCembedTable_set_method(LuaCembedTable *self ,const char *name,LuaCEmbedResponse *(*callback)(LuaCembedTable  *self,LuaCEmbed *args)){



    lua_getglobal(self->main_object->state,self->global_buffer);
    lua_pushstring(self->main_object->state,name);

    lua_pushlightuserdata(self->main_object->state,(void*)callback); //calback
    lua_pushlightuserdata(self->main_object->state,(void*)self->main_object); //main_object
    lua_pushlightuserdata(self->main_object->state,(void*)self); //table
    lua_pushlightuserdata(self->main_object->state,(void*)name); //function name

    //add these clojure to be handled by the callbacks
    lua_pushcclosure(self->main_object->state,privateLuaCembedTable_handle_methods,3);


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

