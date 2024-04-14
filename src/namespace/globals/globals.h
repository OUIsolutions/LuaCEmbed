

typedef struct {

    int (*ensure_type)(LuaCEmbed *self, const char *name,int expected_type);

    int (*get_type)(LuaCEmbed *self,const char *name);
    long (*get_long)(LuaCEmbed *self,const char *name);
    double (*get_double)(LuaCEmbed *self,const char *name);
    bool (*get_bool)(LuaCEmbed *self,const char *name);
    char * (*get_string)(LuaCEmbed *self,const char *name);
    int  (*get_evaluation_type)(LuaCEmbed *self, char *code);
    char * (*get_evaluation_string)(LuaCEmbed *self, char *code);
    long (*get_evaluation_size)(LuaCEmbed *self, char *code);
    long (*get_evaluation_long)(LuaCEmbed *self, char *code);
    double (*get_evaluation_double)(LuaCEmbed *self, char *code);
    bool (*get_evaluation_bool)(LuaCEmbed *self, char *code);


    void (*set_string)(LuaCEmbed *self,const char *name,const  char *value);
    void (*set_long)(LuaCEmbed *self,const char *name,long value);
    void (*set_double)(LuaCEmbed *self,const char *name,double value);
    void (*set_bool)(LuaCEmbed *self,const char *name,bool value);


}LuaCEmbedGlobalModule;

LuaCEmbedGlobalModule newLuaCEmbedGlobalModule();