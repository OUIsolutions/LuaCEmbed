

LuaCEmbed * newLuaCEmbed(){
    LuaCEmbed  *self = (LuaCEmbed*) malloc(sizeof (LuaCEmbed));
    *self = (LuaCEmbed){0};
    self->state = luaL_newstate();
    return self;
}

char * LuaCEmbed_get_error_message(LuaCEmbed *self){
    return self->error_message;
}

bool LuaCEmbed_has_errors(LuaCEmbed *self){
    if(self->error_message){
        return  true;
    }
    return false;
}


int privateLuaCEmbed_main_callback_handler(lua_State  *L){

    LuaCEmbedResponse* (*callback)(LuaCEmbed *args);
    callback = (LuaCEmbedResponse* (*)(LuaCEmbed *args))lua_touserdata(L, lua_upvalueindex(PRIVATE_LUACEMBED_FUNCTION_INDEX));

    LuaCEmbed  *self = (LuaCEmbed*)lua_touserdata(L,lua_upvalueindex(PRIVATE_LUACEMBED_EMBED_OBJECT));


    //evaluating callback
    LuaCEmbedResponse *possible_return = callback(self);

    if(!possible_return){
        return PRIVATE_LUACEMBED_NO_RETURN;
    }

    if(possible_return->type == PRIVATE_LUA_CEMBED_LONG_RESPONSE){
        lua_pushinteger(L, (int)possible_return->num_val);
        return PRIVATE_LUACEMBED_ONE_RETURN;
    }

    if(possible_return->type == PRIVATE_LUA_CEMBED_DOUBLE_RESPONSE){
        lua_pushnumber(L, possible_return->num_val);
        return PRIVATE_LUACEMBED_ONE_RETURN;
    }

    if(possible_return->type == PRIVATE_LUA_CEMBED_STRING_RESPONSE){
        lua_pushstring(L, possible_return->string_val);
        return PRIVATE_LUACEMBED_ONE_RETURN;
    }

    if(possible_return->type == PRIVATE_LUA_CEMBED_DOUBLE_RESPONSE){

        lua_pushboolean(L, (bool)possible_return->num_val);
        return PRIVATE_LUACEMBED_ONE_RETURN;
    }

    if(possible_return->type == PRIVATE_LUA_CEMBED_TABLE_RESPONSE){

        char formated_function[LUA_CEMBED_ARGS_BUFFER_SIZE] = {0};
        snprintf(
                formated_function, sizeof(formated_function),
                PRIVATE_LUA_CEMBED_FUNCTION_TABLE_RESPONSE_EVALUATION_CODE,
                PRIVATE_LUA_CEMBED_FUNCTION_EVALUATION_NAME,
                possible_return->string_val
        );

        int error_code =LuaCEmbed_evaluate_string(self,formated_function);

        if(error_code){
            return PRIVATE_LUACEMBED_NO_RETURN;
        }

        lua_getglobal(self->state, PRIVATE_LUA_CEMBED_FUNCTION_EVALUATION_NAME);
        const int TOTAL_ARGS =0;
        const int TOTAL_RETURNS =1;
        //calling the function
        lua_pcall(self->state,TOTAL_ARGS,TOTAL_RETURNS,0);
        //printf("v:%s\n", lua_tostring(self->state,-1));
        lua_pushvalue(self->state,-1);
        return PRIVATE_LUACEMBED_ONE_RETURN;

    }

    return PRIVATE_LUACEMBED_NO_RETURN;

}


void LuaCEmbed_add_calback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) ){

    lua_pushlightuserdata(self->state,(void*)callback);
    lua_pushlightuserdata(self->state,(void*)self);

    lua_pushcclosure(self->state,privateLuaCEmbed_main_callback_handler,PRIVATE_LUACEMBED_TOTAL_MAIN_CALLBACK_ARGS);
    lua_setglobal(self->state, callback_name);

}


int LuaCEmbed_evaluate_string(LuaCEmbed *self, const char *str){
   int error = luaL_dostring(self->state,str);
   if(error){
       self->error_message = strdup(lua_tostring(self->state,-1));
   }
   return error;

}

int LuaCEmbed_evaluete_file(LuaCEmbed *self, const char *file){
    int error =luaL_dofile(self->state,file);
    if(error){
        self->error_message = strdup(lua_tostring(self->state,-1));
    }
    return error;

}

void LuaCEmbed_free(LuaCEmbed *self){
    lua_close(self->state); // Fecha o estado Lua
    if(self->error_message){
        free(self->error_message);
    }

    free(self);
}
