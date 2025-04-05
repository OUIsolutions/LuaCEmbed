# Callbacks

Callbacks allow C functions to be accessible in Lua code:

```c
#include "LuaCEmbedOne.c"
LuaCEmbedNamespace lua_n;

LuaCEmbedResponse *hello(LuaCEmbed *args) {
    printf("my first callback\n");
    return NULL;
}

int main(int argc, char *argv[]) {
    lua_n = newLuaCEmbedNamespace();
    LuaCEmbed *l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l, "hello", hello);

    lua_n.evaluate(l, "hello()");

    if (lua_n.has_errors(l)) {
        printf("error: %s\n", lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
```

**Output:**
```bash
my first callback
```

### Callback Args

You can accept and check callback arguments:

```c
#include "LuaCEmbedOne.c"
LuaCEmbedNamespace lua_n;

LuaCEmbedResponse *test_func(LuaCEmbed *args) {
    long size = lua_n.args.size(args);
    if (size == 0) {
        printf("no argument provided\n");
        return NULL;
    }
    // ... (rest of the function)
}
```

**Output:**
```bash
no argument provided
number: 10.000000
str: hello
bool: 1
type: table
```

### Index Type

Lua starts indexing at 1, but LuaCEmbed uses C-style indexing (starting at 0):

```c
#define LUA_CEMBED_INDEX_DIF 0
#include "LuaCEmbedOne.c"
// ... (rest of the code)
```