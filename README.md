
LuaCEmbed it's  a lua wrapper to allow easy interoperability beetwen C and Lua
providing any methods to control Lua Code from C

<h3 style="color:red;">
DESPITE BEING 100% COVERED BY TESTS, THIS LIBRARY IS NOT CONSIDERED PRODUCTION READY YET, USE RESPONSIBLY
</h3>


### Usefull Links


#### Lua Project
[Lua Project](https://www.lua.org/)

#### Oui WebSite
[Link to Web Site](oui.tec.br)

#### Download Link
[Click Here to Download](https://github.com/OUIsolutions/LuaCEmbed/releases/download/v0.53/LuaCEmbed.h)


### Instalation
Like all Oui librarys, the LuaCEmbed addopt the ideia of single file lib, so you just need to copy the **LuaCEmbed.h** file
into your project, and compile with gcc/clang 

~~~c
#include "LuaCEmbed.h"
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
~~~


It will produce:


~~~txt
result 50
~~~

### Runting Native functions
<h3 style="color:red;">
NEVER CALL THE FUNCTION 'load_native_libs' IF YOU DON TRUST IN THE USER 
</h3>
You can load native lua functions by the usage of **load_native_libs** function 


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    //NEVER USE THESE IF YOU DONT TRUSt IN THE CLIENT
    lua_n.load_native_libs(l);

    lua_n.evaluate(l,"print('hello from lua')");
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:

~~~txt
hello from lua

~~~


### Making a library
in the same way we can execute lua from C, we also can generate dll/so to be acessible by lua as a library

~~~c

#include "LuaCEmbed.h"

LuaCEmbedNamespace  lua_n;


    LuaCEmbedResponse  *add_cfunc(LuaCEmbed *args){
    double first_num = lua_n.args.get_double(args,0);
    double second_num = lua_n.args.get_double(args,1);

    if(lua_n.has_errors(args)){
        char *message = lua_n.get_error_message(args);
        return lua_n.response.send_error(message);
    }
    double result = first_num + second_num;
    return lua_n.response.send_double(result);
}
LuaCEmbedResponse  *sub_cfunc(LuaCEmbed *args){
    double first_num = lua_n.args.get_double(args,0);
    double second_num = lua_n.args.get_double(args,1);

    if(lua_n.has_errors(args)){
        char *message = lua_n.get_error_message(args);
        return lua_n.response.send_error(message);
    }
    double result = first_num - second_num;
    return lua_n.response.send_double(result);
}
int luaopen_my_lib(lua_State *state){
    lua_n = newLuaCEmbedNamespace();
    //functions will be only assescible by the required reciver
    LuaCEmbed * l  = lua_n.newLuaLib(state);
    lua_n.add_callback(l,"add",add_cfunc);
    lua_n.add_callback(l,"sub",sub_cfunc);

return lua_n.perform(l);

}
~~~
Compile the code with:
~~~shell
gcc -Wall -shared -fpic -o my_lib.so  main.c 
~~~


than you can call into your lua code

~~~lua 

local lib = require("my_lib")

x = lib.add(10,20)
y = lib.sub(20,5)
print("x",x)
print("y",y)

~~~
### Lib Props
you can determine library props into your lib:
~~~c 


#include "LuaCEmbed.h"

LuaCEmbedNamespace  lua_n;



int luaopen_my_lib(lua_State *state){
    lua_n = newLuaCEmbedNamespace();
    //functions will be only assescible by the required reciver
    bool set_functions_as_public  = false;
    LuaCEmbed * l  = lua_n.newLuaLib(state,set_functions_as_public);
    lua_n.set_long_lib_prop(l,"long_prop", 30);
    lua_n.set_double_lib_prop(l,"double_prop",50.5);
    lua_n.set_bool_lib_prop(l,"bool_prop",true);
    lua_n.set_string_lib_prop(l,"string_prop","test");
    LuaCEmbedTable * t = lua_n.tables.new_anonymous_table(l);
    lua_n.tables.set_string_prop(t,"test","test_message");
    lua_n.set_table_lib_prop(l,"table_prop",t);

    return lua_n.perform(l);

}
~~~

testing with lua:

~~~lua 

lib = require("my_lib")
print("long_prop",lib.long_prop)
print("double_prop",lib.double_prop)
print("bool_prop",lib.bool_prop)
print("string_prop",lib.string_prop)
print("table_prop",lib.table_prop)
print("table_prop internal",lib.table_prop.test)


~~~


### Evaluation
To evaluate Lua Code from C, you can use all the evaluation methods, provided by the lib


#### Evaluating string


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;



int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate(l,"r = 'hello world'");

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


~~~txt
result: hello world

~~~


#### Evaluating a file
It's also possible to evaluate a file by using the **evaluete_file** method


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


~~~txt
hello world
~~~



#### Type Evaluation
You can determine the type of the evaluation by using the **get_evaluation_type** method
#### Evaluating Long


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;



int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate(l,"r = 'hello world'");

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


~~~txt
result: string

~~~



### Table Size
Its also possible to determine the size of a table by using the **get_evaluation_size** method


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;



int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate(l,"r = {1,2,3}");

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


~~~txt
size: 3

~~~

#### Evaluating Long


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;



int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate(l,"r = 20 + 30");

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


~~~txt
result: 50

~~~

#### Evaluating Double


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;



int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate(l,"r = 20 + 30");

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


~~~txt
result: 50.000000

~~~

#### Evaluating Bool


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;



int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.evaluate(l,"r = true");

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


~~~txt
result: 1

~~~

### Timeout
You can set timeout to your functions, by using the timeout method:



~~~c
#include "LuaCEmbed.h"


LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    return lua_n.response.send_str(" executed after timeout error\n");
}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);
    int seconds = 2;
    lua_n.set_timeout(seconds);

    lua_n.evaluate(l,"while true do end ;");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.clear_errors(l);
    char *teste =lua_n.get_string_evaluation(l,"test()");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    else{
        printf("%s",teste);
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
error: timeout error
 executed after timeout error

~~~

### Memory usage
by using the method **set_memory_limit** you can control the max ram usage of lua, the default its 100mb
<h5 style="color:red;">NOTE THAT EXTRA MEMORY ALOCATED OUTSIDE CALLBACKS OR EVALUATIONS  ARE CONSIDER UNPROTECTED GEHAVIOR
AND IT WILL KILL THE APPLICATION

</h5>




~~~c
#include "LuaCEmbed.h"

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
~~~

It will produce:


~~~txt
error: not enough memory

~~~

### Callbacks
Callbacks i'ts a way to make c functions assesible in lua code, this it's the most basic callback:


~~~c

#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * hello(LuaCEmbed *args){
    printf("my first callback\n");
    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"hello",hello);

    lua_n.evaluate(l,"hello()");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
