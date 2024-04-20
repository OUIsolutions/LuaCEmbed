

typedef struct {
    LuaCEmbed  *main_object;
    char  *global_buffer;

}LuaCembedTable;

LuaCembedTable * newLuaCembedTable(LuaCEmbed *main_object,const char *format, va_list  args);

void  LuaCembedTable_set_string_prop(LuaCembedTable *self ,const char *name,const char *value);

void  LuaCembedTable_set_long_prop(LuaCembedTable *self ,const char *name,long  value);

void  LuaCembedTable_set_double_prop(LuaCembedTable *self ,const char *name,double  value);

void  LuaCembedTable_set_bool_prop(LuaCembedTable *self ,const char *name,bool value);


