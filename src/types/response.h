#ifndef PRIVATE_LUACEMBED_RESPONSE_TYPE
#define PRIVATE_LUACEMBED_RESPONSE_TYPE

typedef struct {

    int type;
    double num_val;
    bool its_string_ref;
    long string_size;
    char *string_val;

}LuaCEmbedResponse;

#endif
