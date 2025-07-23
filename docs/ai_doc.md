
### Type Especification: 
~~~c 
// Public functions

int LuaCEmbed_ensure_arg_exist(LuaCEmbed *self, lua_Integer index);


lua_Integer LuaCEmbed_get_total_args(LuaCEmbed *self);

lua_Integer LuaCEmbed_get_arg_type(LuaCEmbed *self, lua_Integer index);

lua_Integer LuaCEmbed_get_long_arg(LuaCEmbed *self, lua_Integer index);

double LuaCEmbed_get_double_arg(LuaCEmbed *self, lua_Integer index);

bool LuaCEmbed_get_bool_arg(LuaCEmbed *self, lua_Integer index);

char *LuaCEmbed_get_str_arg(LuaCEmbed *self, lua_Integer index);

char *LuaCEmbed_get_raw_str_arg(LuaCEmbed *self, lua_Integer *size, lua_Integer index);

LuaCEmbedTable *LuaCEmbed_get_arg_table(LuaCEmbed *self, lua_Integer index);

LuaCEmbedTable *LuaCEmbed_run_args_lambda(LuaCEmbed *self, lua_Integer index, LuaCEmbedTable *args_to_call, lua_Integer total_returns);

LuaCEmbedTable *LuaCEmbed_transform_args_in_table(LuaCEmbed *self);
lua_Integer LuaCEmbed_get_type_clojure_evalation(LuaCEmbed *self,lua_Integer index,const char *code,...);

lua_Integer LuaCEmbed_generate_arg_clojure_evalation(LuaCEmbed *self,lua_Integer index,const char *code,...);

lua_Integer LuaCEmbed_get_long_arg_clojure_evalation(LuaCEmbed *self,lua_Integer index,const char *code,...);

double LuaCEmbed_get_double_arg_clojure_evalation(LuaCEmbed *self,lua_Integer index,const char *code,...);

bool LuaCEmbed_get_bool_arg_clojure_evalation(LuaCEmbed *self,lua_Integer index,const char *code,...);

char* LuaCEmbed_get_string_arg_clojure_evalation(LuaCEmbed *self,lua_Integer index,const char *code,...);
LuaCEmbed * newLuaCEmbedEvaluation();

void LuaCEmbed_load_lib_from_c(LuaCEmbed *self,int (*callback)(lua_State *l),const char *name);

void LuaCEmbed_load_native_libs(LuaCEmbed *self);

void LuaCembed_set_delete_function(LuaCEmbed *self,void (*delelte_function)(struct  LuaCEmbed *self));

void LuaCEmbed_set_timeout(int seconds);

void LuaCEmbed_free(LuaCEmbed *self);
void LuaCEmbed_add_callback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) );

void LuaCEmbed_add_global_callback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args));
char * LuaCEmbed_get_error_message(LuaCEmbed *self);

bool LuaCEmbed_has_errors(LuaCEmbed *self);

void LuaCEmbed_clear_errors(LuaCEmbed *self);

void LuaCEmbed_dangerous_raise_error_jumping(LuaCEmbed *self,const char *error_msg,...);

void LuaCEmbed_dangerous_raise_self_error_jumping(LuaCEmbed *self);

// Public Functions
int LuaCEmbed_evaluate(LuaCEmbed *self, const char *code, ...);
int LuaCEmbed_evaluete_file(LuaCEmbed *self, const char *file);
char * LuaCEmbed_get_evaluation_string(LuaCEmbed *self,const char *code, ...);
int LuaCEmbed_get_evaluation_type(LuaCEmbed *self,const char *code, ...);
long LuaCEmbed_get_evaluation_table_size(LuaCEmbed *self,const char *code, ...);
long long LuaCEmbed_get_evaluation_long(LuaCEmbed *self,const char *code, ...);
double LuaCEmbed_get_evaluation_double(LuaCEmbed *self,const char *code, ...);
bool LuaCEmbed_get_evaluation_bool(LuaCEmbed *self,const char *code, ...);

int LuaCEmbed_ensure_global_type(LuaCEmbed *self, const char *name, int expected_type);
int LuaCEmbed_get_global_type(LuaCEmbed *self, const char *name);

