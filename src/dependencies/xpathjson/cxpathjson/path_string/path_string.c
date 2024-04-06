
cJSON * privateCxpathJson_parse_args(CxpathJson * self,bool allow_append,const char *format, va_list args){
    char buffer[2000] = {0};
    vsnprintf(buffer, sizeof(buffer), format, args);
    private_cxpathjson_replace_comas(buffer);
    cJSON *parsed_path  = cJSON_Parse(buffer);

    if(!parsed_path){
        CxpathJson  *root = private_CxpathJson_get_root(self);
        CxpathJson_raise_errror(root,
                                CXPATHJSON_ARG_PATH_NOT_VALID_CODE,
                                NULL,
                                PRIVATE_CXPATHJSON_ARG_PATH_NOT_VALID_MESSAGE,
                                buffer
        );

        cJSON_Delete(parsed_path);
        return  NULL;
    }

    if(!cJSON_IsArray(parsed_path)){
        CxpathJson  *root = private_CxpathJson_get_root(self);
        CxpathJson_raise_errror(root,
                                CXPATHJSON_ARG_PATH_NOT_VALID_CODE,
                                NULL,
                                PRIVATE_CXPATHJSON_ARG_PATH_NOT_VALID_MESSAGE,
                                buffer
        );
        cJSON_Delete(parsed_path);
        return  NULL;
    }

    int path_size = cJSON_GetArraySize(parsed_path);
    for(int i = 0;i <path_size;i++){
        cJSON *current = cJSON_GetArrayItem(parsed_path,i);

        if(cJSON_IsString(current)){
            if( !allow_append && strcmp(current->valuestring, CXPATHJSON_APPEND_KEY) == 0){
                CxpathJson  *root = private_CxpathJson_get_root(self);
                CxpathJson_raise_errror(root,
                                        CXPATHJSON_ARG_PATH_NOT_VALID_CODE,
                                        NULL,
                                        PRIVATE_CXPATHJSON_APPEND_NOT_VALID_ON_READ_ONLY_FUNCTION_MESSAGE,
                                        buffer
                );
                cJSON_Delete(parsed_path);
                return  NULL;
            }
            continue;
        }

        if(cJSON_IsNumber(current)){
            continue;
        }

        CxpathJson  *root = private_CxpathJson_get_root(self);
        CxpathJson_raise_errror(root,
                                CXPATHJSON_ARG_PATH_NOT_VALID_CODE,
                                NULL,
                                PRIVATE_CXPATHJSON_ARG_PATH_NOT_VALID_MESSAGE,
                                buffer
        );
        cJSON_Delete(parsed_path);
        return  NULL;
    }

    return parsed_path;
}

cJSON * privateCxpathJson_parse_args_read_only(CxpathJson * self, const char *format, va_list args){
    return privateCxpathJson_parse_args(self,false,format,args);
}

cJSON * privateCxpathJson_parse_write_mode(CxpathJson * self,const char *format, va_list args){
    return privateCxpathJson_parse_args(self,true,format,args);
}
