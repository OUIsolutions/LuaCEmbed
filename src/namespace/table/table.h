
typedef struct {

    void (*set_method)(LuaCEmbedTable *self , const char *name, LuaCEmbedResponse *(*callback)(LuaCEmbedTable  *self, LuaCEmbed *args));
    void  (*set_string_prop)(LuaCEmbedTable *self , const char *name, const char *value);
    void  (*set_long_prop)(LuaCEmbedTable *self , const char *name, long  value);
    void  (*set_double_prop)(LuaCEmbedTable *self , const char *name, double  value);
    void  (*set_bool_prop)(LuaCEmbedTable *self , const char *name, bool value);

}LuaCembedTableModule;

LuaCembedTableModule newLuaCembedTableModule();