my first callback

~~~



#### CallBack args
you can accept callback arguments into your function,check their types, and make operations with them.


~~~c

#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    long size = lua_n.args.size(args);
    if(size == 0){
        printf("no argument providided\n");
        return NULL;
    }
    int index = 0;
    int arg_type = lua_n.args.get_type(args,index);

    if(arg_type  == lua_n.types.NUMBER){
        printf("number: %lf\n",lua_n.args.get_double(args,index));
    }

    else if(arg_type  == lua_n.types.STRING){
        printf("str: %s\n",lua_n.args.get_str(args,index));
    }

    else if(arg_type  == lua_n.types.BOOL){
        printf("bool: %d\n", lua_n.args.get_bool(args,index));
    }
    else{
        const char *converted_to_str = lua_n.convert_arg_code(arg_type);
        printf("type: %s\n",converted_to_str);
    }

    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);

    lua_n.evaluate(l,"test()");
    lua_n.evaluate(l,"test(10)");
    lua_n.evaluate(l,"test('hello')");
    lua_n.evaluate(l,"test(true)");
    lua_n.evaluate(l,"test({a=30})");


    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
no argument providided
number: 10.000000
str: hello
bool: 1
type: table

~~~

#### Index type
The lua native language index first elements in position 1, authogth LuaCEmbed use the C style for indexation, starting at
0, but these can be easly reverted with the int macro **LUA_CEMBED_INDEX_DIF**


