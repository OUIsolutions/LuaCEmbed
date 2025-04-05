### Retrieving Table Properties

```c
#include "LuaCEmbedOne.c"
LuaCEmbedNamespace lua_n;

LuaCEmbedResponse *show_table(LuaCEmbed *args) {
    LuaCEmbedTable *t1 = lua_n.args.get_table(args, 0);
    if (lua_n.has_errors(args)) {
        char *message = lua_n.get_error_message(args);
        return lua_n.response.send_error(message);
    }

    char *name = lua_n.tables.get_string_prop(t1, "name");
    long age = lua_n.tables.get_long_prop(t1, "age");

    if (lua_n.has_errors(args)) {
        char *message = lua_n.get_error_message(args);
        return lua_n.response.send_error(message);
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
LuaCEmbedNamespace lua_n;

LuaCEmbedResponse *show_table(LuaCEmbed *args) {
    LuaCEmbedTable *t1 = lua_n.args.get_table(args, 0);
    if (lua_n.has_errors(args)) {
        char *message = lua_n.get_error_message(args);
        return lua_n.response.send_error(message);
    }

    long size = lua_n.tables.get_size(t1);
    for (int i = 0; i < size; i++) {
        LuaCEmbedTable *current = lua_n.tables.get_sub_table_by_index(t1, i);
        char *name = lua_n.tables.get_string_prop(current, "name");
        long age = lua_n.tables.get_long_prop(current, "age");

        if (lua_n.has_errors(args)) {
            char *message = lua_n.get_error_message(args);
            return lua_n.response.send_error(message);
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
LuaCEmbedNamespace lua_n;

LuaCEmbedResponse *show_table(LuaCEmbed *args) {
    LuaCEmbedTable *t1 = lua_n.args.get_table(args, 0);
    if (lua_n.has_errors(args)) {
        char *message = lua_n.get_error_message(args);
        return lua_n.response.send_error(message);
    }
    long size = lua_n.tables.get_size(t1);
    for (int i = 0; i < size; i++) {
        printf("index: %d\n", i);
        const char *key = "Not provided";
        if (lua_n.tables.has_key(t1, i)) {
            key = lua_n.tables.get_key_by_index(t1, i);
        }
        printf("key: %s\n", key);

        int type = lua_n.tables.get_type_by_index(t1, i);
        printf("type %s\n", lua_n.convert_arg_code(type));

        if (type == lua_n.types.NUMBER) {
            double value = lua_n.tables.get_double_by_index(t1, i);
            printf("value: %lf\n", value);
        }

        if (type == lua_n.types.STRING) {
            char *value = lua_n.tables.get_string_by_index(t1, i);
            printf("value: %s\n", value);
        }

        if (type == lua_n.types.BOOL) {
            bool value = lua_n.tables.get_bool_by_index(t1, i);
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