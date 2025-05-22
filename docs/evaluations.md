### Evaluation
To evaluate Lua Code from C, you can use all the evaluation methods provided by the library.

#### Evaluating string

```c
#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){
    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_evaluate(l, "r = 'hello world'");

    char * result = LuaCEmbed_get_evaluation_string(l, "r");
    printf("result: %s\n", result);
    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}
```

It will produce:

```bash
result: hello world
```

#### Evaluating a file
It's also possible to evaluate a file by using the **LuaCEmbed_evaluete_file** method.

```c
#include "LuaCEmbedOne.c"

LuaCEmbedResponse * hello(LuaCEmbed *args){
    printf("hello world");
    return NULL;
}

int main(int argc, char *argv[]){
    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l, "hello", hello);

    LuaCEmbed_evaluete_file(l, "tests/target/hello.lua");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}
```

It will produce:

```bash
hello world
```

#### Type Evaluation
You can determine the type of the evaluation by using the **LuaCEmbed_get_evaluation_type** method.

#### Evaluating Long

```c
#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){
    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_evaluate(l, "r = 'hello world'");

    int r_type = LuaCEmbed_get_evaluation_type(l, "r");
    const char* converted = LuaCembed_convert_arg_code(r_type);
    printf("result: %s\n", converted);
    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}
```

It will produce:

```bash
result: string
```

#### Evaluating Long

```c
#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){
    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_evaluate(l, "r = 20 + 30");

    long result = LuaCEmbed_get_evaluation_long(l, "r");
    printf("result: %ld\n", result);
    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}
```

It will produce:

```bash
result: 50
```

#### Evaluating Double

```c
#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){
    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_evaluate(l, "r = 20 + 30");

    double result = LuaCEmbed_get_evaluation_double(l, "r");
    printf("result: %lf\n", result);
    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}
```

It will produce:

```bash
result: 50.000000
```

#### Evaluating Bool

```c
#include "LuaCEmbedOne.c"

int main(int argc, char *argv[]){
    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_evaluate(l, "r = true");

    bool result = LuaCEmbed_get_evaluation_bool(l, "r");
    printf("result: %d\n", result);
    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n", LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}
```

It will produce:

```bash
result: 1
```