~~~c

#define LUA_CEMBED_INDEX_DIF 0
#include "LuaCEmbed.h"

LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    long size = lua_n.args.size(args);
    if(size == 0){
        printf("no argument providided\n");
        return NULL;
    }
    int index = 1;
    int arg_type = lua_n.args.get_type(args,index);

    if(arg_type  == lua_n.types.NUMBER){
        printf("number: %lf\n",lua_n.args.get_double(args,index));
    }

    else if(arg_type  == lua_n.types.STRING){
        printf("str: %s\n",lua_n.args.get_str(args,index));
    }

    else if(arg_type  == lua_n.types.BOOL){
        printf("bool: %d\n", lua_n.args.get_bool(args,index));
    }
    else{
        const char *converted_to_str = lua_n.convert_arg_code(arg_type);
        printf("type: %s\n",converted_to_str);
    }

    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);

    lua_n.evaluate(l,"test()");
    lua_n.evaluate(l,"test(10)");
    lua_n.evaluate(l,"test('hello')");
    lua_n.evaluate(l,"test(true)");
    lua_n.evaluate(l,"test({a=30})");


    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~


It will produce:


~~~txt
no argument providided
number: 10.000000
str: hello
bool: 1
type: table

~~~



#### Creating a basic print function

in these example, we are creating an 'print' function ,to allow print values


~~~c

#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * print_func(LuaCEmbed *args){
    long size = lua_n.args.size(args);
   for(int index =0;index < size;index++ ){
       int arg_type = lua_n.args.get_type(args,index);

       if(arg_type  == lua_n.types.NUMBER){
           printf("%lf\n",lua_n.args.get_double(args,index));
       }

       else if(arg_type  == lua_n.types.STRING){
           printf("%s\n",lua_n.args.get_str(args,index));
       }

       else if(arg_type  == lua_n.types.BOOL){
           bool result = lua_n.args.get_bool(args,index);
          const  char *converted_bool = result? "true":"false";
           printf("%s\n", converted_bool);
       }
       else{
           const char *converted_to_str = lua_n.convert_arg_code(arg_type);
           printf("%s\n",converted_to_str);
       }

   }


    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"print",print_func);


    lua_n.evaluate(l,"print(10,30,'aa',true,{a=30})");


    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
10.000000
30.000000
aa
true
table

~~~


#### Evaluating arguments

it's also possible to modify callbacks by lua code , by using the evaluation args mechanism.


~~~c

#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * add_func(LuaCEmbed *args){


    double num1 = lua_n.args.get_long_arg_clojure_evalation(args,0,"function(t) return t.num1  end ");
    double num2 = lua_n.args.get_long_arg_clojure_evalation(args,0,"function(t) return t.num2  end ");

    if(lua_n.has_errors(args)){
        char *error_message = lua_n.get_error_message(args);
        return lua_n.response.send_error(error_message);
    }
    return lua_n.response.send_double(num1+num2);
    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"add",add_func);


   double result = lua_n.get_evaluation_double(l,"add({num1=10, num2=30})");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
   printf("resullt :%lf\n",result);

    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
resullt :40.000000

~~~

#### Calling args callback

if you recive a lambda as argument , you can run the function with rguments and retriving its result


~~~c

#include "LuaCEmbed.h"


LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){

    LuaCEmbedTable *created = lua_n.tables.new_anonymous_table(args);
    lua_n.tables.append_long(created,10);
    lua_n.tables.append_long(created,20);
    LuaCEmbedTable *response = lua_n.args.run_lambda(args,0,created,3);
    double result = lua_n.tables.get_double_by_index(response,0);

    printf("result %lf\n",result);

    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);

    lua_n.evaluate(l,"test(function (a,b) return a + b end )");


    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
result 30.000000

~~~


#### Table Arguments
you can control table arguments easly with the **get_table** method, where you can retrive a
**LuaCEmbedTable** object



~~~c

