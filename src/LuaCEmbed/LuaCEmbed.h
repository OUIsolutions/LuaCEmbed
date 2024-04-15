
typedef struct LuaCEmbed{
    lua_State *state;
    char *error_message;
    char *current_function;
    bool is_lib;
    bool public_functions;
    void *opt_args;
    bool runing;
    void (*delelte_function)(struct  LuaCEmbed *self);
}LuaCEmbed;


LuaCEmbed  *global_current_lua_embed_object;

