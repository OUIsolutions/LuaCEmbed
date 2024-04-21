


LuaCEmbedResponse *private_LuaCEmbedReturn_raw(){
    LuaCEmbedResponse *self = (LuaCEmbedResponse*)malloc(sizeof(LuaCEmbedResponse));
    *self = (LuaCEmbedResponse){0};
    return self;
}

LuaCEmbedResponse  * LuaCEmbed_send_bool(bool value){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_BOOL_RESPONSE;
    self->num_val = (double)value;
    return self;
}

LuaCEmbedResponse * LuaCEmbed_send_str(const char *text){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_STRING_RESPONSE;
    self->string_val  = strdup(text);
    return self;
}
LuaCEmbedResponse * LuaCEmbed_send_table(LuaCEmbedTable *table){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_TABLE_RESPONSE;
    self->string_val = strdup(table->global_buffer);
    return self;
}

LuaCEmbedResponse * LuaCEmbed_send_evaluation(const char *code){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_EVALUATION;
    self->string_val  = strdup(code);
    return self;
}

LuaCEmbedResponse  * LuaCEmbed_send_double(double value){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_DOUBLE_RESPONSE;
    self->num_val = value;
    return self;
}

LuaCEmbedResponse  * LuaCEmbed_send_long(long value){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->type = PRIVATE_LUA_CEMBED_LONG_RESPONSE;
    self->num_val = (double)value;
    return self;
}



void private_LuaCEmbedResponse_free(LuaCEmbedResponse  *self){
    if(self->string_val){
        free(self->string_val);
    }
    free(self);
}
