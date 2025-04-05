### Setting Basic Properties

```c
#include "LuaCEmbedOne.c"
LuaCEmbedNamespace lua_n;

LuaCEmbedResponse *create_table(LuaCEmbed *args) {
    LuaCEmbedTable *custom_table = lua_n.tables.new_anonymous_table(args);
    lua_n.tables.set_string_prop(custom_table, "name", "Mateus");
    lua_n.tables.set_long_prop(custom_table, "age", 27);
    lua_n.tables.set_double_prop(custom_table, "height", 1.82);
    lua_n.tables.set_bool_prop(custom_table, "married", false);
    return lua_n.response.send_table(custom_table);
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
LuaCEmbedNamespace lua_n;

LuaCEmbedResponse *describe(LuaCEmbedTable *self, LuaCEmbed *args) {
    char *name = lua_n.tables.get_string_prop(self, "name");
    long age = lua_n.tables.get_long_prop(self, "age");
    double height = lua_n.tables.get_double_prop(self, "height");
    bool married = lua_n.tables.get_bool_prop(self, "married");
    printf("person description:\n");
    printf("name: %s\n", name);
    printf("age: %ld\n", age);
    printf("height: %lf\n", height);
    printf("married %d\n", married);
    return NULL;
}

LuaCEmbedResponse *create_table(LuaCEmbed *args) {
    LuaCEmbedTable *custom_table = lua_n.tables.new_anonymous_table(args);
    lua_n.tables.set_string_prop(custom_table, "name", "Mateus");
    lua_n.tables.set_long_prop(custom_table, "age", 27);
    lua_n.tables.set_double_prop(custom_table, "height", 1.82);
    lua_n.tables.set_bool_prop(custom_table, "married", false);
    lua_n.tables.set_method(custom_table, "describe", describe);
    return lua_n.response.send_table(custom_table);
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
LuaCEmbedNamespace lua_n;

LuaCEmbedResponse *index_callback(LuaCEmbedTable *self, LuaCEmbed *args) {
    int value_type = lua_n.args.get_type(args, 1);

    if (value_type == lua_n.types.NUMBER) {
        printf("index-value: %lf\n", lua_n.args.get_double(args, 1));
    } else if (value_type == lua_n.types.STRING) {
        printf("index-value: %s\n", lua_n.args.get_str(args, 1));
    }

    return NULL;
}

LuaCEmbedResponse *deletion_callback(LuaCEmbedTable *self, LuaCEmbed *args) {
    printf("called the delete function\n");
    return NULL;
}

LuaCEmbedResponse *create_table(LuaCEmbed *args) {
    LuaCEmbedTable *custom_table = lua_n.tables.new_anonymous_table(args);
    lua_n.tables.set_method(custom_table, "__gc", deletion_callback);
    lua_n.tables.set_method(custom_table, "__index", index_callback);
    return lua_n.response.send_table(custom_table);
}
```

**Output:**
```bash
index-value: 10.000000
index-value: sss
called the delete function
```