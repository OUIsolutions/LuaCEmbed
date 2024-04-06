

int CxpathJson_type(CxpathJson * self, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return CXPATHJSON_NOT_FOUND;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_args_read_only(self,format,args);
    va_end(args);
    if(!path_list){
        return CXPATHJSON_NOT_FOUND;
    }

    bool old_config = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *old = private_CxpathJson_get_cJSON_by_path_list(self,path_list);
    self->raise_runtime_errors = old_config;

    int type_result =  private_cxpathjson_get_json_type(old);
    cJSON_Delete(path_list);
    return  type_result;
}

bool CxpathJson_exist(CxpathJson * self, const char *format, ...){


    if(CxpathJson_get_error_code(self)){
        return CXPATHJSON_NOT_FOUND;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_args_read_only(self,format,args);
    va_end(args);
    if(!path_list){
        return CXPATHJSON_NOT_FOUND;
    }

    bool old_config = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *old = private_CxpathJson_get_cJSON_by_path_list(self,path_list);
    self->raise_runtime_errors = old_config;

    int type_result =  private_cxpathjson_get_json_type(old);
    cJSON_Delete(path_list);
    return  (bool)type_result;
}

bool CxpathJson_its_not_null(CxpathJson * self, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return CXPATHJSON_NOT_FOUND;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_args_read_only(self,format,args);
    va_end(args);
    if(!path_list){
        return CXPATHJSON_NOT_FOUND;
    }

    bool old_config = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *old = private_CxpathJson_get_cJSON_by_path_list(self,path_list);
    self->raise_runtime_errors = old_config;

    int type_result =  private_cxpathjson_get_json_type(old);
    cJSON_Delete(path_list);

    if(type_result == CXPATHJSON_NULL){
        return  false;
    }

    if(type_result == CXPATHJSON_NOT_FOUND){
        return  false;
    }

    return  true;
}



const char * CxpathJson_type_str(CxpathJson * self, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return CXPATHJSON_NOT_FOUND_TEXT;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_args_read_only(self,format,args);
    va_end(args);
    if(!path_list){
        return CXPATHJSON_NOT_FOUND_TEXT;
    }

    bool old_config = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *old = private_CxpathJson_get_cJSON_by_path_list(self,path_list);
    self->raise_runtime_errors = old_config;
    cJSON_Delete(path_list);

    return private_cxpathjson_convert_json_type_to_str(old);
}


bool CxpathJson_its_iterable(CxpathJson * self, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return CXPATHJSON_NOT_FOUND;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_args_read_only(self,format,args);
    va_end(args);
    if(!path_list){
        return CXPATHJSON_NOT_FOUND;
    }

    bool old_config = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *old = private_CxpathJson_get_cJSON_by_path_list(self,path_list);
    self->raise_runtime_errors = old_config;

    int type_result =  private_cxpathjson_get_json_type(old);
    cJSON_Delete(path_list);

    if(type_result == CXPATHJSON_ARRAY){
        return  true;
    }

    if(type_result == CXPATHJSON_OBJECT){
        return  true;
    }

    return  false;
}