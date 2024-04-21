
typedef struct {
    void (*set_method)(LuaCembedTable *self ,const char *name,LuaCEmbedResponse *(*callback)(LuaCembedTable  *self,LuaCEmbed *args));
    void  (*set_string_prop)(LuaCembedTable *self ,const char *name,const char *value);
    void  (*set_long_prop)(LuaCembedTable *self ,const char *name,long  value);
    void  (*set_double_prop)(LuaCembedTable *self ,const char *name,double  value);
    void  (*set_bool_prop)(LuaCembedTable *self ,const char *name,bool value);

}LuaCembedTableModule;

LuaCembedTableModule newLuaCembedTableModule();
