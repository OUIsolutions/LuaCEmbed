
typedef struct {

    void  (*append_string)(LuaCEmbedTable *self,  const char *value);
    void  (*append_long)(LuaCEmbedTable *self,  long  value);
    void  (*append_double)(LuaCEmbedTable *self, double  value);
    void  (*append_bool)(LuaCEmbedTable *self,  bool value);
    void  (*append_table)(LuaCEmbedTable *self, LuaCEmbedTable *table);
    void  (*set_evaluation_prop)(LuaCEmbedTable *self, const char *name, const char *code, ...);
    void  (*append_evaluation)(LuaCEmbedTable *self, const char *code, ...);


    void (*set_method)(LuaCEmbedTable *self , const char *name, LuaCEmbedResponse *(*callback)(LuaCEmbedTable  *self, LuaCEmbed *args));
    void  (*set_string_prop)(LuaCEmbedTable *self , const char *name, const char *value);
    void  (*set_long_prop)(LuaCEmbedTable *self , const char *name, long  value);
    void  (*set_double_prop)(LuaCEmbedTable *self , const char *name, double  value);
    void  (*set_bool_prop)(LuaCEmbedTable *self , const char *name, bool value);
    int  (*get_type_prop)(LuaCEmbedTable *self, const char *name);
    char*  (*get_string_prop)(LuaCEmbedTable *self , const char *name);
    long  (*get_long_prop)(LuaCEmbedTable *self , const char *name);
    double  (*get_double_prop)(LuaCEmbedTable *self , const char *name);
    bool  (*get_bool_prop)(LuaCEmbedTable *self , const char *name);

    LuaCEmbedTable * (*new_anonymous_table)(LuaCEmbed *self);

    LuaCEmbedTable  *(*get_sub_table_auto_creating)(LuaCEmbedTable *self, const char *name);
    LuaCEmbedTable  *(*new_sub_table)(LuaCEmbedTable *self, const char *name);
    void (*set_sub_table)(LuaCEmbedTable *self,const char *name,LuaCEmbedTable *sub_table);

    char *(*get_key_by_index)(LuaCEmbedTable *self, long index);
    bool (*has_key)(LuaCEmbedTable *self,long index);

    long  (*get_size)(LuaCEmbedTable *self);
    int (*get_type_by_index)(LuaCEmbedTable *self, int index);
    long (*get_long_by_index)(LuaCEmbedTable *self, int index);
    double (*get_double_by_index)(LuaCEmbedTable *self, int index);
    char * (*get_string_by_index)(LuaCEmbedTable *self, int index);
    bool (*get_bool_by_index)(LuaCEmbedTable *self, int index);

}LuaCembedTableModule;

LuaCembedTableModule newLuaCembedTableModule();
