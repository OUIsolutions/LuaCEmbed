
typedef struct LuaCEmbed{
    lua_State *state;
    const char *current_function;
    bool is_lib;
    bool public_functions;
    int total_args;
    char *error_msg;
    long memory_limit;
    int timeout;
    void (*delete_function)(struct  LuaCEmbed *self);
    void *global_tables;
    void *func_tables;
}LuaCEmbed;


LuaCEmbed  *global_current_lua_embed_object;

