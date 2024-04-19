




void privateLuaCembedTableIteration_bool_callback(privateLuaCembedTableIteration *self ){
    int value_type = lua_type(self->embed_obj->state,-1);
    if(value_type != LUA_CEMBED_BOOL){

        privateLuaCEmbed_raise_error_not_jumping(
                self->embed_obj,
                PRIVATE_LUA_CEMBED_VALUE_TABLE_WITH_WRONG_TYPE,
                self->args->formated_code,
                self->location,
                LuaCembed_convert_arg_code(value_type),
                LuaCembed_convert_arg_code(LUA_CEMBED_BOOL)
        );
        return;
    }
    self->num_result = (bool)lua_toboolean(self->embed_obj->state,-1);

}


bool privateLuaCembedTableIteration_get_bool(privateLuaCembedTableIteration *self,int index ){
    self->callback = privateLuaCembedTableIteration_bool_callback;
    privateLuaCembedTableIteration_run_iteration(self,index);
    return (bool )self->num_result;
}


