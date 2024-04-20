


privateLuaCembedTableIteration * nwqprivateLuaCembedTableIteration(LuaCEmbed *embed_obj);

void privateLuaCembedTableIteration_run_iteration(privateLuaCembedTableIteration *self, int index);

int  privateLuaCembedTableIteration_set_args_code(privateLuaCembedTableIteration *self,const char *code,va_list args);


void  privateLuaCembedTableIteration_set_location(privateLuaCembedTableIteration *self,const char *format,...);



void privateLuaCembedTableIteration_free(privateLuaCembedTableIteration *self);