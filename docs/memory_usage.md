### Memory usage
by using the method **set_memory_limit** you can control the max ram usage of lua, the default its 100mb
<h5 style="color:red;">NOTE THAT EXTRA MEMORY ALOCATED OUTSIDE CALLBACKS OR EVALUATIONS ARE CONSIDER UNPROTECTED GEHAVIOR
AND IT WILL KILL THE APPLICATION
</h5>

```c
#include "LuaCEmbedOne.c"

LuaCEmbedNamespace  lua_n;



int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    int one_mega = 1;
    lua_n.set_memory_limit(l,one_mega);
    lua_n.evaluate(l,"t = 'a';while true do t = t .. t  end");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    lua_n.free(l);

    return 0;
}
```

It will produce:

```bash
error: not enough memory
```
