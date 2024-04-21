

int privateLuaCEmbed_main_callback_handler(lua_State  *L){

    bool is_a_method =  (bool)lua_touserdata(L, lua_upvalueindex(1));
    bool is_a_function = !is_a_method;
    LuaCEmbedResponse *possible_return = NULL;
    LuaCEmbed  *self = (LuaCEmbed*)lua_touserdata(L,lua_upvalueindex(2));
    char *func_name =  (char*)lua_touserdata(L,lua_upvalueindex(3));
    self->current_function = func_name;

    if(is_a_method){
        LuaCEmbedResponse *(*method_callback)(LuaCembedTable *tb,LuaCEmbed *self);
        LuaCembedTable  *table = (LuaCembedTable*) lua_touserdata(L, lua_upvalueindex(4));
        method_callback = (LuaCEmbedResponse *(*)(LuaCembedTable *tb,LuaCEmbed *self))lua_touserdata(L, lua_upvalueindex(5));
        possible_return = method_callback(table,self);
    }

    if(is_a_function){
        LuaCEmbedResponse *(*function_callback)(LuaCEmbed *self);
        function_callback = (LuaCEmbedResponse *(*)(LuaCEmbed *self))lua_touserdata(L, lua_upvalueindex(4));
        possible_return = function_callback(self);
    }

    self->current_function = NULL;

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

        int error_code = LuaCEmbed_evaluate_string_no_return(self, formated_function);

        if(error_code){
            private_LuaCEmbedResponse_free(possible_return);
            return PRIVATE_LUACEMBED_NO_RETURN;
        }

        lua_getglobal(self->state, PRIVATE_LUA_CEMBED_EVALUATION_NAME);
        const int TOTAL_ARGS =0;
        const int TOTAL_RETURNS =1;
        //calling the function
        lua_pcall(self->state,TOTAL_ARGS,TOTAL_RETURNS,0);
        //printf("v:%s\n", lua_tostring(self->state,-1));
        lua_pushvalue(self->state,-1);
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

        int error_code = LuaCEmbed_evaluate_string_no_return(self, formated_function);

        if(error_code){
            private_LuaCEmbedResponse_free(possible_return);
            return PRIVATE_LUACEMBED_NO_RETURN;
        }

        lua_getglobal(self->state, PRIVATE_LUA_CEMBED_EVALUATION_NAME);
        const int TOTAL_ARGS =0;
        const int TOTAL_RETURNS =1;
        //calling the function
        lua_pcall(self->state,TOTAL_ARGS,TOTAL_RETURNS,0);
        //printf("v:%s\n", lua_tostring(self->state,-1));
        lua_pushvalue(self->state,-1);
        private_LuaCEmbedResponse_free(possible_return);
        return PRIVATE_LUACEMBED_ONE_RETURN;

    }

    private_LuaCEmbedResponse_free(possible_return);
    return PRIVATE_LUACEMBED_NO_RETURN;

}


void private_LuaCEmbed_add_lib_callback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) ){

    //get the table
    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME);
    lua_pushvalue(self->state,-1);

    //set the function name
    lua_pushstring(self->state,callback_name);

    //creating the clojure

    //creating the clojure
    lua_pushlightuserdata(self->state,(void*)false);//is a method
    lua_pushlightuserdata(self->state,(void*)self); //self
    lua_pushlightuserdata(self->state,(void*)callback_name);//calback name
    lua_pushlightuserdata(self->state,(void*)callback);//calback

    lua_pushcclosure(self->state,privateLuaCEmbed_main_callback_handler,4);


    lua_settable(self->state,-3);
    if(self->public_functions){
        //it points the function to a global function
        //like: callback = private_lua_c_embed_main_lib_table.callback
        lua_getglobal(self->state,PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME);
        lua_getfield(self->state,-1,callback_name);
        lua_setglobal(self->state, callback_name);
    }


}

void private_LuaCEmbed_add_evaluation_callback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) ){

    //creating the clojure
    lua_pushlightuserdata(self->state,(void*)false);//is a method
    lua_pushlightuserdata(self->state,(void*)self); //self
    lua_pushlightuserdata(self->state,(void*)callback_name);//calback name
    lua_pushlightuserdata(self->state,(void*)callback);

    lua_pushcclosure(self->state,privateLuaCEmbed_main_callback_handler,4);
    lua_setglobal(self->state, callback_name);

}


void LuaCEmbed_add_callback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) ){


    if(self->is_lib){
        private_LuaCEmbed_add_lib_callback(self,callback_name,callback);
        return;
    }
    private_LuaCEmbed_add_evaluation_callback(self,callback_name,callback);

}
