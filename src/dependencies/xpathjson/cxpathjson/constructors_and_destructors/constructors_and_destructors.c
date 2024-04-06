

CxpathJson * private_newCxpathJson(){
    CxpathJson  *self = (CxpathJson*) malloc(sizeof (CxpathJson));
    *self = (CxpathJson){0};
    self->childs = (struct CxpathJson **) (CxpathJson **) malloc(0);
    self->raise_runtime_errors = true;
    return self;
}

CxpathJson * private_CxpathJson_get_root(CxpathJson *self){
    if(!self->private_root){
        return self;
    }
    return (CxpathJson *) self->private_root;
}

CxpathJson * private_CxpathJson_construct_child(CxpathJson  *self,cJSON *element){
    CxpathJson  *created = newCxpathJson_from_cJSON_getting_ownership(element);
    created->private_root = (struct CxpathJson *) private_CxpathJson_get_root(self);
    self->childs = (struct CxpathJson **) realloc(
            self->childs,
            (self->size +1) * sizeof(CxpathJson)
             );
    self->childs[self->size] = (struct CxpathJson *) created;
    self->size+=1;
    return created;
}

CxpathJson * newCxpathJson_from_cJSON_by_reference(cJSON *element){
    CxpathJson  *self = private_newCxpathJson();
    self->element_reference = true;
    self->element = element;
    return  self;
}

CxpathJson * newCxpathJson_from_cJSON_getting_ownership(cJSON *element){
    CxpathJson  *self = private_newCxpathJson();
    self->element = element;
    return  self;
}

CxpathJson * newCxpathJsonObject(){
    cJSON *created = cJSON_CreateObject();
    return newCxpathJson_from_cJSON_getting_ownership(created);
}

CxpathJson * newCxpathJsonArray(){
    cJSON *created = cJSON_CreateArray();
    return newCxpathJson_from_cJSON_getting_ownership(created);
}

CxpathJson * newCxpathJson_from_string( const char *data){
    CxpathJson  *self = private_newCxpathJson();
    self->element =  cJSON_Parse(data);
    if(!self->element){
        CxpathJson_raise_errror(
                self,
                CXPATHJSON_STRING_NOT_PARSABLE_CODE,
                NULL,
                PRIVATE_CXPATHJSON_STRING_NOT_PARSABLE_MESSAGE,
                data
                );
    }
    return  self;
}

CxpathJson * newCxpathJson_from_file(const char *path){

    char *content = private_cxpathjson_read_file(path);
    if(!content){
        CxpathJson  *self = private_newCxpathJson();
        CxpathJson_raise_errror(
                self,
                CXPATHJSON_FILE_NOT_FOUND_CODE,
                NULL,
                PRIVATE_CXPATHJSON_FILE_NOT_FOUND_MESSAGE,
                path
                );
        return self;
    }

    CxpathJson *result = newCxpathJson_from_string(content);
    free(content);
    return result;
}

void CxpathJson_free(CxpathJson * self){
    //means its root element
    if(!self->private_root){
        CxpathJson_clear_errors(self);
        if(self->element && !self->element_reference){
            cJSON_Delete(self->element);
        }
    }

    for(int i = 0; i < self->size; i++){
        struct CxpathJson  *current_child = self->childs[i];
        CxpathJson_free((CxpathJson *) current_child);
    }
    free(self->childs);

    free(self);
}
