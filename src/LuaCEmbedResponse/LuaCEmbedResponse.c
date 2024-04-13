


LuaCEmbedResponse *private_LuaCEmbedReturn_raw(){
    LuaCEmbedResponse *self = (LuaCEmbedResponse*) malloc(sizeof(LuaCEmbedResponse));
    *self = (LuaCEmbedResponse){0};
    return self;
}


LuaCEmbedResponse * LuaCEmbed_send_str(const char *text){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->value = cJSON_CreateString(text);
    return self;
}

LuaCEmbedResponse  * LuaCEmbed_send_double(double value){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->value = cJSON_CreateNumber(value);
    return self;
}

LuaCEmbedResponse  * LuaCEmbed_send_long(long value){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->value = cJSON_CreateNumber((double )value);
    return self;
}
LuaCEmbedResponse  * LuaCEmbed_return_xpath(CxpathJson *value){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->value =value->element;
    value->element_reference = true;
    CxpathJson_free(value);
    return self;
}

LuaCEmbedResponse  * LuaCEmbed_return_cJSON(cJSON *value){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->value = value;
    return self;

}

LuaCEmbedResponse  * LuaCEmbed_return_error(const char *errror){
    LuaCEmbedResponse * self= private_LuaCEmbedReturn_raw();
    self->is_error = true;
    self->value = cJSON_CreateString(errror);
    return self;
}


void private_LuaCEmbedResponse_free(LuaCEmbedResponse  *self){
    cJSON_Delete(self->value);
    free(self);
}
