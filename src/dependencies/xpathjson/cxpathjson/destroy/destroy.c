

void CxpathJson_destroy(CxpathJson *self,const char *format, ...){

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

    bool old_raise = self->raise_runtime_errors;
    self->raise_runtime_errors = false;
    cJSON *possible_element = private_CxpathJson_get_cJSON_by_path_list(self, path_list);
    self->raise_runtime_errors = old_raise;

    if(!possible_element){
        cJSON_Delete(path_list);
        return;
    }
    //here we know the element exist
    int path_size = cJSON_GetArraySize(path_list);
    cJSON *rest = cJSON_CreateArray();

    for(int i = 0; i < path_size -1; i++){
        cJSON *element = cJSON_GetArrayItem(path_list,i);
        cJSON_AddItemReferenceToArray(rest,element);
    }
    cJSON *father = private_CxpathJson_get_cJSON_by_path_list(self, rest);
    cJSON_Delete(rest);

    cJSON *last = cJSON_GetArrayItem(path_list,path_size -1);

    if(cJSON_IsString(last)){
        cJSON_DeleteItemFromObject(father,last->valuestring);
    }
    if(cJSON_IsNumber(last)){
        cJSON_DeleteItemFromArray(father,last->valueint);
    }

    cJSON_Delete(path_list);

}