#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * add_func(LuaCEmbed *args){

    LuaCEmbedTable  *t0 = lua_n.args.get_table(args,0);

    if(lua_n.has_errors(args)){
        char *error_message = lua_n.get_error_message(args);
        return lua_n.response.send_error(error_message);
    }

    double num1 = lua_n.tables.get_double_prop(t0,"num1");
    double num2 = lua_n.tables.get_double_prop(t0,"num2");


    if(lua_n.has_errors(args)){
        char *error_message = lua_n.get_error_message(args);
        return lua_n.response.send_error(error_message);
    }
    return lua_n.response.send_double(num1+num2);
    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"add",add_func);


   double result = lua_n.get_evaluation_double(l,"add({num1=10, num2=30})");
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
   printf("resullt :%lf\n",result);

    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
resullt :40.000000

~~~

### Callbacks Response

You also can return  values or errors, with the **response** methods

#### Returning a Long



~~~c

#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    return lua_n.response.send_long(30);
}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);


   long result = lua_n.get_evaluation_long(l,"test()");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
   printf("resullt :%ld\n",result);
    
    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
resullt :30

~~~

#### Returning a Double



~~~c

#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    return lua_n.response.send_double(30);
}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);


   double result = lua_n.get_evaluation_double(l,"test()");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
   printf("resullt :%lf\n",result);
    
    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
resullt :30.000000

~~~

#### Returning a String



~~~c

#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    return lua_n.response.send_str("str return");
}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);


   char * result = lua_n.get_string_evaluation(l,"test()");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
   printf("resullt :%s\n",result);
    
    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
resullt :str return

~~~

#### Returning a Bool



~~~c

#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    return lua_n.response.send_bool(true);
}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);


   bool result = lua_n.get_evaluation_bool (l,"test()");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
   printf("resullt :%d\n",result);
    
    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
resullt :1

~~~

#### Returning a Table



~~~c

#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    LuaCEmbedTable *created = lua_n.tables.new_anonymous_table(args);
    lua_n.tables.set_string_prop(created,"a","test message");
    return lua_n.response.send_table(created);
}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);


    lua_n.evaluate(l,"created_table = test()");
    LuaCEmbedTable *created = lua_n.globals.get_table(l,"created_table");
    char *a = lua_n.tables.get_string_prop(created,"a");
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

   printf("value of created.a = %s\n",a);
    
    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
value of created.a = test message

~~~


#### Returning multi return

You also can return multi values at once  with the **return_multi_return** method


~~~c

#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){

    LuaCEmbedTable * multi_response  = lua_n.tables.new_anonymous_table(args);
    lua_n.tables.append_string(multi_response,"first");
    lua_n.tables.append_long(multi_response,10);
    return lua_n.response.send_multi_return(multi_response);
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);


    lua_n.evaluate(l,"a,b =test()");
    char *a = lua_n.get_string_evaluation(l,"a");
    long b = lua_n.get_evaluation_long(l,"b");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    printf("a = %s\n",a);
    printf("b = %ld\n",b);


    lua_n.free(l);

    return 0;
}
~~~


It will produce:


~~~txt
a = first
b = 10

~~~

you can return multiple values using the multi return method


#### Returning a a Error
you can "raise" a error by returning a error in the function


~~~c

#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    return lua_n.response.send_error("my custom error menssage");
}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);


   lua_n.evaluate(l,"test()");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
error: my custom error menssage

~~~

### Table Handling
you can easly handle tables, with the getters and setters methods

#### Retriving table props


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;

LuaCEmbedResponse  * show_table(LuaCEmbed *args){

    LuaCEmbedTable * t1 = lua_n.args.get_table(args,0);
    if(lua_n.has_errors(args)){
        char *menssage = lua_n.get_error_message(args);
        return  lua_n.response.send_error(menssage);
    }

    char *name  = lua_n.tables.get_string_prop(t1,"name");
    long age = lua_n.tables.get_long_prop(t1,"age");

    if(lua_n.has_errors(args)){
        char *menssage = lua_n.get_error_message(args);
        return  lua_n.response.send_error(menssage);
    }

    printf("name : %s\n",name);
    printf("age: %ld\n",age);

    return NULL;
}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"show_table", show_table);
    lua_n.evaluate(l,"show_table({name='mateus',age=27})");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