lua_Integer LuaCEmbed_get_global_long(LuaCEmbed *self, const char *name);

double LuaCEmbed_get_global_double(LuaCEmbed *self, const char *name);

bool LuaCEmbed_get_global_bool(LuaCEmbed *self, const char *name);

char *LuaCEmbed_get_global_string(LuaCEmbed *self, const char *name);

char *LuaCEmbed_get_global_raw_string(LuaCEmbed *self, const char *name, long *size);

LuaCEmbedTable *LuaCembed_new_anonymous_table(LuaCEmbed *self);

LuaCEmbedTable *LuaCEmbed_run_global_lambda(LuaCEmbed *self, const char *name, LuaCEmbedTable *args_to_call, int total_returns);

LuaCEmbedTable *LuaCembed_get_global_table(LuaCEmbed *self, const char *name);

LuaCEmbedTable *LuaCembed_new_global_table(LuaCEmbed *self, const char *name);
void LuaCEmbed_set_global_string(LuaCEmbed *self, const char *name, const char *value);

void LuaCEmbed_set_global_raw_string(LuaCEmbed *self, const char *name, const char *value, long size);

void LuaCEmbed_set_global_long(LuaCEmbed *self, const char *name, lua_Integer value);

void LuaCEmbed_set_global_double(LuaCEmbed *self, const char *name, double value);

void LuaCEmbed_set_global_bool(LuaCEmbed *self, const char *name, bool value);

void LuaCEmbed_set_global_table(LuaCEmbed *self, const char *name, LuaCEmbedTable *table);
void LuaCEmbed_set_long_lib_prop(LuaCEmbed *self, const char *name, lua_Integer value);

void LuaCEmbed_set_double_lib_prop(LuaCEmbed *self, const char *name, double value);

void LuaCEmbed_set_bool_lib_prop(LuaCEmbed *self, const char *name, bool value);

void LuaCEmbed_set_string_lib_prop(LuaCEmbed *self, const char *name, const char *value);

void LuaCEmbed_set_table_lib_prop(LuaCEmbed *self, const char *name, LuaCEmbedTable *value);

lua_Integer LuaCEmbed_get_long_lib_prop(LuaCEmbed *self, const char *name);

double LuaCEmbed_get_double_lib_prop(LuaCEmbed *self, const char *name);

bool LuaCEmbed_get_bool_lib_prop(LuaCEmbed *self, const char *name);

char *LuaCEmbed_get_string_lib_prop(LuaCEmbed *self, const char *name);

LuaCEmbedTable *LuaCEmbed_get_table_lib_prop(LuaCEmbed *self, const char *name);
LuaCEmbed * newLuaCEmbedLib(lua_State *state);

int  LuaCemb_perform(LuaCEmbed *self);

int LuaCembed_send_self_as_lib(LuaCEmbed *self);

int LuaCembed_send_global_as_lib(LuaCEmbed *self,const char *global_name);

void LuaCEmbed_set_memory_limit(LuaCEmbed *self, double limit);
void LuaCEmbedTable_append_table(LuaCEmbedTable *self, LuaCEmbedTable *table);

void LuaCEmbedTable_append_evaluation(LuaCEmbedTable *self, const char *code, ...);

void LuaCEmbedTable_append_string(LuaCEmbedTable *self, const char *value);

void LuaCEmbedTable_append_long(LuaCEmbedTable *self, lua_Integer value);

void LuaCEmbedTable_append_double(LuaCEmbedTable *self, double value);

void LuaCEmbedTable_append_bool(LuaCEmbedTable *self, bool value);

void LuaCEmbedTable_append_global(LuaCEmbedTable *self, const char *global_name);

void LuaCEmbedTable_append_arg(LuaCEmbedTable *self, int index);

void LuaCembedTable_destroy_prop(LuaCEmbedTable *self, const char *name);

void LuaCEmbedTable_destroy_by_index(LuaCEmbedTable *self, long index);

