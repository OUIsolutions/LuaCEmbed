

int private_CxpathJson_verifiy_if_insertion_is_possible(CxpathJson *self, cJSON *path_list);

void private_cxpathjson_set_cjson_by_path_list_getting_ownership(CxpathJson *self, cJSON *value, cJSON *path_list);


void CxpathJson_set_cjson_getting_ownership(CxpathJson *self, cJSON *value, const char *format, ...);

void CxpathJson_set_xpathJson_getting_onwership(CxpathJson *self, CxpathJson *value, const char *format, ...);

void CxpathJson_set_xpath_by_reference(CxpathJson *self, CxpathJson *value, const char *format, ...);


void CxpathJson_set_empty_array(CxpathJson *self, const char *format, ...);

void CxpathJson_set_empty_object(CxpathJson *self, const char *format, ...);


void CxpathJson_set_str(CxpathJson *self, const char *value, const char *format, ...);

void CxpathJson_set_str_getting_ownership(CxpathJson *self,  char *value, const char *format, ...);

void CxpathJson_set_double(CxpathJson *self, double value, const char *format, ...);

void CxpathJson_set_int(CxpathJson *self, int value, const char *format, ...);

void CxpathJson_set_bool(CxpathJson *self, bool value, const char *format, ...);


void CxpathJson_set_default_cjson_getting_ownership(CxpathJson *self, cJSON *value, const char *format, ...);

void CxpathJson_set_default_str_getting_onwership(CxpathJson *self,  char *value, const char *format, ...);


void CxpathJson_set_default_str(CxpathJson *self, const char *value, const char *format, ...);

void CxpathJson_set_default_double(CxpathJson *self, double value, const char *format, ...);

void CxpathJson_set_default_int(CxpathJson *self, int value, const char *format, ...);

void CxpathJson_set_default_bool(CxpathJson *self, bool value, const char *format, ...);

