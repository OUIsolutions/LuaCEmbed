#define CXPATHJSON_NOT_FOUND (-1)

#define CXPATHJSON_NULL 1

#define CXPATHJSON_STRING 2
#define CXPATHJSON_BOOL 3
#define CXPATHJSON_NUMBER 4
#define CXPATHJSON_OBJECT 5
#define CXPATHJSON_ARRAY 6
typedef struct{

     int NOT_FOUND;
     int NULL_TYPE;
     int STRING_TYPE;
     int BOOL_TYPE;
     int NUMBER_TYPE;
     int OBJECT_TYPE;
     int ARRAY_TYPE;


    int (*type)(CxpathJson * self, const char *format, ...);
    bool (*exist)(CxpathJson * self, const char *format, ...);
    bool (*its_not_null)(CxpathJson * self, const char *format, ...);
    bool (*its_iterable)(CxpathJson * self, const char *format, ...);

    const char * (*type_str)(CxpathJson * self, const char *format, ...);
}CxpathJsonTypeNamespace;


CxpathJsonTypeNamespace newCxpathJsonTypeNamespace(void);