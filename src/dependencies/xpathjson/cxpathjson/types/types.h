#define CXPATHJSON_NOT_FOUND (-1)

#define CXPATHJSON_NULL 1

#define CXPATHJSON_STRING 2
#define CXPATHJSON_BOOL 3
#define CXPATHJSON_NUMBER 4
#define CXPATHJSON_OBJECT 5
#define CXPATHJSON_ARRAY 6

#define CXPATHJSON_NOT_FOUND_TEXT "not found"
#define CXPATHJSON_NULL_TEXT "Null"

#define CXPATHJSON_STRING_TEXT  "String"
#define CXPATHJSON_BOOL_TEXT "Boolean"
#define CXPATHJSON_NUMBER_TEXT "Number"
#define CXPATHJSON_OBJECT_TEXT "Object"
#define CXPATHJSON_ARRAY_TEXT "Array"


int CxpathJson_type(CxpathJson * self, const char *format, ...);

bool CxpathJson_exist(CxpathJson * self, const char *format, ...);

bool CxpathJson_its_not_null(CxpathJson * self, const char *format, ...);

bool CxpathJson_its_iterable(CxpathJson * self, const char *format, ...);

const char * CxpathJson_type_str(CxpathJson * self, const char *format, ...);
