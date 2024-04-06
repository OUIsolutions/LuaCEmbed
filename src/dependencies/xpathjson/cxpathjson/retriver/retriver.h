

cJSON * private_CxpathJson_get_cJSON_by_path_list(CxpathJson * self, cJSON *path_list);




cJSON * CxpathJson_get_cJSON(CxpathJson * self, const char *format, ...);


char * CxpathJson_get_str(CxpathJson * self, const char *format, ...);

char * CxpathJson_get_key(CxpathJson * self, const char *format, ...);

CxpathJson  * CxpathJson_get_object(CxpathJson * self, const char *format, ...);


CxpathJson  * CxpathJson_get_array(CxpathJson * self, const char *format, ...);


double CxpathJson_get_double(CxpathJson * self, const char *format, ...);

int CxpathJson_get_int(CxpathJson * self, const char *format, ...);

bool CxpathJson_get_bool(CxpathJson * self, const char *format, ...);


int CxpathJson_get_size(CxpathJson * self, const char *format, ...);
