

typedef struct privateLuaCembedTableIteration {
    LuaCEmbed  *embed_obj;
    privateLuaEmbedTableArgs *args;
    char *location;
    char *str_result;
    void (*callback)(struct  privateLuaCembedTableIteration *self );

} privateLuaCembedTableIteration;


privateLuaCembedTableIteration * nwqprivateLuaCembedTableIteration(LuaCEmbed *embed_obj);

void privateLuaCembedTableIteration_run_iteration(privateLuaCembedTableIteration *self, int index);

int  privateLuaCembedTableIteration_set_args_code(privateLuaCembedTableIteration *self,const char *code,va_list args);


void  privateLuaCembedTableIteration_set_location(privateLuaCembedTableIteration *self,const char *format,...);

void privateLuaCembedTableIteration_str_callback(privateLuaCembedTableIteration *self );

char * privateLuaCembedTableIteration_get_str(privateLuaCembedTableIteration *self,int index );



void privateLuaCembedTableIteration_free(privateLuaCembedTableIteration *self);