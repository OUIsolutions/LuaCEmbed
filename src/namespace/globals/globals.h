

typedef struct {

    int (*ensure_type)(LuaCEmbed *self, const char *name,int expected_type);
    int (*get_type)(LuaCEmbed *self,const char *name);
    long (*get_long)(LuaCEmbed *self,const char *name);
    double (*get_double)(LuaCEmbed *self,const char *name);
    bool (*get_bool)(LuaCEmbed *self,const char *name);
    char * (*get_string)(LuaCEmbed *self,const char *name);

    void (*set_string)(LuaCEmbed *self,const char *name,const  char *value);
    void (*set_long)(LuaCEmbed *self,const char *name,long value);
    void (*set_double)(LuaCEmbed *self,const char *name,double value);
    void (*set_bool)(LuaCEmbed *self,const char *name,bool value);

    LuaCEmbedTable * (*get_table)(LuaCEmbed *self, const char *name);
    LuaCEmbedTable * (*new_table)(LuaCEmbed *self, const char *name);


}LuaCEmbedGlobalModule;

LuaCEmbedGlobalModule newLuaCEmbedGlobalModule();