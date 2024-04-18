

typedef struct privateLuaCembedTableIteration {
    LuaCEmbed  *embed_obj;
    privateLuaEmbedTableArgs *args;
    char *location;
    void (*callback)(struct  privateLuaCembedTableIteration *self )

}privateLuaCembedTableIteration;


privateLuaCembedTableIteration * nwqprivateLuaCembedTableIteration(LuaCEmbed *embed_obj);

int  privateLuaCembedTableIteration_set_args_code(privateLuaCembedTableIteration *self,const char *code,va_list args);

void  privateLuaCembedTableIteration_set_location(privateLuaCembedTableIteration *self,const char *format,...);


char * privateLuaCembedTableIteration_get_str(privateLuaCembedTableIteration *self,int index );



void privateLuaCembedTableIteration_free(privateLuaCembedTableIteration *self);