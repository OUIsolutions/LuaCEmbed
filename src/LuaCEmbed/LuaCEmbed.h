
typedef struct{
    lua_State *state;
    char *error_message;
    char *current_function;
    void *opt_args;
}LuaCEmbed;



LuaCEmbed  *timeout_handler;
