typedef struct {


    int (*get_error_code)(CxpathJson * self);
    bool (*is_ok)(CxpathJson * self);

    bool (*has_errors)(CxpathJson * self);
    char * (*get_error_message)(CxpathJson * self);
    char * (*get_error_path)(CxpathJson * self);
    void (*raise_errror)(CxpathJson * self, int error_code, cJSON *path_list, const char *format, ...);
    void (*clear_errors)(CxpathJson * self);


}CxpathJsonErrorNamespace;

CxpathJsonErrorNamespace newCxpathJsonErrorNamespace();
