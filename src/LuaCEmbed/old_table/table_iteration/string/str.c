
void privateLuaCembedTableIteration_str_callback(privateLuaCembedTableIteration *self ){
    int value_type = lua_type(self->embed_obj->state,-1);
    if(value_type != LUA_CEMBED_STRING){

        privateLuaCEmbed_raise_error_not_jumping(
                self->embed_obj,
                PRIVATE_LUA_CEMBED_VALUE_TABLE_WITH_WRONG_TYPE,
                self->args->formated_code,
                self->location,
                LuaCembed_convert_arg_code(value_type),
                LuaCembed_convert_arg_code(LUA_CEMBED_STRING)
        );
        return;
    }
    self->str_result = (char*) lua_tostring(self->embed_obj->state,-1);

}

char * privateLuaCembedTableIteration_get_str(privateLuaCembedTableIteration *self,int index ){
    self->callback = privateLuaCembedTableIteration_str_callback;
    privateLuaCembedTableIteration_run_iteration(self,index);
    return self->str_result;
}


