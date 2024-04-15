
typedef struct{
    lua_State *state;
    char *error_message;
    char *current_function;
    bool is_lib;
    bool public_functions;
    void *opt_args;
    bool runing;
}LuaCEmbed;


LuaCEmbed  *global_current_lua_embed_object;

