

void CxpathJson_set_cjson_getting_ownership(CxpathJson *self, cJSON *value, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        cJSON_Delete(value);
        return ;
    }

    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_write_mode(self,format,args);
    va_end(args);
    if(!path_list){
        cJSON_Delete(value);
        return ;
    }
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value, path_list);
    cJSON_Delete(path_list);
}


void CxpathJson_set_xpathJson_getting_onwership(CxpathJson *self, CxpathJson *value, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        CxpathJson_free(value);
        return ;
    }

    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_write_mode(self,format,args);
    va_end(args);
    if(!path_list){
        CxpathJson_free(value);
        return ;
    }

    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value->element,path_list);
    value->element = NULL;
    cJSON_Delete(path_list);
    CxpathJson_free(value);
}

void CxpathJson_set_xpath_by_reference(CxpathJson *self, CxpathJson *value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return ;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_write_mode(self,format,args);
    va_end(args);
    if(!path_list){
        return ;
    }


    cJSON *copy = cJSON_Duplicate(value->element,true);
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, copy, path_list);
    cJSON_Delete(path_list);
}


void CxpathJson_set_empty_array(CxpathJson *self, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return ;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_write_mode(self,format,args);
    va_end(args);
    if(!path_list){
        return ;
    }

    cJSON *value_cjson = cJSON_CreateArray();
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value_cjson, path_list);
    cJSON_Delete(path_list);
}



void CxpathJson_set_empty_object(CxpathJson *self, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        return ;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_write_mode(self,format,args);
    va_end(args);
    if(!path_list){
        return ;
    }

    cJSON *value_cjson = cJSON_CreateObject();
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value_cjson, path_list);
    cJSON_Delete(path_list);

}


void CxpathJson_set_str_getting_ownership(CxpathJson *self,  char *value, const char *format, ...){

    if(CxpathJson_get_error_code(self)){
        free(value);
        return ;
    }

    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_write_mode(self,format,args);
    va_end(args);
    if(!path_list){
        free(value);
        return ;
    }

    cJSON *value_cjson = cJSON_New_Item(&global_hooks);
    value_cjson->type = cJSON_String;
    value_cjson->valuestring = value;
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value_cjson, path_list);
    cJSON_Delete(path_list);

}

void CxpathJson_set_str(CxpathJson *self, const char *value, const char *format, ...){


    if(CxpathJson_get_error_code(self)){
        return ;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_write_mode(self,format,args);
    va_end(args);
    if(!path_list){
        return ;
    }

    cJSON *value_cjson = cJSON_CreateString(value);
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value_cjson, path_list);
    cJSON_Delete(path_list);


}

void CxpathJson_set_double(CxpathJson *self, double value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return ;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_write_mode(self,format,args);
    va_end(args);
    if(!path_list){
        return ;
    }

    cJSON *value_cjson = cJSON_CreateNumber(value);
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value_cjson, path_list);
    cJSON_Delete(path_list);
}

void CxpathJson_set_int(CxpathJson *self, int value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return ;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_write_mode(self,format,args);
    va_end(args);
    if(!path_list){
        return ;
    }

    cJSON *value_cjson = cJSON_CreateNumber((int)value);
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value_cjson, path_list);
    cJSON_Delete(path_list);
}

void CxpathJson_set_bool(CxpathJson *self, bool value, const char *format, ...){
    if(CxpathJson_get_error_code(self)){
        return ;
    }
    va_list args;
    va_start(args, format);
    cJSON *path_list = privateCxpathJson_parse_write_mode(self,format,args);
    va_end(args);
    if(!path_list){
        return ;
    }

    cJSON *value_cjson = cJSON_CreateBool(value);
    private_cxpathjson_set_cjson_by_path_list_getting_ownership(self, value_cjson, path_list);
    cJSON_Delete(path_list);

}
