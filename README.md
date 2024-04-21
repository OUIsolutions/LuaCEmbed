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

### Globals 
Glbals can be fully handled by the LuaCEmbed Api

#### Retriving Globals 
