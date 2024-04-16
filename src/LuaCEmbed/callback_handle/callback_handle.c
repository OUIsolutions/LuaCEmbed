

int privateLuaCEmbed_main_callback_handler(lua_State  *L){

    LuaCEmbedResponse* (*callback)(LuaCEmbed *args);
    callback = (LuaCEmbedResponse* (*)(LuaCEmbed *args))lua_touserdata(L, lua_upvalueindex(PRIVATE_LUACEMBED_FUNCTION_INDEX));
    LuaCEmbed  *self = (LuaCEmbed*)lua_touserdata(L,lua_upvalueindex(PRIVATE_LUACEMBED_EMBED_OBJECT));
    char *func_name =  (char*)lua_touserdata(L,lua_upvalueindex(PRIVATE_LUACEMBED_FUNCTION_ARG));;
    self->current_function = func_name;

    //evaluating callback
    LuaCEmbedResponse *possible_return = callback(self);
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
    lua_pushlightuserdata(self->state,(void*)callback);
    lua_pushlightuserdata(self->state,(void*)self);
    lua_pushlightuserdata(self->state,(void*)callback_name);
    lua_pushcclosure(self->state,privateLuaCEmbed_main_callback_handler,PRIVATE_LUACEMBED_TOTAL_MAIN_CALLBACK_ARGS);


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
    lua_pushlightuserdata(self->state,(void*)callback);
    lua_pushlightuserdata(self->state,(void*)self);
    lua_pushlightuserdata(self->state,(void*)callback_name);
    lua_pushcclosure(self->state,privateLuaCEmbed_main_callback_handler,PRIVATE_LUACEMBED_TOTAL_MAIN_CALLBACK_ARGS);
    lua_setglobal(self->state, callback_name);

}


void LuaCEmbed_add_callback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) ){


    if(self->is_lib){
        private_LuaCEmbed_add_lib_callback(self,callback_name,callback);
        return;
    }
    private_LuaCEmbed_add_evaluation_callback(self,callback_name,callback);

}
