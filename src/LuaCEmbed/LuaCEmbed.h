
typedef struct{
    lua_State *state;
    char *error_message;
    char *current_function;
}LuaCEmbed;



LuaCEmbed  *timeout_handler;
