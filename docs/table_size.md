### Table Size

It's also possible to determine the size of a table by using the **get_evaluation_size** method

```c
#include "LuaCEmbedOne.c"
LuaCEmbedNamespace lua_n;

int main(int argc, char *argv[]) {

    lua_n = newLuaCEmbedNamespace();
    LuaCEmbed *l = lua_n.newLuaEvaluation();
    lua_n.evaluate(l, "r = {1,2,3}");

    long result = lua_n.get_evaluation_size(l, "r");
    printf("size: %ld\n", result);
    if (lua_n.has_errors(l)) {
        printf("error: %s\n", lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
```

**Output:**

```bash
size: 3
```