

typedef struct{
    LuaCEmbedTypeModule  types;
    LuaCEmbedResponseModule  response;
    LuaCembedArgsModule args;
    LuaCEmbedGlobalModule  globals;
    LuaCembedTableModule tables;
    LuaCEmbed * (*newLuaLib)(lua_State *state, bool public_functions);
    void (*set_delete_function)(LuaCEmbed *self,void (*delelte_function)(struct  LuaCEmbed *self));
    LuaCEmbed * (*newLuaEvaluation)();
    void (*perform)(LuaCEmbed *self);
    const char * (*convert_arg_code)(int arg_code);

    char * (*get_error_message)(LuaCEmbed *self);
    bool (*has_errors)(LuaCEmbed *self);
    void (*raise_error)(LuaCEmbed *self, const char *error,...);
    void (*set_timeout)(LuaCEmbed *self,int seconds);
    int (*evaluate_string)(LuaCEmbed *self, const char *code,...);

    char * (*get_string_evaluation)(LuaCEmbed *self, char *code, ...);
    int  (*get_evaluation_type)(LuaCEmbed *self, char *code,...);
    long (*get_evaluation_size)(LuaCEmbed *self, char *code,...);
    long (*get_evaluation_long)(LuaCEmbed *self, char *code,...);
    double (*get_evaluation_double)(LuaCEmbed *self, char *code,...);
    bool (*get_evaluation_bool)(LuaCEmbed *self, char *code,...);


    int (*evaluete_file)(LuaCEmbed *self, const char *file);
    void (*add_callback)(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) );
    void (*free)(LuaCEmbed *self);

} LuaCEmbedNamespace;

LuaCEmbedNamespace newLuaCEmbedNamespace();