name : mateus
age: 27

~~~


#### Retriving Sub Tables



~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;

LuaCEmbedResponse  * show_table(LuaCEmbed *args){

    LuaCEmbedTable * t1 = lua_n.args.get_table(args,0);
    if(lua_n.has_errors(args)){
        char *menssage = lua_n.get_error_message(args);
        return  lua_n.response.send_error(menssage);
    }

    long size = lua_n.tables.get_size(t1);
    for(int i = 0; i < size; i++){

        LuaCEmbedTable *current = lua_n.tables.get_sub_table_by_index(t1,i);
        char *name  = lua_n.tables.get_string_prop(current,"name");
        long age = lua_n.tables.get_long_prop(current,"age");

        if(lua_n.has_errors(args)){
            char *menssage = lua_n.get_error_message(args);
            return  lua_n.response.send_error(menssage);
        }

        printf("name : %s\n",name);
        printf("age: %ld\n",age);

        printf("------------------------------------------\n");
    }
    
    return NULL;

}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"show_table", show_table);
    lua_n.evaluate(l,"show_table({{name='mateus',age=27},{name='john',age=30}} )");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
name : mateus
age: 27
------------------------------------------
name : john
age: 30
------------------------------------------

~~~

#### Iterating over table


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;



LuaCEmbedResponse  * show_table(LuaCEmbed *args){

    LuaCEmbedTable * t1 = lua_n.args.get_table(args,0);
    if(lua_n.has_errors(args)){
        char *menssage = lua_n.get_error_message(args);
        return  lua_n.response.send_error(menssage);
    }
    long size = lua_n.tables.get_size(t1);
    for(int i = 0; i <size;i++){
        printf("index: %d\n",i);
        const char *key= "Not provided";
        if(lua_n.tables.has_key(t1,i)){
            key = lua_n.tables.get_key_by_index(t1,i);
        }
        printf("key: %s\n",key);

        int type= lua_n.tables.get_type_by_index(t1,i);
        printf("type %s\n",lua_n.convert_arg_code(type));

        if(type == lua_n.types.NUMBER){
            double value = lua_n.tables.get_double_by_index(t1,i);
            printf("value: %lf\n",value);
        }

        if(type == lua_n.types.STRING){
            char * value = lua_n.tables.get_string_by_index(t1,i);
            printf("value: %s\n",value);
        }

        if(type == lua_n.types.BOOL){
            bool value = lua_n.tables.get_bool_by_index(t1,i);
            printf("value: %d\n",value);
        }
        printf("------------------------------------------\n");
    }
    return NULL;
}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"show_table", show_table);
    lua_n.evaluate(l,"show_table({name='Mateus',age=27,single=true,'indexable random string'})");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}

~~~

It will produce:


~~~txt
index: 0
key: Not provided
type string
value: indexable random string
------------------------------------------
index: 1
key: name
type string
value: Mateus
------------------------------------------
index: 2
key: age
type number
value: 27.000000
------------------------------------------
index: 3
key: single
type boolean
value: 1
------------------------------------------

~~~


### Table setting
its possible to set values of table in a lot of different ways

#### Seting  basic Props

~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;

LuaCEmbedResponse  * create_table(LuaCEmbed *args){

    LuaCEmbedTable *custom_table =  lua_n.tables.new_anonymous_table(args);
    lua_n.tables.set_string_prop(custom_table,"name","Mateus");
    lua_n.tables.set_long_prop(custom_table,"age",27);
    lua_n.tables.set_double_prop(custom_table,"height",1.82);
    lua_n.tables.set_bool_prop(custom_table,"married",false);
    return lua_n.response.send_table(custom_table);

}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"create_person", create_table);
    lua_n.evaluate(l,"r = create_person()");

    char *name = lua_n.get_string_evaluation(l,"r.name");
    long age  = lua_n.get_evaluation_long(l,"r.age");
    double height = lua_n.get_evaluation_double(l,"r.height");
    bool married = lua_n.get_evaluation_bool(l,"r.married");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    if(!lua_n.has_errors(l)){
        printf("name: %s\n",name);
        printf("age: %ld\n",age);
        printf("height: %lf\n",height);
        printf("married %d\n",married);
    }

    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
