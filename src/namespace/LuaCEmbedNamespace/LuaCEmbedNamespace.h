

typedef struct{
    LuaCEmbedTypeModule  types;
    LuaCEmbedResponseModule  response;
    LuaCembedArgsModule args;
    LuaCEmbed * (*newLuaCEmbed)();
    char * (*get_error_message)(LuaCEmbed *self);
    bool (*has_errors)(LuaCEmbed *self);
    void (*raise_error)(LuaCEmbed *self, const char *error);
    void (*set_timeout)(LuaCEmbed *self,int seconds);
    int (*evaluate_string)(LuaCEmbed *self, const char *str);
    int (*evaluete_file)(LuaCEmbed *self, const char *file);
    void (*add_callback)(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) );
    void (*free)(LuaCEmbed *self);

} LuaCEmbedNamespace;

LuaCEmbedNamespace newLuaCEmbedNamespace();

