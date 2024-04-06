

void CxpathJson_set_default_cjson_getting_ownership(CxpathJson *self, cJSON *value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return ;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_args_read_only(self,format,args);
    va_end(args);
    if(!path_list){
        return ;
    }

    bool old_config = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *old = private_CxpathJson_get_cJSON_by_path_list(self,path_list);
    self->raise_runtime_errors = old_config;

    if(old || CxpathJson_has_errors(self)){
        cJSON_Delete(path_list);
        cJSON_Delete(value);
        return;
    }
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value, path_list);
    cJSON_Delete(path_list);

}
void CxpathJson_set_default_str_getting_onwership(CxpathJson *self,  char *value, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return ;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_args_read_only(self,format,args);
    va_end(args);
    if(!path_list){
        return ;
    }

    bool old_config = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *old = private_CxpathJson_get_cJSON_by_path_list(self,path_list);
    self->raise_runtime_errors = old_config;

    if(old || CxpathJson_has_errors(self)){
        cJSON_Delete(path_list);
        free(value);
        return;
    }

    cJSON *value_cjson = cJSON_New_Item(&global_hooks);
    value_cjson->type = cJSON_String;
    value_cjson->valuestring = value;
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value_cjson, path_list);
    cJSON_Delete(path_list);
}

void CxpathJson_set_default_str(CxpathJson *self, const char *value, const char *format, ...){


    if(CxpathJson_get_error_code(self)){
        return ;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_args_read_only(self,format,args);
    va_end(args);
    if(!path_list){
        return ;
    }

    bool old_config = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *old = private_CxpathJson_get_cJSON_by_path_list(self,path_list);
    self->raise_runtime_errors = old_config;

    if(old || CxpathJson_has_errors(self)){
        cJSON_Delete(path_list);
        return;
    }

    cJSON *value_cjson = cJSON_CreateString(value);
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value_cjson, path_list);
    cJSON_Delete(path_list);
}


void CxpathJson_set_default_double(CxpathJson *self, double value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return ;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_args_read_only(self,format,args);
    va_end(args);
    if(!path_list){
        return ;
    }

    bool old_config = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *old = private_CxpathJson_get_cJSON_by_path_list(self,path_list);
    self->raise_runtime_errors = old_config;

    if(old || CxpathJson_has_errors(self)){
        cJSON_Delete(path_list);
        return;
    }

    cJSON *value_cjson = cJSON_CreateNumber(value);
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value_cjson, path_list);
    cJSON_Delete(path_list);

}

void CxpathJson_set_default_int(CxpathJson *self, int value, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return ;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_args_read_only(self,format,args);
    va_end(args);
    if(!path_list){
        return ;
    }

    bool old_config = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *old = private_CxpathJson_get_cJSON_by_path_list(self,path_list);
    self->raise_runtime_errors = old_config;

    if(old || CxpathJson_has_errors(self)){
        cJSON_Delete(path_list);
        return;
    }

    cJSON *value_cjson = cJSON_CreateNumber((int)value);
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value_cjson, path_list);
    cJSON_Delete(path_list);

}

void CxpathJson_set_default_bool(CxpathJson *self, bool value, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return ;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_args_read_only(self,format,args);
    va_end(args);
    if(!path_list){
        return ;
    }

    bool old_config = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *old = private_CxpathJson_get_cJSON_by_path_list(self,path_list);
    self->raise_runtime_errors = old_config;

    if(old || CxpathJson_has_errors(self)){
        cJSON_Delete(path_list);
        return;
    }

    cJSON *value_cjson = cJSON_CreateBool(value);
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value_cjson, path_list);
    cJSON_Delete(path_list);

}