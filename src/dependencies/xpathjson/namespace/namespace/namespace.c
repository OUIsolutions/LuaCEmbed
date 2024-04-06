

CxpathJsonNamespace newCxpathJsonNamespace(){
    CxpathJsonNamespace self;

    self.new_from_cJSON_by_reference = newCxpathJson_from_cJSON_by_reference;
    self.dump_to_file =CxpathJson_dump_to_file;
    self.dump_to_string = CxpathJson_dump_to_string;
    self.new_from_cJSON = newCxpathJson_from_cJSON_getting_ownership;
    self.newJsonObject = newCxpathJsonObject;
    self.newJsonArray = newCxpathJsonArray;
    self.new_from_string = newCxpathJson_from_string;
    self.new_from_file = newCxpathJson_from_file;

    self.get_bool = CxpathJson_get_bool;
    self.get_cJSON = CxpathJson_get_cJSON;
    self.get_double = CxpathJson_get_double;
    self.get_int = CxpathJson_get_int;
    self.get_str  = CxpathJson_get_str;
    self.get_object = CxpathJson_get_object;
    self.get_array = CxpathJson_get_array;
    self.get_key = CxpathJson_get_key;
    self.size = CxpathJson_get_size;


    self.set_bool = CxpathJson_set_bool;
    self.set_int = CxpathJson_set_int;
    self.set_double = CxpathJson_set_double;
    self.set_str  = CxpathJson_set_str;
    self.set_str_getting_ownership = CxpathJson_set_str_getting_ownership;
    self.set_cjson_getting_ownership = CxpathJson_set_cjson_getting_ownership;

    self.set_xpathJson_getting_onwership =CxpathJson_set_xpathJson_getting_onwership;
    self.set_xpath_by_reference = CxpathJson_set_xpath_by_reference;

    self.set_empty_array = CxpathJson_set_empty_array;
    self.set_empty_object = CxpathJson_set_empty_object;

    self.set_default_bool = CxpathJson_set_default_bool;
    self.set_default_int = CxpathJson_set_default_int;
    self.set_default_double = CxpathJson_set_default_double;
    self.set_default_str = CxpathJson_set_default_str;
    self.set_default_str_getting_onwership = CxpathJson_set_default_str_getting_onwership;
    self.set_default_cjson_getting_ownership = CxpathJson_set_default_cjson_getting_ownership;

    self.destroy = CxpathJson_destroy;


    self.free = CxpathJson_free;
    self.errors = newCxpathJsonErrorNamespace();
    self.types = newCxpathJsonTypeNamespace();
    return self;
}