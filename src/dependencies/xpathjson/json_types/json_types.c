



int private_cxpathjson_get_json_type(cJSON *element){
    if(!element){
        return CXPATHJSON_NOT_FOUND;
    }

    if(cJSON_IsNull(element)){
        return CXPATHJSON_NULL;
    }

    if(cJSON_IsBool(element)){
        return CXPATHJSON_BOOL;
    }

    if(cJSON_IsNumber(element)){
        return CXPATHJSON_NUMBER;
    }

    if(cJSON_IsString(element)){
        return CXPATHJSON_STRING;
    }

    if(cJSON_IsObject(element)){
        return CXPATHJSON_OBJECT;
    }

    if(cJSON_IsArray(element)){
        return CXPATHJSON_ARRAY;
    }
    return CXPATHJSON_NOT_FOUND;
}


const char * private_cxpathjson_convert_json_type_to_str(cJSON *element){


    if(!element){
        return CXPATHJSON_NOT_FOUND_TEXT;
    }

    if(cJSON_IsNull(element)){
        return CXPATHJSON_NULL_TEXT;
    }

    if(cJSON_IsBool(element)){
        return CXPATHJSON_BOOL_TEXT;
    }

    if(cJSON_IsNumber(element)){
        return CXPATHJSON_NUMBER_TEXT;
    }

    if(cJSON_IsString(element)){
        return CXPATHJSON_STRING_TEXT;
    }

    if(cJSON_IsObject(element)){
        return CXPATHJSON_OBJECT_TEXT;
    }

    if(cJSON_IsArray(element)){
        return CXPATHJSON_ARRAY_TEXT;
    }
    return CXPATHJSON_NOT_FOUND_TEXT;
}
