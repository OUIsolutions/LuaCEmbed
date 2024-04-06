

CxpathJsonErrorNamespace newCxpathJsonErrorNamespace(){
    CxpathJsonErrorNamespace self = {0};
    self.get_error_code = CxpathJson_get_error_code;
    self.get_error_message = CxpathJson_get_error_message;
    self.get_error_path =CxpathJson_get_error_path;
    self.clear_errors = CxpathJson_clear_errors;
    self.has_errors = CxpathJson_has_errors;
    self.is_ok = CxpathJson_is_ok;
    self.raise_errror = CxpathJson_raise_errror;
    return  self;
}