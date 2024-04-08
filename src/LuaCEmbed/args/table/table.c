
cJSON * privateLuaCEmbed_parse_args(const char *format, va_list args){
    char buffer[2000] = {0};
    vsnprintf(buffer, sizeof(buffer), format, args);
    private_cxpathjson_replace_comas(buffer);
    cJSON *parsed_path  = cJSON_Parse(buffer);
    return parsed_path;
}


int  LuaCEmbed_get_table_element_type(LuaCEmbed *self,int index,const char *format ,...){

    if(LuaCEmbed_get_arg_type(self,index) != LUA_CEMBED_TABLE){
        return LUA_CEMBED_NOT_FOUND;
    }

    va_list args;
    va_start(args, format);
    cJSON *path_list = privateLuaCEmbed_parse_args(format,args);
    va_end(args);

    
    cJSON_Delete(path_list);



}
