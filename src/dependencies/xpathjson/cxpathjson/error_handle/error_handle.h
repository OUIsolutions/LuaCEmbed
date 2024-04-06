#define CXPATH_ERROR_NUM_RETURN (-1)
#define  CXPATHJSON_OK_CODE 0
#define CXPATHJSON_GENERIC_ERROR 1

#define  CXPATHJSON_FILE_NOT_FOUND_CODE 2
#define  CXPATHJSON_STRING_NOT_PARSABLE_CODE 3
#define  CXPATHJSON_ARG_PATH_NOT_VALID_CODE 4
#define  CXPATHJSON_ELEMENT_PATH_NOT_EXIST_CODE 5
#define  CXPATHJSON_MIDDLE_ELEMENT_ITS_NOT_OBJECT_CODE 6

#define  CXPATHJSON_MIDDLE_ELEMENT_ITS_NOT_ITERABLE_CODE 7

#define  CXPATHJSON_MIDDLE_ELEMENT_ITS_NOT_ARRAY_CODE 8
#define  CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_CODE 9
#define  CXPATHJSON_IO_PROBLEM_CODE 12
#define XPATH_JSON_ELEMENT_NOT_HAVE_KEY_CODE 13
#define XPATH_JSON_ELEMENT_NOT_HAVE_KEY_MESSAGE "element does not have a key"


#define  PRIVATE_CXPATHJSON_FILE_NOT_FOUND_MESSAGE "file %s  not exist"
#define PRIVATE_CXPATHJSON_ARG_PATH_NOT_VALID_MESSAGE "path %s its not well formated"
#define PRIVATE_CXPATHJSON_APPEND_NOT_VALID_ON_READ_ONLY_FUNCTION_MESSAGE  \
"append its not valid on read only function on path %s"

#define  PRIVATE_CXPATHJSON_ELEMENT_HAS_WRONG_TYPE_MESSAGE "element has type %s instead of %s"
#define  PRIVATE_CXPATHJSON_MIDDLE_ELEMENT_ITS_NOT_ARRAY_MESSAGE "middle element  its not array"
#define  PRIVATE_CXPATHJSON_MIDDLE_ELEMENT_ITS_NOT_ITERABLE_MESSAGE "Middle element its not iterable"
#define  PRIVATE_CXPATHJSON_MIDDLE_ELEMENT_ITS_NOT_OBJECT_MESSAGE  "middle element its not a object"
#define  PRIVATE_CXPATHJSON_ELEMENT_PATH_NOT_EXIST_MESSAGE "Element not exist"
#define  PRIVATE_CXPATHJSON_STRING_NOT_PARSABLE_MESSAGE "string %s its not a valid json"
#define CXPATHJSON_IO_PROBLEM_MESSAGE "impossible to write in %s"


int CxpathJson_get_error_code(CxpathJson * self);

bool CxpathJson_has_errors(CxpathJson * self);

bool CxpathJson_is_ok(CxpathJson * self);

char * CxpathJson_get_error_message(CxpathJson * self);

char * CxpathJson_get_error_path(CxpathJson * self);


void CxpathJson_raise_errror(CxpathJson * self, int error_code, cJSON *path_list, const char *format, ...);


void CxpathJson_clear_errors(CxpathJson * self);