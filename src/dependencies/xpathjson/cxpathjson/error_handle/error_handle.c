
void CxpathJson_raise_errror(CxpathJson * self, int error_code, cJSON *path, const char *format, ...){
    if(self->error_code){
        return;
    }
    self->error_code = error_code;
    if(path){
        self->error_path_str = cJSON_PrintUnformatted(path);
        self->path_list = cJSON_Duplicate(path,true);
    }

    va_list args;
    va_start(args, format);
    self->error_message = (char*)malloc(2000 * sizeof (char));
    vsnprintf(self->error_message, 2000 * sizeof (char), format, args);
    va_end(args);

}

int CxpathJson_get_error_code(CxpathJson * self){

    if(!self){
        return CXPATHJSON_NOT_FOUND;
    }
    CxpathJson  *root = private_CxpathJson_get_root(self);
    return root->error_code;
}


bool CxpathJson_has_errors(CxpathJson * self){
    return (bool) CxpathJson_get_error_code(self);
}

bool CxpathJson_is_ok(CxpathJson * self){
    if(CxpathJson_has_errors(self)){
        return false;
    }
    return true;
}
char *  CxpathJson_get_error_message(CxpathJson * self){
    if(!self->error_code){
        return NULL;
    }
    return self->error_message;



}


void CxpathJson_clear_errors(CxpathJson * self){

    if(self->error_message){
        free(self->error_message);
    }

    if(self->path_list){
        cJSON_Delete(self->path_list);
    }

    if(self->error_path_str){
        free(self->error_path_str);
    }



    self->error_code = CXPATHJSON_OK_CODE;
}
char * CxpathJson_get_error_path(CxpathJson * self){
    return  self->error_path_str;
}