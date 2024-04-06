

typedef struct CxpathJson{

    cJSON * element;
    bool element_reference;
    bool raise_runtime_errors;
    char *error_message;
    cJSON *path_list;
     char *error_path_str;
    int error_code;

    struct CxpathJson *private_root;
    struct CxpathJson **childs;
    int size;

}CxpathJson;

