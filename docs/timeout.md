### Timeout
You can set a timeout for your functions by using the timeout method:

```c
#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    return LuaCEmbed_send_str(" executed after timeout error\n");
}
int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l, "test", test_func);
    int seconds = 2;
    LuaCEmbed_set_timeout(seconds);

    LuaCEmbed_evaluate(l, "while true do end ;");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_clear_errors(l);
    char *teste = LuaCEmbed_get_evaluation_string(l, "test()");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    else{
        printf("%s", teste);
    }
    LuaCEmbed_free(l);

    return 0;
}
```

It will produce:

```bash
error: timeout error
 executed after timeout error
```
