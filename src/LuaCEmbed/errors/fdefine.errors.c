


char * LuaCEmbed_get_error_message(LuaCEmbed *self){
    if(!self){
        return NULL;
    }

    return self->error_msg;
}
void LuaCEmbed_clear_errors(LuaCEmbed *self){
    if(!self){
        return;
    }

    if(self->error_msg){
        free(self->error_msg);
        self->error_msg = NULL;
    }
}

void privateLuaCEmbed_raise_error_not_jumping(LuaCEmbed *self, const char *error_msg, ...){

    if(LuaCEmbed_has_errors(self)){
        return;
    }

    va_list args;
    va_start(args,error_msg);
    self->error_msg = private_LuaCembed_format_vaarg(error_msg, args);
    va_end(args);

}



bool LuaCEmbed_has_errors(LuaCEmbed *self){
    if(!self){
        return true;
    }

    if(self->error_msg){
        return  true;
    }

    return false;
}



void LuaCEmbed_dangerous_raise_error_jumping(LuaCEmbed *self,const char *error_msg,...){
    if(LuaCEmbed_has_errors(self)){
        return;
    }

    va_list args;
    va_start(args,error_msg);
    char *error_formmated = private_LuaCembed_format_vaarg(error_msg, args);
    va_end(args);
    lua_pushstring(self->state, error_formmated);
    free(error_formmated);
    lua_error(self->state);
}

void LuaCEmbed_dangerous_raise_self_error_jumping(LuaCEmbed *self){
    if(!LuaCEmbed_has_errors(self)){
        return;
    }
    char *msg = LuaCEmbed_get_error_message(self);
    lua_pushstring(self->state,msg);
    LuaCEmbed_clear_errors(self);
    lua_error(self->state);
}
