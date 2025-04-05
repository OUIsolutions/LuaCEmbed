

typedef struct {

    int type;
    double double_val;
    lua_Integer int_val;
    bool its_string_ref;
    lua_Integer string_size;
    char *string_val;

}LuaCEmbedResponse;
