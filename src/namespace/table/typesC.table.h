//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesB.h"
//silver_chain_scope_end

typedef struct {

    void  (*append_string)(LuaCEmbedTable *self,  const char *value);
    void  (*append_long)(LuaCEmbedTable *self, lua_Integer  value);
    void  (*append_double)(LuaCEmbedTable *self, double  value);
    void  (*append_bool)(LuaCEmbedTable *self,  bool value);
    void  (*append_table)(LuaCEmbedTable *self, LuaCEmbedTable *table);
    void  (*set_evaluation_prop)(LuaCEmbedTable *self, const char *name, const char *code, ...);
    void  (*append_evaluation)(LuaCEmbedTable *self, const char *code, ...);

    void  (*insert_string_at_index)(LuaCEmbedTable *self, lua_Integer index, const char *value);
    void  (*insert_bool_at_index)(LuaCEmbedTable *self, lua_Integer index,bool value);
    void  (*insert_long_at_index)(LuaCEmbedTable *self, lua_Integer  index,lua_Integer value);
    void  (*insert_double_at_index)(LuaCEmbedTable *self, lua_Integer index,double value);
    void  (*insert_table_at_index)(LuaCEmbedTable *self, lua_Integer index,LuaCEmbedTable *table);



    void (*set_sub_table_by_index)(LuaCEmbedTable *self, lua_Integer index,LuaCEmbedTable *sub_table);
    void  (*set_string_by_index)(LuaCEmbedTable *self, lua_Integer index, const char *value);
    void  (*set_raw_string_by_index)(LuaCEmbedTable *self, lua_Integer index, const char *value,lua_Integer size);
    void  (*set_long_by_index)(LuaCEmbedTable *self, lua_Integer index, lua_Integer  value);
    void  (*set_double_by_index)(LuaCEmbedTable *self, lua_Integer index, double  value);
    void  (*set_bool_by_index)(LuaCEmbedTable *self, lua_Integer index, bool value);
    void  (*set_evaluation_by_index)(LuaCEmbedTable *self, lua_Integer index, const char *code, ...);
    lua_Integer  (*get_listable_size)(LuaCEmbedTable *self);
    LuaCEmbedTable  *(*get_sub_table_by_index)(LuaCEmbedTable *self, lua_Integer index);

    LuaCEmbedTable  *(*new_sub_table_appending)(LuaCEmbedTable *self);

    void (*set_method)(LuaCEmbedTable *self , const char *name, LuaCEmbedResponse *(*callback)(LuaCEmbedTable  *self, LuaCEmbed *args));
    void  (*set_string_prop)(LuaCEmbedTable *self , const char *name, const char *value);
    void  (*set_raw_string_prop)(LuaCEmbedTable *self , const char *name, const char *value,lua_Integer size);

    void  (*set_long_prop)(LuaCEmbedTable *self , const char *name,lua_Integer   value);
    void  (*set_double_prop)(LuaCEmbedTable *self , const char *name, double  value);
    void  (*set_bool_prop)(LuaCEmbedTable *self , const char *name, bool value);
    int  (*get_type_prop)(LuaCEmbedTable *self, const char *name);
    char*  (*get_string_prop)(LuaCEmbedTable *self , const char *name);
    char*  (*get_raw_string_prop)(LuaCEmbedTable *self, const char *name,lua_Integer *size);
    lua_Integer  (*get_long_prop)(LuaCEmbedTable *self , const char *name);
    double  (*get_double_prop)(LuaCEmbedTable *self , const char *name);
    bool  (*get_bool_prop)(LuaCEmbedTable *self , const char *name);
    LuaCEmbedTable * (*new_anonymous_table)(LuaCEmbed *self);
    void (*destroy_prop)(LuaCEmbedTable *self, const char *name);

    LuaCEmbedTable  *(*get_sub_table_prop)(LuaCEmbedTable *self, const char *name);
    LuaCEmbedTable  *(*new_sub_table_prop)(LuaCEmbedTable *self, const char *name);
    void (*set_sub_table_prop)(LuaCEmbedTable *self, const char *name, LuaCEmbedTable *sub_table);
    char *(*get_key_by_index)(LuaCEmbedTable *self, lua_Integer index);
    bool (*has_key)(LuaCEmbedTable *self,lua_Integer index);

    lua_Integer  (*get_size)(LuaCEmbedTable *self);
    int (*get_type_by_index)(LuaCEmbedTable *self, lua_Integer index);
    lua_Integer (*get_long_by_index)(LuaCEmbedTable *self, lua_Integer index);
    double (*get_double_by_index)(LuaCEmbedTable *self, lua_Integer index);
    char * (*get_string_by_index)(LuaCEmbedTable *self, lua_Integer index);
    char * (*get_raw_string_by_index)(LuaCEmbedTable *self, lua_Integer index, lua_Integer *size);

    bool (*get_bool_by_index)(LuaCEmbedTable *self, lua_Integer index);

}LuaCembedTableModule;
