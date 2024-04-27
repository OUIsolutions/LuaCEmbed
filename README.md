LuaCEmbed it's  a lua wrapper to allow easy interoperability beetwen C and Lua 
providing any methods to control Lua Code from C 


### Hello World
<!--codeof:exemples/evaluation/hello_world.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;

int main(int argc, char *argv[]){
    
    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate_string(l,"r = 30");
    long calc = lua_n.get_evaluation_long(l,"r + 20");
    printf("result %ld",calc);
    
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:

<!--codeof:tests/main_test/evaluation/T_hello_world/expected.txt-->
~~~txt
 
result 50
~~~

### Evaluation
To evaluate Lua Code from C, you can use all the evaluation methods, provided by the lib 


#### Evaluating string 

<!--codeof:exemples/evaluation/string_evalation.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;



int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate_string(l,"r = 'hello world'");

    char * result = lua_n.get_string_evaluation(l,"r");
    printf("result: %s\n",result);
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:

<!--codeof:tests/main_test/evaluation/T_string_evalation/expected.txt-->
~~~txt
 
result: hello world

~~~



#### Evaluating a file 
It's also possible to evaluate a file by using the **evaluete_file** method 

<!--codeof:exemples/evaluation/file_evaluation.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * hello(LuaCEmbed *args){
    printf("hello world");
    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"hello",hello);

    lua_n.evaluete_file(l,"tests/target/hello.lua");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~


It will produce:

<!--codeof:tests/main_test/evaluation/T_file_evaluation/expected.txt-->
~~~txt
 
hello world
~~~



#### Type Evaluation 
You can determine the type of the evaluation by using the **get_evaluation_type** method 
#### Evaluating Long

<!--codeof:exemples/evaluation/type_evaluation.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;



int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate_string(l,"r = 'hello world'");

    int r_type = lua_n.get_evaluation_type(l,"r");
    const char*converted =  lua_n.convert_arg_code(r_type);
    printf("result: %s\n",converted);
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:

<!--codeof:tests/main_test/evaluation/T_type_evaluation/expected.txt-->
~~~txt
 
result: string

~~~
### Table Size 
Its also possible to determine the size of a table by using the **get_evaluation_size** method 
<!--codeof:exemples/evaluation/table_size.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;



int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate_string(l,"r = {1,2,3}");

    long result = lua_n.get_evaluation_size(l,"r");
    printf("size: %ld\n",result);
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:

<!--codeof:tests/main_test/evaluation/T_table_size/expected.txt-->
~~~txt
 
size: 3

~~~

#### Evaluating Long

<!--codeof:exemples/evaluation/long_return.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;



int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate_string(l,"r = 20 + 30");

    long result = lua_n.get_evaluation_long(l,"r");
    printf("result: %ld\n",result);
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~
It will produce:

<!--codeof:tests/main_test/evaluation/T_long_return/expected.txt-->
~~~txt
 
result: 50

~~~

#### Evaluating Double

<!--codeof:exemples/evaluation/double_evaluation.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;



int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate_string(l,"r = 20 + 30");

    double result = lua_n.get_evaluation_double(l,"r");
    printf("result: %lf\n",result);
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:

<!--codeof:tests/main_test/evaluation/T_double_evaluation/expected.txt-->
~~~txt
 
result: 50.000000

~~~

#### Evaluating Bool

<!--codeof:exemples/evaluation/bool_evaluation.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;



int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate_string(l,"r = true");

    bool result = lua_n.get_evaluation_bool(l,"r");
    printf("result: %d\n",result);
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:

<!--codeof:tests/main_test/evaluation/T_bool_evaluation/expected.txt-->
~~~txt
 
result: 1

~~~

### Callbacks 
Callbacks i'ts a way to make c functions assesible in lua code, this it's the most basic callback:

<!--codeof:exemples/calbacks/basic_callback.c-->
~~~c
~~~
It will produce:

<!--codeof:tests/main_test/calbacks/T_basic_callback/expected.txt-->
~~~txt
~~~


#### CallBack args
you can accept callback arguments into your function,check their types, and make operations with them.

<!--codeof:exemples/calbacks/args_retriving.c-->
~~~c
~~~
It will produce:

<!--codeof:tests/main_test/calbacks/T_args_retriving/expected.txt-->
~~~txt
~~~

#### Creating a basic print function

in these example, we are creating an 'print' function ,to allow print values 

<!--codeof:exemples/calbacks/print_func.c-->
~~~c
~~~
It will produce:

<!--codeof:tests/main_test/calbacks/T_print_func/expected.txt-->
~~~txt
~~~

#### Evaluating arguments

it's also possible to modify callbacks by lua code , by using the evaluation args mechanism.

<!--codeof:exemples/calbacks/evaluating_args.c-->
~~~c
~~~
It will produce:

<!--codeof:tests/main_test/calbacks/T_evaluating_args/expected.txt-->
~~~txt
~~~

#### Table Arguments
you can control table arguments easly with the **get_table** method, where you can retrive a 
**LuaCEmbedTable** object 


<!--codeof:exemples/calbacks/getting_table_args.c-->
~~~c
~~~
It will produce:

<!--codeof:tests/main_test/calbacks/T_getting_table_args/expected.txt-->
~~~txt
~~~
### Callbacks Response 




### Globals 
Glbals can be fully handled by the LuaCEmbed Api

#### Retriving Globals 

#### Getting a global string

<!--codeof:exemples/globals/get_string_global.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate_string(l,"r = 'hello world'");
    char *  result  = lua_n.globals.get_string(l,"r");
    printf("result %s\n",result);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:

<!--codeof:tests/main_test/globals/T_get_string_global/expected.txt-->
~~~txt
 
result hello world

~~~

#### Getting a global bool

<!--codeof:exemples/globals/get_bool_global.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate_string(l,"r = true");
    bool  result  = lua_n.globals.get_bool(l,"r");
    printf("result %d\n",result);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:

<!--codeof:tests/main_test/globals/T_get_bool_global/expected.txt-->
~~~txt
 
result 1

~~~

#### Getting a double global

<!--codeof:exemples/globals/get_double_global.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate_string(l,"r = 30.5");
    double  result  = lua_n.globals.get_double(l,"r");
    printf("result %lf\n",result);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~
It will produce:

<!--codeof:tests/main_test/globals/T_get_double_global/expected.txt-->
~~~txt
 
result 30.500000

~~~


#### Getting a long global

<!--codeof:exemples/globals/get_long_global.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate_string(l,"r = 30");
    long  result  = lua_n.globals.get_long(l,"r");
    printf("result %ld\n",result);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:

<!--codeof:tests/main_test/globals/T_get_long_global/expected.txt-->
~~~txt
 
result 30

~~~

#### Getting a type global
<!--codeof:exemples/globals/get_type.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate_string(l,"r = 'hello world'");
    int type_code  = lua_n.globals.get_type(l,"r");
    const char *converted_type = lua_n.convert_arg_code(type_code);
    printf("result %s\n",converted_type);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~
It will produce:

<!--codeof:tests/main_test/globals/T_get_type/expected.txt-->
~~~txt
 
result string

~~~

#### Getting a table
Tables are by default auto created, so yoou can just use the **get_table_auto_creating**  method
<!--codeof:exemples/globals/get_table_global.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate_string(l,"r = {a='internal text'}");
    LuaCEmbedTable *r_table  = lua_n.globals.get_table_auto_creating(l,"r");
    char *a = lua_n.tables.get_string_prop(r_table,"a");
    printf("value of r.a = %s\n",a);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:

<!--codeof:tests/main_test/globals/T_get_table_global/expected.txt-->
~~~txt
 
value of r.a = internal text

~~~

### Setting Globals

Its also possible to set global variables 

#### Set Long
<!--codeof:exemples/globals/set_long.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.globals.set_long(l,"r",30);
    double result  = lua_n.globals.get_long(l,"r");
    printf("result %lf\n",result);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce 

<!--codeof:tests/main_test/globals/T_set_long/expected.txt-->
~~~txt
 
result 30.000000

~~~


#### Set Double
<!--codeof:exemples/globals/set_double.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.globals.set_double(l,"r",30);
    double result  = lua_n.globals.get_double(l,"r");
    printf("result %lf\n",result);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce

<!--codeof:tests/main_test/globals/T_set_double/expected.txt-->
~~~txt
 
result 30.000000

~~~



#### Set string
<!--codeof:exemples/globals/set_string.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.globals.set_string(l,"r","hello world");
    char *  result  = lua_n.globals.get_string(l,"r");
    printf("result %s\n",result);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce

<!--codeof:tests/main_test/globals/T_set_string/expected.txt-->
~~~txt
 
result hello world

~~~



#### Set Bool
<!--codeof:exemples/globals/set_bool.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.globals.set_bool(l,"r",true);
    bool result  = lua_n.globals.get_bool(l,"r");
    printf("result %d\n",result);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce

<!--codeof:tests/main_test/globals/T_set_bool/expected.txt-->
~~~txt
 
result 1

~~~

#### New Table
its possible to create a new global table, the vallues will be automaticaly setted


#### Set Bool
<!--codeof:exemples/globals/set_table.c-->
~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    LuaCEmbedTable *created = lua_n.globals.new_table(l,"r");
    lua_n.tables.set_string_prop(created,"a","internal text");

    char *a =  lua_n.tables.get_string_prop(created,"a");
    printf("result of r.a %s\n",a);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce

<!--codeof:tests/main_test/globals/T_set_table/expected.txt-->
~~~txt
 
result of r.a internal text

~~~

