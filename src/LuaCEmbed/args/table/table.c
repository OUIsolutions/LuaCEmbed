
cJSON * privateLuaCEmbed_parse_args(const char *format, va_list args){
    char buffer[2000] = {0};
    vsnprintf(buffer, sizeof(buffer), format, args);
    private_cxpathjson_replace_comas(buffer);
    cJSON *parsed_path  = cJSON_Parse(buffer);

    if(!parsed_path){
        return  NULL;
    }

    if(!cJSON_IsArray(parsed_path)){
        cJSON_Delete(parsed_path);
        return  NULL;
    }

    int path_size = cJSON_GetArraySize(parsed_path);
    for(int i = 0;i <path_size;i++){
        cJSON *current = cJSON_GetArrayItem(parsed_path,i);

        if(cJSON_IsString(current)){

            continue;
        }

        if(cJSON_IsNumber(current)){
            continue;
        }

        cJSON_Delete(parsed_path);
        return  NULL;
    }

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

    if(!path_list){
        return LUA_CEMBED_INVALID_ARGS;
    }
    int size = cJSON_GetArraySize(path_list);
    for(int i = 0; i < size; i++){

        lua_pushnil(self->state);
        while (lua_next(self->state, index) != 0) {

            // Obtém a chave e o valor atual da tabela

            if (lua_isstring(L, -2)) {
                const char *chave = lua_tostring(L, -2);
                printf("%s:\n{",chave);

                if (lua_isstring(L, -1)) {
                    const char *valor = lua_tostring(L, -1);
                    printf("%s\n", valor);
                }

                else if (lua_istable(L,-1)) {

                    //printf("index %d\n",index);
                    iterate(L, lua_gettop(L));
                }
                printf("\n}");

            } else {
                printf("chave não é uma string\n");
            }
            lua_pop(L, 1); // Remove o valor, mantendo a chave na pilha para a próxima iteração
        }
    }
    cJSON_Delete(path_list);



}
