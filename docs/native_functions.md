### Runting Native functions
<h3 style="color:red;">
NEVER CALL THE FUNCTION 'load_native_libs' IF YOU DON TRUST IN THE USER
</h3>
You can load native lua functions by the usage of **load_native_libs** function

```c
#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    //NEVER USE THESE IF YOU DONT TRUST IN THE CLIENT
    LuaCEmbed_load_native_libs(l);

    LuaCEmbed_evaluate(l,"print('hello from lua')");
    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n",LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}
```


It will produce:
```bash
hello from lua
```
