
int private_cxpathjson_convert_index(int index, int size){
    if(index >=0){
        return index;
    }
    return (size +index);


}

bool private_cxpathjson_path_is_append(cJSON *current_path){
    bool is_append = false;
    if(cJSON_IsString(current_path)){
        is_append = strcmp(current_path->valuestring, CXPATHJSON_APPEND_KEY) == 0;
    }
    return is_append;

}

void private_cxpathjson_replace_comas(char *result){
    long size = strlen(result);
    for(int i =1; i < size; i++){
        char current_char = result[i];
        char last_char = result[i-1];

        if(current_char == '\'' && last_char !='\\'){
            result[i] = '"';
        }
    }
}
