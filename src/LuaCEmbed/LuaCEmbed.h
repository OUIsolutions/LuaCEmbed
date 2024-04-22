
typedef struct LuaCEmbed{
    lua_State *state;
    char *error_message;
    const char *current_function;
    bool is_lib;
    bool public_functions;
    int total_args;

    bool runing;
    void (*delelte_function)(struct  LuaCEmbed *self);
    void *current_table;
    void *global_tables;
    void *func_tables;
}LuaCEmbed;


LuaCEmbed  *global_current_lua_embed_object;

