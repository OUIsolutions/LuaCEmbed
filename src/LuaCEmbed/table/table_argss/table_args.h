
typedef  struct {
    LuaCEmbed  *element;
    int index;
    int current_type;
    long current_value;
    char *formated_code;
    char *current_value_str;

    int size;

}privateLuaEmbedTableArgs;



privateLuaEmbedTableArgs * newprivateLuaEmbedTableArgs(const char *code,va_list  args);

void privateLuaEmbedTableArgs_next(privateLuaEmbedTableArgs *self);

bool private_LuaCembed_is_the_last_index(privateLuaEmbedTableArgs *self);

bool privateLuaEmbedTableArgs_is_the_current_index(
        privateLuaEmbedTableArgs *self,
        long current_iteration,
        long total_elements,
        const char *possible_key
        );


void privateLuaEmbedTableArgs_free(privateLuaEmbedTableArgs *self);
