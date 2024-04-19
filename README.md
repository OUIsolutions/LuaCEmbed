LuaCEmbed it's  a lua wrapper to allow easy interoperability beetwen C and Lua 
providing any methods to control Lua Code from C 


### Hello World
<!--codeof:exemples/evaluation/hello_world.c-->
~~~c
#include "../../../LuaCEmbed.h"
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


### Evaluation
To evaluate Lua Code from C, you can use all the evaluation methods, provided by the lib 


#### Evaluating string 

<!--codeof:exemples/evaluation/string_evalation.c-->
~~~c

~~~

#### Evaluating a file 
It's also possible to evaluate a file by using the **evaluete_file** method 

<!--codeof:exemples/evaluation/file_evaluation.c-->
~~~c

~~~

#### Type Evaluation 
You can determine the type of the evaluation by using the **get_evaluation_type** method 
#### Evaluating Long

<!--codeof:exemples/evaluation/type_evaluation.c-->
~~~c

~~~

### Table Size 
Its also possible to determine the size of a table by using the **get_evaluation_size** method 
<!--codeof:exemples/evaluation/table_size.c-->
~~~c

~~~


#### Evaluating Long

<!--codeof:exemples/evaluation/long_return.c-->
~~~c

~~~

#### Evaluating Double

<!--codeof:exemples/evaluation/double_evaluation.c-->
~~~c

~~~


#### Evaluating Bool

<!--codeof:exemples/evaluation/bool_evaluation.c-->
~~~c

~~~



