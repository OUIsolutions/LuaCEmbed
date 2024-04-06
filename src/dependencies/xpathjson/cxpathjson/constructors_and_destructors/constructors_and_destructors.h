

CxpathJson * private_newCxpathJson(void);

CxpathJson * private_CxpathJson_get_root(CxpathJson *self);

CxpathJson * private_CxpathJson_construct_child(CxpathJson  *self,cJSON *element);

CxpathJson * newCxpathJson_from_cJSON_by_reference(cJSON *element);

CxpathJson * newCxpathJson_from_cJSON_getting_ownership(cJSON *element);

CxpathJson * newCxpathJsonObject(void);

CxpathJson * newCxpathJsonArray(void);

CxpathJson * newCxpathJson_from_string( const char *data);

CxpathJson * newCxpathJson_from_file(const char *path);


void CxpathJson_free(CxpathJson * self);
