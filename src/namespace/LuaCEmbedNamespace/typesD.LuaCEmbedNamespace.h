//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesC.h"
//silver_chain_scope_end


typedef struct{
    LuaCEmbedTypeModule  types;
    LuaCEmbedResponseModule  response;
    LuaCembedArgsModule args;
    LuaCEmbedGlobalModule  globals;
    LuaCembedTableModule tables;
    void (*clear_errors)(LuaCEmbed *self);
    LuaCEmbed * (*newLuaLib)(lua_State *state);
    void (*set_delete_function)(LuaCEmbed *self,void (*delelte_function)(struct  LuaCEmbed *self));
    LuaCEmbed * (*newLuaEvaluation)();
    void (*load_native_libs)(LuaCEmbed *self);
    void (*load_lib_from_c)(LuaCEmbed *self,int (*callback)(lua_State *l),const char *name);
    int (*perform)(LuaCEmbed *self);
    int (*send_self_as_lib)(LuaCEmbed *self);
    int (*send_global_as_lib)(LuaCEmbed *self,const char *global_name);

    const char * (*convert_arg_code)(int arg_code);
    void (*set_memory_limit)(LuaCEmbed *self, double limit);

    char * (*get_error_message)(LuaCEmbed *self);
    bool (*has_errors)(LuaCEmbed *self);
    void (*set_timeout)(int seconds);
    int (*evaluate)(LuaCEmbed *self, const char *code, ...);
    char * (*get_string_evaluation)(LuaCEmbed *self,const char *code, ...);
    int  (*get_evaluation_type)(LuaCEmbed *self,const char *code,...);
    long (*get_evaluation_size)(LuaCEmbed *self,const char *code,...);
    long long  (*get_evaluation_long)(LuaCEmbed *self,const char *code,...);
    double (*get_evaluation_double)(LuaCEmbed *self,const char *code,...);
    bool (*get_evaluation_bool)(LuaCEmbed *self, const char *code,...);

    void (*set_long_lib_prop)(LuaCEmbed *self,const char *name,lua_Integer value);

    void (*set_double_lib_prop)(LuaCEmbed *self,const char *name,double value);
    void (*set_bool_lib_prop)(LuaCEmbed *self,const char *name,bool value);
    void (*set_string_lib_prop)(LuaCEmbed *self,const char *name,const char * value);
    void (*set_table_lib_prop)(LuaCEmbed *self,const char *name,LuaCEmbedTable *value);

    lua_Integer  (*get_long_lib_prop)(LuaCEmbed *self,const char *name);
    double (*get_double_lib_prop)(LuaCEmbed *self,const char *name);
    bool (*get_bool_lib_prop)(LuaCEmbed *self,const char *name);
    char * (*get_string_lib_prop)(LuaCEmbed *self,const char *name);
    LuaCEmbedTable *(*get_table_lib_prop)(LuaCEmbed *self,const char *name);

    int (*evaluete_file)(LuaCEmbed *self, const char *file);
    void (*add_callback)(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) );
    void (*add_global_callback)(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) );

    void (*dangerous_raise_error_jumping)(LuaCEmbed *self,const char *error_msg,...);
    void (*dangerous_raise_self_error_jumping)(LuaCEmbed *self);

    void (*free)(LuaCEmbed *self);

} LuaCEmbedNamespace;