LuaCEmbedTable *LuaCEmbedTable_run_prop_function(LuaCEmbedTable *self, const char *prop, LuaCEmbedTable *args_to_call, int total_returns);

LuaCEmbedTable *LuaCEmbedTable_run_index_function(LuaCEmbedTable *self, lua_Integer index, LuaCEmbedTable *args_to_call, int total_returns);
char *LuaCembedTable_get_key_by_index(LuaCEmbedTable *self, lua_Integer index);

bool LuaCembedTable_has_key_at_index(LuaCEmbedTable *self, lua_Integer index);

lua_Integer LuaCEmbedTable_get_full_size(LuaCEmbedTable *self);

lua_Integer LuaCEmbedTable_get_listable_size(LuaCEmbedTable *self);

int LuaCEmbedTable_get_type_by_index(LuaCEmbedTable *self, lua_Integer index);

lua_Integer LuaCEmbedTable_get_long_by_index(LuaCEmbedTable *self, lua_Integer index);

double LuaCEmbedTable_get_double_by_index(LuaCEmbedTable *self, lua_Integer index);

char *LuaCEmbedTable_get_string_by_index(LuaCEmbedTable *self, lua_Integer index);

char *LuaCEmbedTable_get_raw_string_by_index(LuaCEmbedTable *self, lua_Integer index, lua_Integer *size);

bool LuaCEmbedTable_get_bool_by_index(LuaCEmbedTable *self, lua_Integer index);
char* LuaCembedTable_get_string_prop(LuaCEmbedTable *self, const char *name);

char* LuaCembedTable_get_raw_string_prop(LuaCEmbedTable *self, const char *name, lua_Integer *size);

lua_Integer LuaCembedTable_get_long_prop(LuaCEmbedTable *self, const char *name);

double LuaCembedTable_get_double_prop(LuaCEmbedTable *self, const char *name);

bool LuaCembedTable_get_bool_prop(LuaCEmbedTable *self, const char *name);

int LuaCEmbedTable_get_type_prop(LuaCEmbedTable *self, const char *name);

// Public Functions:

void LuaCEmbedTable_set_string_by_index(LuaCEmbedTable *self, lua_Integer index, const char *value);

void LuaCEmbedTable_set_raw_string_by_index(LuaCEmbedTable *self, lua_Integer index, const char *value, lua_Integer size);

void LuaCEmbedTable_set_long_by_index(LuaCEmbedTable *self, lua_Integer index, lua_Integer value);

void LuaCEmbedTable_set_double_by_index(LuaCEmbedTable *self, lua_Integer index, double value);

void LuaCEmbedTable_set_bool_by_index(LuaCEmbedTable *self, lua_Integer index, bool value);

void LuaCEmbedTable_set_evaluation_by_index(LuaCEmbedTable *self, lua_Integer index, const char *code, ...);

void LuaCEmbedTable_copy_index_to_global_var(LuaCEmbedTable *self, lua_Integer index, const char *name);

void LuaCEmbedTable_set_table_index_with_table_prop(LuaCEmbedTable *self, lua_Integer self_index, LuaCEmbedTable *table, const char *table_prop);

void LuaCEmbedTable_set_table_index_with_table_index(LuaCEmbedTable *self, lua_Integer self_index, LuaCEmbedTable *table, const char *table_index);
void LuaCEmbedTable_insert_string_at_index(LuaCEmbedTable *self, lua_Integer index, const char *value);

void LuaCEmbedTable_insert_bool_at_index(LuaCEmbedTable *self, lua_Integer index, bool value);

void LuaCEmbedTable_insert_long_at_index(LuaCEmbedTable *self, lua_Integer index, lua_Integer value);

void LuaCEmbedTable_insert_double_at_index(LuaCEmbedTable *self, lua_Integer index, double value);

void LuaCEmbedTable_insert_table_at_index(LuaCEmbedTable *self, lua_Integer index, LuaCEmbedTable *table);
void LuaCEmbedTable_set_method(LuaCEmbedTable *self, const char *name, LuaCEmbedResponse *(*callback)(LuaCEmbedTable *self, LuaCEmbed *args));

