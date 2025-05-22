### Making a Library
In the same way we can execute Lua from C, we can also generate a DLL/SO to be accessible by Lua as a library.

```c
#include "LuaCEmbedOne.c"

LuaCEmbedResponse  *add_cfunc(LuaCEmbed *args) {
    double first_num = LuaCEmbed_get_double_arg(args, 0);
    double second_num = LuaCEmbed_get_double_arg(args, 1);

    if (LuaCEmbed_has_errors(args)) {
        char *message = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(message);
    }
    double result = first_num + second_num;
    return LuaCEmbed_send_double(result);
}

LuaCEmbedResponse  *sub_cfunc(LuaCEmbed *args) {
    double first_num = LuaCEmbed_get_double_arg(args, 0);
    double second_num = LuaCEmbed_get_double_arg(args, 1);

    if (LuaCEmbed_has_errors(args)) {
        char *message = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(message);
    }
    double result = first_num - second_num;
    return LuaCEmbed_send_double(result);
}

int luaopen_my_lib(lua_State *state) {
    LuaCEmbed *l = newLuaCEmbedLib(state);
    LuaCEmbed_add_callback(l, "add", add_cfunc);
    LuaCEmbed_add_callback(l, "sub", sub_cfunc);
    return LuaCembed_perform(l);
}
```

Compile the code with:
```shell
gcc -shared -fPIC -o my_lib.so main.c
```

Then you can call it in your Lua code:

```lua
local lib = require("my_lib")

x = lib.add(10, 20)
y = lib.sub(20, 5)
print("x", x)
print("y", y)
```

### Lib Props
You can define library properties in your library:

```c
#include "LuaCEmbedOne.c"

int luaopen_my_lib(lua_State *state) {
    LuaCEmbed *l = newLuaCEmbedLib(state);
    bool set_functions_as_public = false;
    LuaCEmbed_set_long_lib_prop(l, "long_prop", 30);
    LuaCEmbed_set_double_lib_prop(l, "double_prop", 50.5);
    LuaCEmbed_set_bool_lib_prop(l, "bool_prop", true);
    LuaCEmbed_set_string_lib_prop(l, "string_prop", "test");
    LuaCEmbedTable *t = LuaCembed_new_anonymous_table(l);
    LuaCEmbedTable_set_string_prop(t, "test", "test_message");
    LuaCEmbed_set_table_lib_prop(l, "table_prop", t);
    return LuaCembed_perform(l);
}
```

Testing with Lua:

```lua
lib = require("my_lib")
print("long_prop", lib.long_prop)
print("double_prop", lib.double_prop)
print("bool_prop", lib.bool_prop)
print("string_prop", lib.string_prop)
print("table_prop", lib.table_prop)
print("table_prop internal", lib.table_prop.test)
```
