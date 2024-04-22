
typedef struct {


    int  (*size)(LuaCEmbed *self);
    int  (*get_type)(LuaCEmbed *self,int index);
    long (*get_long)(LuaCEmbed *self, int index);
    double (*get_double)(LuaCEmbed *self, int index);
    bool (*get_bool)(LuaCEmbed *self, int index);
    char * (*get_str)(LuaCEmbed *self, int index);
    int  (*get_total_args)(LuaCEmbed *self);
    LuaCEmbedTable  * (*get_table)(LuaCEmbed *self,int index);
    long (*generate_arg_clojure_evalation)(LuaCEmbed *self,int index,char *code,...);
    long (*get_type_clojure_evalation)(LuaCEmbed *self,int index,char *code,...);
    long (*get_long_arg_clojure_evalation)(LuaCEmbed *self,int index,char *code,...);
    double (*get_double_arg_clojure_evalation)(LuaCEmbed *self,int index,char *code,...);
    bool (*get_bool_arg_clojure_evalation)(LuaCEmbed *self,int index,char *code,...);
    char* (*get_string_arg_clojure_evalation)(LuaCEmbed *self,int index,char *code,...);



} LuaCembedArgsModule;

LuaCembedArgsModule newLuaCembedArgsModule();