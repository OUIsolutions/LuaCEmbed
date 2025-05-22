### Table Size

It's also possible to determine the size of a table by using the **get_evaluation_size** method

```c
#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]) {

    LuaCEmbed *l = newLuaCEmbedEvaluation();
    LuaCEmbed_evaluate(l, "r = {1,2,3}");

    long result = LuaCEmbed_get_evaluation_table_size(l, "r");
    printf("size: %ld\n", result);
    if (LuaCEmbed_has_errors(l)) {
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}
```

**Output:**

```bash
size: 3
```