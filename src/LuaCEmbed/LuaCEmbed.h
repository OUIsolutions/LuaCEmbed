
typedef struct{
    lua_State *state;
    char *error_message;
    char *current_function;
    void *opt_args;
    bool runing;
}LuaCEmbed;



LuaCEmbed  *global_current_lua_embed_object;
