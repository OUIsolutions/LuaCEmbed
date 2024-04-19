




void privateLuaCembedTableIteration_long_callback(privateLuaCembedTableIteration *self ){
    int value_type = lua_type(self->embed_obj->state,-1);
    if(value_type != LUA_CEMBED_NUMBER){

        privateLuaCEmbed_raise_error_not_jumping(
                self->embed_obj,
                PRIVATE_LUA_CEMBED_VALUE_TABLE_WITH_WRONG_TYPE,
                self->args->formated_code,
                self->location,
                LuaCembed_convert_arg_code(value_type),
                LuaCembed_convert_arg_code(LUA_CEMBED_NUMBER)
        );
        return;
    }
    self->num_result = lua_tonumber(self->embed_obj->state,-1);

}


long privateLuaCembedTableIteration_get_long(privateLuaCembedTableIteration *self,int index ){
    self->callback = privateLuaCembedTableIteration_long_callback;
    privateLuaCembedTableIteration_run_iteration(self,index);
    return (long )self->num_result;
}


