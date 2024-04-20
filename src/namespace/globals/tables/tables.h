
typedef struct {

    long (*get_long)(LuaCEmbed *self,const char *name,const char *format, ...);
    double (*get_double)(LuaCEmbed *self,const char *name,const char *format, ...);
    char *(*get_string)(LuaCEmbed *self,const char *name,const char *format, ...);
    bool (*get_bool)(LuaCEmbed *self,const char *name,const char *format, ...);
    int  (*get_type)(LuaCEmbed *self,const char *name,const char *format, ...);
    long  (*get_size)(LuaCEmbed *self,const char *name,const char *format, ...);


}LuaCEmbedGlobalTableModule;

LuaCEmbedGlobalTableModule newLuaCEmbedGlobalTableModule();