name: Mateus
age: 27
height: 1.820000
married 0

~~~


#### Setting Methods
you also can set a method to a table, passing a callback function for it


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;

LuaCEmbedResponse  * describe( LuaCEmbedTable  *self,LuaCEmbed *args){
    char *name = lua_n.tables.get_string_prop(self,"name");
    long age  = lua_n.tables.get_long_prop(self,"age");
    double height = lua_n.tables.get_double_prop(self,"height");
    bool married = lua_n.tables.get_bool_prop(self,"married");
    printf("person description:\n");
    printf("name: %s\n",name);
    printf("age: %ld\n",age);
    printf("height: %lf\n",height);
    printf("married %d\n",married);
    return NULL;

}
LuaCEmbedResponse  * create_table(LuaCEmbed *args){

    LuaCEmbedTable *custom_table =  lua_n.tables.new_anonymous_table(args);
    lua_n.tables.set_string_prop(custom_table,"name","Mateus");
    lua_n.tables.set_long_prop(custom_table,"age",27);
    lua_n.tables.set_double_prop(custom_table,"height",1.82);
    lua_n.tables.set_bool_prop(custom_table,"married",false);
    lua_n.tables.set_method(custom_table,"describe",describe);
    return lua_n.response.send_table(custom_table);

}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"create_person", create_table);
    lua_n.evaluate(l,"r = create_person()");
    lua_n.evaluate(l,"r.describe()");
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
person description:
name: Mateus
age: 27
height: 1.820000
married 0

~~~

#### Setting Meta Methods
Meta methods like **__gc** or **__index** works fine tool


~~~c

#include "LuaCEmbed.h"

LuaCEmbedNamespace  lua_n;



LuaCEmbedResponse * index_callback(LuaCEmbedTable *self, LuaCEmbed *args){




    int value_type = lua_n.args.get_type(args,1);

    if(value_type == lua_n.types.NUMBER){
        printf("index-value: %lf\n",lua_n.args.get_double(args,1));
    }

    else if(value_type == lua_n.types.STRING){
        printf("index-value: %s\n",lua_n.args.get_str(args,1));
    }


    return NULL;
}

LuaCEmbedResponse * deletion_callback(LuaCEmbedTable *self, LuaCEmbed *args){

    printf("called the delete function\n");
    return NULL;
}

LuaCEmbedResponse  * create_table(LuaCEmbed *args){

    LuaCEmbedTable *custom_table =  lua_n.tables.new_anonymous_table(args);
    lua_n.tables.set_method(custom_table,"__gc",deletion_callback);
    lua_n.tables.set_method(custom_table,"__index",index_callback);
    return lua_n.response.send_table(custom_table);

}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"create_object", create_table);
    lua_n.evaluate(l,"r = create_object()");
    lua_n.evaluate(l,"v = r[10]");
    lua_n.evaluate(l,"v = r['sss']");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    lua_n.free(l);

    return 0;
}

~~~

It will produce:


~~~txt
index-value: 10.000000
index-value: sss
called the delete function

~~~

### Full Object construction

