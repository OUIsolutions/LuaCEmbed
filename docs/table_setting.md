### Setting Basic Properties

```c
#include "LuaCEmbedOne.c"

LuaCEmbedResponse *create_table(LuaCEmbed *args) {
    LuaCEmbedTable *custom_table = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_string_prop(custom_table, "name", "Mateus");
    LuaCEmbedTable_set_long_prop(custom_table, "age", 27);
    LuaCEmbedTable_set_double_prop(custom_table, "height", 1.82);
    LuaCEmbedTable_set_bool_prop(custom_table, "married", false);
    return LuaCEmbed_send_table(custom_table);
}
```

**Output:**
```bash
name: Mateus
age: 27
height: 1.820000
married 0
```

### Setting Methods

```c
#include "LuaCEmbedOne.c"

LuaCEmbedResponse *describe(LuaCEmbedTable *self, LuaCEmbed *args) {
    char *name = LuaCembedTable_get_string_prop(self, "name");
    long age = LuaCembedTable_get_long_prop(self, "age");
    double height = LuaCembedTable_get_double_prop(self, "height");
    bool married = LuaCembedTable_get_bool_prop(self, "married");
    printf("person description:\n");
    printf("name: %s\n", name);
    printf("age: %ld\n", age);
    printf("height: %lf\n", height);
    printf("married %d\n", married);
    return NULL;
}

LuaCEmbedResponse *create_table(LuaCEmbed *args) {
    LuaCEmbedTable *custom_table = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_string_prop(custom_table, "name", "Mateus");
    LuaCEmbedTable_set_long_prop(custom_table, "age", 27);
    LuaCEmbedTable_set_double_prop(custom_table, "height", 1.82);
    LuaCEmbedTable_set_bool_prop(custom_table, "married", false);
    LuaCEmbedTable_set_method(custom_table, "describe", describe);
    return LuaCEmbed_send_table(custom_table);
}
```

**Output:**
```bash
person description:
name: Mateus
age: 27
height: 1.820000
married 0
```

### Setting Meta Methods

```c
#include "LuaCEmbedOne.c"

LuaCEmbedResponse *index_callback(LuaCEmbedTable *self, LuaCEmbed *args) {
    int value_type = LuaCEmbed_get_arg_type(args, 1);

    if (value_type == LUA_CEMBED_NUMBER) {
        printf("index-value: %lf\n", LuaCEmbed_get_double_arg(args, 1));
    } else if (value_type == LUA_CEMBED_STRING) {
        printf("index-value: %s\n", LuaCEmbed_get_str_arg(args, 1));
    }

    return NULL;
}

LuaCEmbedResponse *deletion_callback(LuaCEmbedTable *self, LuaCEmbed *args) {
    printf("called the delete function\n");
    return NULL;
}

LuaCEmbedResponse *create_table(LuaCEmbed *args) {
    LuaCEmbedTable *custom_table = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_method(custom_table, "__gc", deletion_callback);
    LuaCEmbedTable_set_method(custom_table, "__index", index_callback);
    return LuaCEmbed_send_table(custom_table);
}
```

**Output:**
```bash
index-value: 10.000000
index-value: sss
called the delete function
```
