
typedef struct {


    int  (*size)(LuaCEmbed *self);
    int  (*get_type)(LuaCEmbed *self,int index);
    long (*get_long)(LuaCEmbed *self, int index);
    double (*get_double)(LuaCEmbed *self, int index);
    bool (*get_bool)(LuaCEmbed *self, int index);
    char * (*get_str)(LuaCEmbed *self, int index);

    LuaCEmbedArgsTableModule table;


} LuaCembedArgsModule;

LuaCembedArgsModule newLuaCembedArgsModule();