void LuaCEmbedTable_set_string_prop(LuaCEmbedTable *self, const char *name, const char *value);

void LuaCEmbedTable_set_raw_string_prop(LuaCEmbedTable *self, const char *name, const char *value, lua_Integer size);

void LuaCEmbedTable_set_long_prop(LuaCEmbedTable *self, const char *name, lua_Integer value);

void LuaCEmbedTable_set_double_prop(LuaCEmbedTable *self, const char *name, double value);

void LuaCEmbedTable_set_bool_prop(LuaCEmbedTable *self, const char *name, bool value);

void LuaCEmbedTable_set_evaluation_prop(LuaCEmbedTable *self, const char *name, const char *code, ...);

void LuaCEmbedTable_copy_prop_to_global_var(LuaCEmbedTable *self, const char *prop, const char *name);

void LuaCEmbedTable_set_table_prop_with_table_prop(LuaCEmbedTable *self, const char *self_prop, LuaCEmbedTable *table, const char *table_prop);

void LuaCEmbedTable_set_table_prop_with_table_index(LuaCEmbedTable *self, const char *self_prop, LuaCEmbedTable *table, const char *table_index);

void LuaCEmbedTable_set_table_prop_with_global(LuaCEmbedTable *self, const char *self_prop, const char *global_name);

LuaCEmbedTable *LuaCEmbedTable_new_sub_table_appending(LuaCEmbedTable *self);

LuaCEmbedTable *LuaCEmbedTable_get_sub_table_by_index(LuaCEmbedTable *self, lua_Integer index);

void LuaCEmbedTable_set_sub_table_by_index(LuaCEmbedTable *self, lua_Integer index, LuaCEmbedTable *sub_table);
LuaCEmbedTable *LuaCEmbedTable_new_sub_table_by_key(LuaCEmbedTable *self, const char *name);

LuaCEmbedTable *LuaCEmbedTable_get_sub_table_by_key(LuaCEmbedTable *self, const char *name);

void LuaCEmbedTable_set_sub_table_prop(LuaCEmbedTable *self, const char *name, LuaCEmbedTable *sub_table);

typedef struct {
    LuaCEmbed *main_object;
    char *prop_name;
    char *global_name;
    void *sub_tables;
    long index;
} LuaCEmbedTable;
typedef struct LuaCEmbed{
    lua_State *state;
    const char *current_function;
    bool is_lib;
    int total_args;
    char *error_msg;
    void (*delete_function)(struct  LuaCEmbed *self);
    void *global_tables;
    void *func_tables;
    int lib_identifier;
    int stack_leve;
    char *main_lib_table;
    bool field_protection;
}LuaCEmbed;
LuaCEmbedResponse *LuaCEmbed_send_str(const char *text);

LuaCEmbedResponse *LuaCEmbed_send_raw_string(const char *text, lua_Integer size);

LuaCEmbedResponse *LuaCEmbed_send_str_reference(const char *text);

LuaCEmbedResponse *LuaCEmbed_send_raw_string_reference(const char *text, lua_Integer size);

LuaCEmbedResponse *LuaCEmbed_send_error(const char *format, ...);

LuaCEmbedResponse *LuaCEmbed_send_evaluation(const char *code);

LuaCEmbedResponse *LuaCEmbed_send_double(double value);

LuaCEmbedResponse *LuaCEmbed_send_bool(bool value);

LuaCEmbedResponse *LuaCEmbed_send_long(lua_Integer value);

LuaCEmbedResponse *LuaCEmbed_send_table(LuaCEmbedTable *table);

LuaCEmbedResponse *LuaCEmbed_send_multi_return(LuaCEmbedTable *table);

typedef struct {

    int type;
    double double_val;
    lua_Integer int_val;
    bool its_string_ref;
    lua_Integer string_size;
    char *string_val;

    char *table_name;
    char *table_prop_name;
        
}LuaCEmbedResponse;

#ifndef LUA_CEMBED_INDEX_DIF
#define LUA_CEMBED_INDEX_DIF 1
#endif

#define LUA_CEMBED_DEFAULT_TIMEOUT 10
#define LUA_CEMBED_DEFAULT_MEMORY_LIMIT 100

