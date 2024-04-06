


LuaCEmbedReturn *private_LuaCEmbedReturn_raw(){
    LuaCEmbedReturn *self = (LuaCEmbedReturn*) malloc(sizeof(LuaCEmbedReturn));
    *self = (LuaCEmbedReturn){0};
}


LuaCEmbedReturn * LuaCEmbedReturn_text(const char *text){
    LuaCEmbedReturn * self= private_LuaCEmbedReturn_raw();
    self->value = cJSON_CreateString(text);
}

LuaCEmbedReturn  * LuaCEmbedReturn_double(double value){
    LuaCEmbedReturn * self= private_LuaCEmbedReturn_raw();
    self->value = cJSON_CreateNumber(value);
}

LuaCEmbedReturn  * LuaCEmbedReturn_long(long value){
    LuaCEmbedReturn * self= private_LuaCEmbedReturn_raw();
    self->value = cJSON_CreateNumber((double )value);
}

LuaCEmbedReturn  * LuaCEmbedReturn_cJSON(cJSON *value){
    LuaCEmbedReturn * self= private_LuaCEmbedReturn_raw();
    self->value = value;
}

LuaCEmbedReturn  * LuaCEmbedReturn_error(const char *errror){
    LuaCEmbedReturn * self= private_LuaCEmbedReturn_raw();
    self->is_error = true;
    self->value = cJSON_CreateString(errror);
}


void private_LuaCEmbedReturn_free(LuaCEmbedReturn  *self){
    cJSON_Delete(self->value);
    free(self);
}
