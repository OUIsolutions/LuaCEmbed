### Retrieving Table Properties

```c
#include "LuaCEmbedOne.c"

LuaCEmbedResponse *show_table(LuaCEmbed *args) {
    LuaCEmbedTable *t1 = LuaCEmbed_get_arg_table(args, 0);
    if (LuaCEmbed_has_errors(args)) {
        char *message = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(message);
    }

    char *name = LuaCembedTable_get_string_prop(t1, "name");
    long age = LuaCembedTable_get_long_prop(t1, "age");

    if (LuaCEmbed_has_errors(args)) {
        char *message = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(message);
    }

    printf("name : %s\n", name);
    printf("age: %ld\n", age);

    return NULL;
}
```

**Output:**
```bash
name : mateus
age: 27
```

### Retrieving Sub Tables

```c
#include "LuaCEmbedOne.c"

LuaCEmbedResponse *show_table(LuaCEmbed *args) {
    LuaCEmbedTable *t1 = LuaCEmbed_get_arg_table(args, 0);
    if (LuaCEmbed_has_errors(args)) {
        char *message = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(message);
    }

    long size = LuaCEmbedTable_get_listable_size(t1);
    for (int i = 0; i < size; i++) {
        LuaCEmbedTable *current = LuaCEmbedTable_get_sub_table_by_index(t1, i);
        char *name = LuaCembedTable_get_string_prop(current, "name");
        long age = LuaCembedTable_get_long_prop(current, "age");

        if (LuaCEmbed_has_errors(args)) {
            char *message = LuaCEmbed_get_error_message(args);
            return LuaCEmbed_send_error(message);
        }

        printf("name : %s\n", name);
        printf("age: %ld\n", age);
        printf("------------------------------------------\n");
    }

    return NULL;
}
```

**Output:**
```bash
name : mateus
age: 27
------------------------------------------
name : john
age: 30
------------------------------------------
```

### Iterating Over Table

```c
#include "LuaCEmbedOne.c"

LuaCEmbedResponse *show_table(LuaCEmbed *args) {
    LuaCEmbedTable *t1 = LuaCEmbed_get_arg_table(args, 0);
    if (LuaCEmbed_has_errors(args)) {
        char *message = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(message);
    }
    long size = LuaCEmbedTable_get_listable_size(t1);
    for (int i = 0; i < size; i++) {
        printf("index: %d\n", i);
        const char *key = "Not provided";
        if (LuaCembedTable_has_key_at_index(t1, i)) {
            key = LuaCembedTable_get_key_by_index(t1, i);
        }
        printf("key: %s\n", key);

        int type = LuaCEmbedTable_get_type_by_index(t1, i);
        printf("type %s\n", LuaCembed_convert_arg_code(type));

        if (type == LUA_CEMBED_NUMBER) {
            double value = LuaCEmbedTable_get_double_by_index(t1, i);
            printf("value: %lf\n", value);
        }

        if (type == LUA_CEMBED_STRING) {
            char *value = LuaCEmbedTable_get_string_by_index(t1, i);
            printf("value: %s\n", value);
        }

        if (type == LUA_CEMBED_BOOL) {
            bool value = LuaCEmbedTable_get_bool_by_index(t1, i);
            printf("value: %d\n", value);
        }
        printf("------------------------------------------\n");
    }
    return NULL;
}
```

**Output:**
```bash
index: 0
key: Not provided
type string
value: indexable random string
------------------------------------------
index: 1
key: single
type boolean
value: 1
------------------------------------------
index: 2
key: name
type string
value: Mateus
------------------------------------------
index: 3
key: age
type number
value: 27.000000
------------------------------------------
```