

typedef struct {



    int  (*get_arg_type)(LuaCEmbed *self, int index,const char *expresion,...);
    char *  (*get_arg_string)(LuaCEmbed *self, int index,const char *expresion,...);
    long (*get_arg_long)(LuaCEmbed *self, int index,const char *expresion,...);
    long (*get_arg_size)(LuaCEmbed *self, int index,const char *expresion,...);
    double (*get_arg_double)(LuaCEmbed *self, int index,const char *expresion,...);
    bool (*get_arg_bool)(LuaCEmbed *self, int index,const char *expresion,...);


}LuaCEmbedArgsTableModule;

LuaCEmbedArgsTableModule newLuaCEmbedArgsTableModule();