#define LUA_CEMBED_OK 0
#define LUA_CEMBED_GENERIC_ERROR (-1)
#define LUA_CEMBED_NOT_FOUND LUA_TNONE
#define LUA_CEMBED_STRING LUA_TSTRING
#define LUA_CEMBED_NUMBER LUA_TNUMBER
#define LUA_CEMBED_BOOL LUA_TBOOLEAN
#define LUA_CEMBED_NIL LUA_TNIL
#define LUA_CEMBED_FUNCTION LUA_TFUNCTION
#define LUA_CEMBED_TABLE LUA_TTABLE

const char * LuaCembed_convert_arg_code(int arg_code);

LuaCEmbedNamespace newLuaCEmbedNamespace();

// Public Functions extracted from LuaCEmbedNamespace:

// Error handling functions
void clear_errors(LuaCEmbed *self);
char *get_error_message(LuaCEmbed *self);
bool has_errors(LuaCEmbed *self);
void dangerous_raise_error_jumping(LuaCEmbed *self, const char *error_msg, ...);
void dangerous_raise_self_error_jumping(LuaCEmbed *self);

// Constructor functions  
LuaCEmbed *newLuaLib(lua_State *state);
LuaCEmbed *newLuaEvaluation();

// Configuration functions
void set_delete_function(LuaCEmbed *self, void (*delelte_function)(struct LuaCEmbed *self));
void load_native_libs(LuaCEmbed *self);
void load_lib_from_c(LuaCEmbed *self, int (*callback)(lua_State *l), const char *name);
void set_memory_limit(LuaCEmbed *self, double limit);
void set_timeout(int seconds);

// Execution functions
int perform(LuaCEmbed *self);
int send_self_as_lib(LuaCEmbed *self);
int send_global_as_lib(LuaCEmbed *self, const char *global_name);
int evaluete_file(LuaCEmbed *self, const char *file);

// Evaluation functions
int evaluate(LuaCEmbed *self, const char *code, ...);
char *get_string_evaluation(LuaCEmbed *self, const char *code, ...);
int get_evaluation_type(LuaCEmbed *self, const char *code, ...);
long get_evaluation_size(LuaCEmbed *self, const char *code, ...);
long long get_evaluation_long(LuaCEmbed *self, const char *code, ...);
double get_evaluation_double(LuaCEmbed *self, const char *code, ...);
bool get_evaluation_bool(LuaCEmbed *self, const char *code, ...);

// Library property setters
void set_long_lib_prop(LuaCEmbed *self, const char *name, lua_Integer value);
void set_double_lib_prop(LuaCEmbed *self, const char *name, double value);
void set_bool_lib_prop(LuaCEmbed *self, const char *name, bool value);
void set_string_lib_prop(LuaCEmbed *self, const char *name, const char *value);
void set_table_lib_prop(LuaCEmbed *self, const char *name, LuaCEmbedTable *value);

// Library property getters
lua_Integer get_long_lib_prop(LuaCEmbed *self, const char *name);
double get_double_lib_prop(LuaCEmbed *self, const char *name);
bool get_bool_lib_prop(LuaCEmbed *self, const char *name);
char *get_string_lib_prop(LuaCEmbed *self, const char *name);
LuaCEmbedTable *get_table_lib_prop(LuaCEmbed *self, const char *name);

// Callback functions
void add_callback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse *(*callback)(LuaCEmbed *args));
void add_global_callback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse *(*callback)(LuaCEmbed *args));

// Utility functions
const char *convert_arg_code(int arg_code);

// Destructor function
void free(LuaCEmbed *self);

