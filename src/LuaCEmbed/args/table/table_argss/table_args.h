
typedef  struct {
    LuaCEmbed  *element;
    int index;
    int size;

}privateLuaEmbedTableArgs;



privateLuaEmbedTableArgs * newprivateLuaEmbedTableArgs(const char *code,va_list  args);

int privateLuaEmbedTableArgs_get_current_index_type(privateLuaEmbedTableArgs *self);

void privateLuaEmbedTableArgs_free(privateLuaEmbedTableArgs *self);