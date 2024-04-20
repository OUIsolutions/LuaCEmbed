typedef struct privateLuaCembedTableIteration {
    LuaCEmbed  *embed_obj;
    privateLuaEmbedTableArgs *args;
    char *location;
    char *str_result;
    double num_result;
    void (*callback)(struct  privateLuaCembedTableIteration *self );

} privateLuaCembedTableIteration;

