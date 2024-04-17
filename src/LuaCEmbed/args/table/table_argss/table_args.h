
typedef  struct {
    LuaCEmbed  *element;
    int index;
    int size;

}privateLuaEmbedTableArgs;


privateLuaEmbedTableArgs * newprivateLuaEmbedTableArgs(const char *code,va_list  args);

void privateLuaEmbedTableArgs_free(privateLuaEmbedTableArgs *self);