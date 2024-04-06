

CxpathJsonTypeNamespace newCxpathJsonTypeNamespace(void){
    CxpathJsonTypeNamespace self;
    self.NOT_FOUND = CXPATHJSON_NOT_FOUND;
    self.NULL_TYPE = CXPATHJSON_NULL;
    self.BOOL_TYPE = CXPATHJSON_BOOL;
    self.NUMBER_TYPE = CXPATHJSON_NUMBER;
    self.STRING_TYPE = CXPATHJSON_STRING;
    self.ARRAY_TYPE =CXPATHJSON_ARRAY;
    self.OBJECT_TYPE = CXPATHJSON_OBJECT;

    self.exist = CxpathJson_exist;
    self.type = CxpathJson_type;
    self.its_not_null = CxpathJson_its_not_null;
    self.its_iterable = CxpathJson_its_iterable;
    self.type_str = CxpathJson_type_str;
    return self;
}