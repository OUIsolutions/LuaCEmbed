


LuaCEmbedReturn *private_LuaCEmbedReturn_raw(){
    LuaCEmbedReturn *self = (LuaCEmbedReturn*) malloc(sizeof(LuaCEmbedReturn));
    *self = (LuaCEmbedReturn){0};
    return self;
}


LuaCEmbedReturn * LuaCEmbed_return_text(const char *text){
    LuaCEmbedReturn * self= private_LuaCEmbedReturn_raw();
    self->value = cJSON_CreateString(text);
    return self;
}

LuaCEmbedReturn  * LuaCEmbed_return_double(double value){
    LuaCEmbedReturn * self= private_LuaCEmbedReturn_raw();
    self->value = cJSON_CreateNumber(value);
    return self;
}

LuaCEmbedReturn  * LuaCEmbed_return_long(long value){
    LuaCEmbedReturn * self= private_LuaCEmbedReturn_raw();
    self->value = cJSON_CreateNumber((double )value);
    return self;
}
LuaCEmbedReturn  * LuaCEmbed_return_xpath(CxpathJson *value){
    LuaCEmbedReturn * self= private_LuaCEmbedReturn_raw();
    self->value =value->element;
    value->element_reference = true;
    CxpathJson_free(value);
    return self;
}

LuaCEmbedReturn  * LuaCEmbed_return_cJSON(cJSON *value){
    LuaCEmbedReturn * self= private_LuaCEmbedReturn_raw();
    self->value = value;
    return self;

}

LuaCEmbedReturn  * LuaCEmbed_return_error(const char *errror){
    LuaCEmbedReturn * self= private_LuaCEmbedReturn_raw();
    self->is_error = true;
    self->value = cJSON_CreateString(errror);
    return self;
}


void private_LuaCEmbedReturn_free(LuaCEmbedReturn  *self){
    cJSON_Delete(self->value);
    free(self);
}