typedef struct{
    LuaCEmbedTypeModule  types;
    LuaCEmbedResponseModule  response;
    LuaCembedArgsModule args;
    LuaCEmbedGlobalModule  globals;
    LuaCembedTableModule tables;
    void (*clear_errors)(LuaCEmbed *self);
    LuaCEmbed * (*newLuaLib)(lua_State *state);
    void (*set_delete_function)(LuaCEmbed *self,void (*delelte_function)(struct  LuaCEmbed *self));
    LuaCEmbed * (*newLuaEvaluation)();
    void (*load_native_libs)(LuaCEmbed *self);
    void (*load_lib_from_c)(LuaCEmbed *self,int (*callback)(lua_State *l),const char *name);
    int (*perform)(LuaCEmbed *self);
    int (*send_self_as_lib)(LuaCEmbed *self);
    int (*send_global_as_lib)(LuaCEmbed *self,const char *global_name);

    const char * (*convert_arg_code)(int arg_code);
    void (*set_memory_limit)(LuaCEmbed *self, double limit);

    char * (*get_error_message)(LuaCEmbed *self);
    bool (*has_errors)(LuaCEmbed *self);
    void (*set_timeout)(int seconds);
    int (*evaluate)(LuaCEmbed *self, const char *code, ...);
    char * (*get_string_evaluation)(LuaCEmbed *self,const char *code, ...);
    int  (*get_evaluation_type)(LuaCEmbed *self,const char *code,...);
    long (*get_evaluation_size)(LuaCEmbed *self,const char *code,...);
    long long  (*get_evaluation_long)(LuaCEmbed *self,const char *code,...);
    double (*get_evaluation_double)(LuaCEmbed *self,const char *code,...);
    bool (*get_evaluation_bool)(LuaCEmbed *self, const char *code,...);

    void (*set_long_lib_prop)(LuaCEmbed *self,const char *name,lua_Integer value);

    void (*set_double_lib_prop)(LuaCEmbed *self,const char *name,double value);
    void (*set_bool_lib_prop)(LuaCEmbed *self,const char *name,bool value);
    void (*set_string_lib_prop)(LuaCEmbed *self,const char *name,const char * value);
    void (*set_table_lib_prop)(LuaCEmbed *self,const char *name,LuaCEmbedTable *value);

    lua_Integer  (*get_long_lib_prop)(LuaCEmbed *self,const char *name);
    double (*get_double_lib_prop)(LuaCEmbed *self,const char *name);
    bool (*get_bool_lib_prop)(LuaCEmbed *self,const char *name);
    char * (*get_string_lib_prop)(LuaCEmbed *self,const char *name);
    LuaCEmbedTable *(*get_table_lib_prop)(LuaCEmbed *self,const char *name);

    int (*evaluete_file)(LuaCEmbed *self, const char *file);
    void (*add_callback)(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) );
    void (*add_global_callback)(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) );

    void (*dangerous_raise_error_jumping)(LuaCEmbed *self,const char *error_msg,...);
    void (*dangerous_raise_self_error_jumping)(LuaCEmbed *self);

    void (*free)(LuaCEmbed *self);

} LuaCEmbedNamespace;
LuaCembedArgsModule newLuaCembedArgsModule();
typedef struct {
    lua_Integer (*size)(LuaCEmbed *self);
    lua_Integer (*get_type)(LuaCEmbed *self, lua_Integer index);
    lua_Integer (*get_long)(LuaCEmbed *self, lua_Integer index);
    double (*get_double)(LuaCEmbed *self, lua_Integer index);
    bool (*get_bool)(LuaCEmbed *self, lua_Integer index);
    char *(*get_raw_str)(LuaCEmbed *self, lua_Integer *size, lua_Integer index);
    char *(*get_str)(LuaCEmbed *self, lua_Integer index);
    LuaCEmbedTable *(*get_table)(LuaCEmbed *self, lua_Integer index);
    lua_Integer (*generate_arg_clojure_evalation)(LuaCEmbed *self, lua_Integer index, const char *code, ...);
    lua_Integer (*get_type_clojure_evalation)(LuaCEmbed *self, lua_Integer index, const char *code, ...);
    lua_Integer (*get_long_arg_clojure_evalation)(LuaCEmbed *self, lua_Integer index, const char *code, ...);
    double (*get_double_arg_clojure_evalation)(LuaCEmbed *self, lua_Integer index, const char *code, ...);
    bool (*get_bool_arg_clojure_evalation)(LuaCEmbed *self, lua_Integer index, const char *code, ...);
    char *(*get_string_arg_clojure_evalation)(LuaCEmbed *self, lua_Integer index, const char *code, ...);
    LuaCEmbedTable *(*run_lambda)(LuaCEmbed *self, lua_Integer index, LuaCEmbedTable *args_to_call, lua_Integer total_returns);
} LuaCembedArgsModule;
LuaCEmbedGlobalModule newLuaCEmbedGlobalModule();
typedef struct {
    int (*ensure_type)(LuaCEmbed *self, const char *name, int expected_type);
    int (*get_type)(LuaCEmbed *self, const char *name);
    lua_Integer (*get_long)(LuaCEmbed *self, const char *name);
    double (*get_double)(LuaCEmbed *self, const char *name);
    bool (*get_bool)(LuaCEmbed *self, const char *name);
    char * (*get_string)(LuaCEmbed *self, const char *name);
    LuaCEmbedTable* (*run_global_lambda)(LuaCEmbed *self, const char *name, LuaCEmbedTable *args_to_call, int total_returns);
    void (*set_table)(LuaCEmbed *self, const char *name, LuaCEmbedTable *table);
    void (*set_raw_string)(LuaCEmbed *self, const char *name, const char *value, long size);
    char * (*get_raw_string)(LuaCEmbed *self, const char *name, long *size);
    void (*set_string)(LuaCEmbed *self, const char *name, const char *value);
    void (*set_long)(LuaCEmbed *self, const char *name, lua_Integer value);
    void (*set_double)(LuaCEmbed *self, const char *name, double value);
    void (*set_bool)(LuaCEmbed *self, const char *name, bool value);
    LuaCEmbedTable * (*get_table)(LuaCEmbed *self, const char *name);
    LuaCEmbedTable * (*new_table)(LuaCEmbed *self, const char *name);
} LuaCEmbedGlobalModule;
LuaCEmbedResponseModule newLuaCEmbedResponseModule();
typedef struct {
    LuaCEmbedResponse * (*send_multi_return)(LuaCEmbedTable *table);
    LuaCEmbedResponse * (*send_str)(const char *text);
    LuaCEmbedResponse * (*send_raw_string)(const char *text,lua_Integer size);
    LuaCEmbedResponse * (*send_str_reference)( const char *text);
    LuaCEmbedResponse * (*send_raw_string_reference)(const char *text,lua_Integer size);
    LuaCEmbedResponse * (*send_table)(LuaCEmbedTable *table);
    LuaCEmbedResponse * (*send_evaluation_function)(const char *function);
    LuaCEmbedResponse  * (*send_double)(double value);
    LuaCEmbedResponse  * (*send_bool)(bool value);
    LuaCEmbedResponse  * (*send_long)(lua_Integer value);
    LuaCEmbedResponse * (*send_error)(const char *format,...);

}LuaCEmbedResponseModule;
LuaCembedTableModule newLuaCembedTableModule();
typedef struct {
    // Array manipulation functions
    void (*append_string)(LuaCEmbedTable *self, const char *value);
    void (*append_long)(LuaCEmbedTable *self, lua_Integer value);
    void (*append_double)(LuaCEmbedTable *self, double value);
    void (*append_bool)(LuaCEmbedTable *self, bool value);
    void (*append_table)(LuaCEmbedTable *self, LuaCEmbedTable *table);
    void (*set_evaluation_prop)(LuaCEmbedTable *self, const char *name, const char *code, ...);
    void (*append_evaluation)(LuaCEmbedTable *self, const char *code, ...);

    // Insert functions
    void (*insert_string_at_index)(LuaCEmbedTable *self, lua_Integer index, const char *value);
    void (*insert_bool_at_index)(LuaCEmbedTable *self, lua_Integer index, bool value);
    void (*insert_long_at_index)(LuaCEmbedTable *self, lua_Integer index, lua_Integer value);
    void (*insert_double_at_index)(LuaCEmbedTable *self, lua_Integer index, double value);
    void (*insert_table_at_index)(LuaCEmbedTable *self, lua_Integer index, LuaCEmbedTable *table);

    // Set by index functions
    void (*set_sub_table_by_index)(LuaCEmbedTable *self, lua_Integer index, LuaCEmbedTable *sub_table);
    void (*set_string_by_index)(LuaCEmbedTable *self, lua_Integer index, const char *value);
    void (*set_raw_string_by_index)(LuaCEmbedTable *self, lua_Integer index, const char *value, lua_Integer size);
    void (*set_long_by_index)(LuaCEmbedTable *self, lua_Integer index, lua_Integer value);
    void (*set_double_by_index)(LuaCEmbedTable *self, lua_Integer index, double value);
    void (*set_bool_by_index)(LuaCEmbedTable *self, lua_Integer index, bool value);
    void (*set_evaluation_by_index)(LuaCEmbedTable *self, lua_Integer index, const char *code, ...);

    // Get by index functions
    lua_Integer (*get_listable_size)(LuaCEmbedTable *self);
    LuaCEmbedTable *(*get_sub_table_by_index)(LuaCEmbedTable *self, lua_Integer index);
    LuaCEmbedTable *(*new_sub_table_appending)(LuaCEmbedTable *self);

    // Property management functions
    void (*set_method)(LuaCEmbedTable *self, const char *name, LuaCEmbedResponse *(*callback)(LuaCEmbedTable *self, LuaCEmbed *args));
    void (*set_string_prop)(LuaCEmbedTable *self, const char *name, const char *value);
    void (*set_raw_string_prop)(LuaCEmbedTable *self, const char *name, const char *value, lua_Integer size);
    void (*set_long_prop)(LuaCEmbedTable *self, const char *name, lua_Integer value);
    void (*set_double_prop)(LuaCEmbedTable *self, const char *name, double value);
    void (*set_bool_prop)(LuaCEmbedTable *self, const char *name, bool value);

    // Get property functions
    int (*get_type_prop)(LuaCEmbedTable *self, const char *name);
    char *(*get_string_prop)(LuaCEmbedTable *self, const char *name);
    char *(*get_raw_string_prop)(LuaCEmbedTable *self, const char *name, lua_Integer *size);
    lua_Integer (*get_long_prop)(LuaCEmbedTable *self, const char *name);
    double (*get_double_prop)(LuaCEmbedTable *self, const char *name);
    bool (*get_bool_prop)(LuaCEmbedTable *self, const char *name);

    // Table management functions
    LuaCEmbedTable *(*new_anonymous_table)(LuaCEmbed *self);
    void (*destroy_prop)(LuaCEmbedTable *self, const char *name);
    LuaCEmbedTable *(*get_sub_table_prop)(LuaCEmbedTable *self, const char *name);
    LuaCEmbedTable *(*new_sub_table_prop)(LuaCEmbedTable *self, const char *name);
    void (*set_sub_table_prop)(LuaCEmbedTable *self, const char *name, LuaCEmbedTable *sub_table);

    // Utility functions
    char *(*get_key_by_index)(LuaCEmbedTable *self, lua_Integer index);
    bool (*has_key)(LuaCEmbedTable *self, lua_Integer index);
    lua_Integer (*get_size)(LuaCEmbedTable *self);
    int (*get_type_by_index)(LuaCEmbedTable *self, lua_Integer index);
    lua_Integer (*get_long_by_index)(LuaCEmbedTable *self, lua_Integer index);
    double (*get_double_by_index)(LuaCEmbedTable *self, lua_Integer index);
    char *(*get_string_by_index)(LuaCEmbedTable *self, lua_Integer index);
    char *(*get_raw_string_by_index)(LuaCEmbedTable *self, lua_Integer index, lua_Integer *size);
    bool (*get_bool_by_index)(LuaCEmbedTable *self, lua_Integer index);

} LuaCembedTableModule;
LuaCEmbedTypeModule newLuaCEmbedTypeModule();
typedef struct {
    int NOT_FOUND;
    int STRING;
    int NUMBER;
    int BOOL;
    int NILL;
    int TABLE;
    int FUNCTION;
} LuaCEmbedTypeModule;

~~~