in these example we are creating a **full class ** of a person


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * describe( LuaCEmbedTable  *self,LuaCEmbed *args){
    char *name = lua_n.tables.get_string_prop(self,"name");
    long age  = lua_n.tables.get_long_prop(self,"age");
    double height = lua_n.tables.get_double_prop(self,"height");
    bool married = lua_n.tables.get_bool_prop(self,"married");
    printf("person description:\n");
    printf("name: %s\n",name);
    printf("age: %ld\n",age);
    printf("height: %lf\n",height);
    printf("married %d\n",married);
    return NULL;

}
LuaCEmbedResponse  * create_table(LuaCEmbed *args){

    char *name = lua_n.args.get_str(args,0);
    long age  = lua_n.args.get_long(args,1);
    double height = lua_n.args.get_double(args,2);
    bool maried = lua_n.args.get_bool(args,3);

    if(lua_n.has_errors(args)){
      const char *error_message = lua_n.get_error_message(args);
      return lua_n.response.send_error(error_message);
    }

    LuaCEmbedTable *custom_table =  lua_n.tables.new_anonymous_table(args);
    lua_n.tables.set_string_prop(custom_table,"name",name);
    lua_n.tables.set_long_prop(custom_table,"age",age);
    lua_n.tables.set_double_prop(custom_table,"height",height);
    lua_n.tables.set_bool_prop(custom_table,"married",maried);
    lua_n.tables.set_method(custom_table,"describe",describe);
    return lua_n.response.send_table(custom_table);

}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"create_person", create_table);
    lua_n.evaluate(l,"r = create_person('test',30,1.4,true)");
    lua_n.evaluate(l,"r.describe()");
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
person description:
name: test
age: 30
height: 1.400000
married 1

~~~

### Appending Props
you also can work with arrays , by using the **append** methods


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;

LuaCEmbedResponse  * create_table(LuaCEmbed *args){

    LuaCEmbedTable *custom_table =  lua_n.tables.new_anonymous_table(args);
    lua_n.tables.append_string(custom_table,"test1");
    lua_n.tables.append_string(custom_table,"test2");
    lua_n.tables.append_string(custom_table,"test3");

    return lua_n.response.send_table(custom_table);

}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"create_string_array", create_table);
    lua_n.evaluate(l,"r = create_string_array()");
    LuaCEmbedTable *table = lua_n.globals.get_table(l,"r");
    long size =lua_n.tables.get_size(table);

    for(int i = 0; i < size; i++){
        char  *current = lua_n.tables.get_string_by_index(table,i);
        if(!lua_n.has_errors(l)){
            printf("%s\n",current);
        }
    }

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }


    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
test1
test2
test3

~~~

### Setting sub tables
sub tables can be constructed, setted and autocreated


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;

LuaCEmbedResponse  * create_table(LuaCEmbed *args){

    LuaCEmbedTable *custom_table =  lua_n.tables.new_anonymous_table(args);
    LuaCEmbedTable *sub_table = lua_n.tables.new_anonymous_table(args);
    lua_n.tables.set_string_prop(sub_table,"test","custom text");
    lua_n.tables.set_sub_table_prop(custom_table,"sub_table",sub_table);

    return lua_n.response.send_table(custom_table);

}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"create_table", create_table);
    lua_n.evaluate(l,"r = create_table()");

    char *test = lua_n.get_string_evaluation(l,"r.sub_table.test");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    if(!lua_n.has_errors(l)){
        printf("%s\n",test);
    }

    lua_n.free(l);

    return 0;
}
~~~

It will produce:


~~~txt
custom text

~~~


### Globals
Glbals can be fully handled by the LuaCEmbed Api

#### Retriving Globals

#### Getting a global string


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate(l,"r = 'hello world'");
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


~~~txt
result hello world

~~~

#### Getting a global bool


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate(l,"r = true");
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



~~~txt
result 1

~~~

#### Getting a double global


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate(l,"r = 30.5");
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


~~~txt
result 30.500000

~~~


#### Getting a long global


~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate(l,"r = 30");
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


~~~txt
result 30

~~~

#### Getting a type global

~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate(l,"r = 'hello world'");
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


~~~txt
result string

~~~
#### Getting a table
Tables are by default auto created, so yoou can just use the **get_table_auto_creating**  method

~~~c
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate(l,"r = {a='internal text'}");
    LuaCEmbedTable *r_table  = lua_n.globals.get_table(l,"r");
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


~~~txt
value of r.a = internal text

~~~

### Setting Globals

Its also possible to set global variables

#### Set Long

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


~~~txt
result 30.000000

~~~
#### Set Double

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


~~~txt
result 30.000000

~~~
#### Set string

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


~~~txt
result hello world

~~~

#### Set Bool

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


~~~txt
result 1

~~~

#### New Table
its possible to create a new global table, the vallues will be automaticaly setted


#### Set Bool

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


~~~txt
result of r.a internal text

~~~

