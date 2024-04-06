

char *CxpathJson_dump_to_string(CxpathJson  *self, bool ident){
    if(CxpathJson_has_errors(self)){
        return NULL;
    }

    if(ident){
        return cJSON_Print(self->element);
    }
    return cJSON_PrintUnformatted(self->element);
}


void CxpathJson_dump_to_file(CxpathJson  *self, const char *filename, bool ident){

    if(CxpathJson_has_errors(self)){
        return ;
    }

    char *result = CxpathJson_dump_to_string(self, ident);
    int write_result = private_cxpathjson_write_file(filename, result);
    if(write_result == CXPATHJSON_IO_PROBLEM_CODE){
        CxpathJson_raise_errror(
                self,
                CXPATHJSON_IO_PROBLEM_CODE,
                NULL,
                CXPATHJSON_IO_PROBLEM_MESSAGE,
                filename
                );
    }
    free(result);
}


