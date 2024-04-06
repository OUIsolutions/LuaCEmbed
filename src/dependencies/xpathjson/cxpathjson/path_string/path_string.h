
#ifndef CXPATHJSON_APPEND_KEY
#define CXPATHJSON_APPEND_KEY "$append"
#endif

cJSON * privateCxpathJson_parse_args(CxpathJson * self,bool allow_append,const char *format, va_list args);

cJSON * privateCxpathJson_parse_args_read_only(CxpathJson * self,const char *format, va_list args);


cJSON * privateCxpathJson_parse_write_mode(CxpathJson * self,const char *format, va_list args);
