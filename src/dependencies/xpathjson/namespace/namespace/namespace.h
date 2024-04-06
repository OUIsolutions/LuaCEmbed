

typedef struct {



    char *(*dump_to_string)(CxpathJson  *self, bool ident);
    void (*dump_to_file)(CxpathJson  *self,const char *filename, bool ident);

    CxpathJson * (*new_from_cJSON_by_reference)(cJSON *element);
    CxpathJson * (*new_from_cJSON)(cJSON *element);
    CxpathJson * (*newJsonObject)(void);
    CxpathJson * (*newJsonArray)(void);
    CxpathJson * (*new_from_string)( const char *data);
    CxpathJson * (*new_from_file)(const char *path);
    void (*free)(CxpathJson * self);

    cJSON * (*get_cJSON)(CxpathJson * self, const char *format, ...);
     char * (*get_str)(CxpathJson * self, const char *format, ...);
    double (*get_double)(CxpathJson * self, const char *format, ...);
    int (*get_int)(CxpathJson * self, const char *format, ...);
    bool (*get_bool)(CxpathJson * self, const char *format, ...);
    int (*size)(CxpathJson * self, const char *format, ...);
    CxpathJson  * (*get_object)(CxpathJson * self, const char *format, ...);
    CxpathJson  * (*get_array)(CxpathJson * self, const char *format, ...);
    char * (*get_key)(CxpathJson * self, const char *format, ...);



    void (*set_empty_array)(CxpathJson *self, const char *format, ...);
    void (*set_empty_object)(CxpathJson *self, const char *format, ...);
    void (*set_cjson_getting_ownership)(CxpathJson *self, cJSON *value, const char *format, ...);
    void (*set_str)(CxpathJson *self, const char *value, const char *format, ...);
    void (*set_str_getting_ownership)(CxpathJson *self, char *value, const char *format, ...);
    void (*set_double)(CxpathJson *self, double value, const char *format, ...);
    void (*set_int)(CxpathJson *self, int value, const char *format, ...);
    void (*set_bool)(CxpathJson *self, bool value, const char *format, ...);
    void (*set_xpathJson_getting_onwership)(CxpathJson *self, CxpathJson *value, const char *format, ...);
    void (*set_xpath_by_reference)(CxpathJson *self, CxpathJson *value, const char *format, ...);

    void (*set_default_cjson_getting_ownership)(CxpathJson *self, cJSON *value, const char *format, ...);
    void (*set_default_str_getting_onwership)(CxpathJson *self,  char *value, const char *format, ...);
    void (*set_default_str)(CxpathJson *self, const char *value, const char *format, ...);
    void (*set_default_double)(CxpathJson *self, double value, const char *format, ...);
    void (*set_default_int)(CxpathJson *self, int value, const char *format, ...);
    void (*set_default_bool)(CxpathJson *self, bool value, const char *format, ...);




    void (*destroy)(CxpathJson *self,const char *format, ...);


    CxpathJsonErrorNamespace errors;
    CxpathJsonTypeNamespace  types;
}CxpathJsonNamespace;

CxpathJsonNamespace newCxpathJsonNamespace();