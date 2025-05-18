### WARNING: THIS IS ALPHA SOFTWARE. USE AT YOUR OWN RISK. NO WARRANTY IS PROVIDED AND BUGS ARE EXPECTED.

LuaCEmbed it's  a lua wrapper to allow easy interoperability beetwen C and Lua
providing any methods to control Lua Code from C,Make Lua  Libs, or create ambients
for safe evaluation of Lua code.

## Releases
| Item | Description |
|------|-------------|
|[LuaCEmbedOne.c](https://github.com/OUIsolutions/LuaCEmbed/releases/download/0.8.3/LuaCEmbedOne.c) |One File|
|[LuaCEmbed.c](https://github.com/OUIsolutions/LuaCEmbed/releases/download/0.8.3/LuaCEmbed.c)| Definition|
|[LuaCEmbed.h](https://github.com/OUIsolutions/LuaCEmbed/releases/download/0.8.3/LuaCEmbed.h)| Header|
|[LuaCEmbed.zip](https://github.com/OUIsolutions/LuaCEmbed/releases/download/0.8.3/LuaCEmbed.zip)| Zip Mode|

### Most Basic Example
Like all OUI librarys, the LuaCEmbed addopt the ideia of single file lib, so you just need to copy the [LuaCEmbedOne.c](https://github.com/OUIsolutions/LuaCEmbed/releases/download/0.8.3/LuaCEmbedOne.c) file
into your project, and compile with gcc/clang
```c
#include "LuaCEmbedOne.c"
LuaCEmbedNamespace  lua_n;

int main(int argc, char *argv[]){
    
    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate(l,"r = 30");
    long calc = lua_n.get_evaluation_long(l,"r + 20");
    printf("result %ld",calc);
    
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
```
## Documentation

| Item | Description |
|------|-------------|
|[build_and_install.md](/docs/build_and_install.md)| Installation and Compilation |
|[native_functions.md](/docs/native_functions.md)| Running Native Functions |
|[making_a_library.md](/docs/making_a_library.md)| Creating Libraries |
|[evaluations.md](/docs/evaluations.md)| Lua Evaluation |
|[timeout.md](/docs/timeout.md)| Timeout |
|[memory_usage.md](/docs/memory_usage.md)| Memory Usage |
|[callbacks.md](/docs/callbacks.md)| Callbacks |
|[table_handling.md](/docs/table_handling.md)| Table Handling |
|[table_setting.md](/docs/table_setting.md)| Setting Table Properties |
|[table_size.md](/docs/table_size.md)| Table Size |
|[dependencies.md](/docs/dependencies.md)| Licenses and Attributions |
