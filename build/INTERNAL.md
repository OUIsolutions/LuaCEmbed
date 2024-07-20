
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
<!--codeof:exemples/evaluation/hello_world.c-->
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

<!--codeof:tests/main_test/evaluation/T_hello_world/expected.txt-->
~~~txt
 
result 50
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

codeof:exemples/evaluation/string_evalation.c

It will produce:

codeof:tests/main_test/evaluation/T_string_evalation/expected.txt


#### Evaluating a file
It's also possible to evaluate a file by using the **evaluete_file** method

codeof:exemples/evaluation/file_evaluation.c


It will produce:

codeof:tests/main_test/evaluation/T_file_evaluation/expected.txt



#### Type Evaluation
You can determine the type of the evaluation by using the **get_evaluation_type** method
#### Evaluating Long

codeof:exemples/evaluation/type_evaluation.c


It will produce:

codeof:tests/main_test/evaluation/T_type_evaluation/expected.txt



### Table Size
Its also possible to determine the size of a table by using the **get_evaluation_size** method

codeof:exemples/evaluation/table_size.c


It will produce:

codeof:tests/main_test/evaluation/T_table_size/expected.txt

#### Evaluating Long

codeof:exemples/evaluation/long_return.c

It will produce:

codeof:tests/main_test/evaluation/T_long_return/expected.txt

#### Evaluating Double

codeof:exemples/evaluation/double_evaluation.c


It will produce:

codeof:tests/main_test/evaluation/T_double_evaluation/expected.txt

#### Evaluating Bool

codeof:exemples/evaluation/bool_evaluation.c

It will produce:

codeof:tests/main_test/evaluation/T_bool_evaluation/expected.txt

### Timeout
You can set timeout to your functions, by using the timeout method:


codeof:exemples/evaluation/timeout.c

It will produce:

codeof:tests/main_test/evaluation/T_timeout/expected.txt

### Memory usage
by using the method **set_memory_limit** you can control the max ram usage of lua, the default its 100mb
<h5 style="color:red;">NOTE THAT EXTRA MEMORY ALOCATED OUTSIDE CALLBACKS OR EVALUATIONS  ARE CONSIDER UNPROTECTED GEHAVIOR
AND IT WILL KILL THE APPLICATION

</h5>



codeof:exemples/evaluation/memory_usage.c

It will produce:

codeof:tests/main_test/evaluation/T_memory_usage/expected.txt

### Callbacks
Callbacks i'ts a way to make c functions assesible in lua code, this it's the most basic callback:

codeof:exemples/calbacks/basic_callback.c

It will produce:

codeof:tests/main_test/calbacks/T_basic_callback/expected.txt



#### CallBack args
you can accept callback arguments into your function,check their types, and make operations with them.

codeof:exemples/calbacks/args_retriving.c

It will produce:

codeof:tests/main_test/calbacks/T_args_retriving/expected.txt

#### Index type
The lua native language index first elements in position 1, authogth LuaCEmbed use the C style for indexation, starting at
0, but these can be easly reverted with the int macro **LUA_CEMBED_INDEX_DIF**

codeof:exemples/calbacks/args_retriving_balanced.c


It will produce:

codeof:tests/main_test/calbacks/T_args_retriving_balanced/expected.txt



#### Creating a basic print function

in these example, we are creating an 'print' function ,to allow print values

codeof:exemples/calbacks/print_func.c

It will produce:

codeof:tests/main_test/calbacks/T_print_func/expected.txt


#### Evaluating arguments

it's also possible to modify callbacks by lua code , by using the evaluation args mechanism.

codeof:exemples/calbacks/evaluating_args.c

It will produce:

codeof:tests/main_test/calbacks/T_evaluating_args/expected.txt

#### Calling args callback

if you recive a lambda as argument , you can run the function with rguments and retriving its result

codeof:exemples/calbacks/args_lambda.c

It will produce:

codeof:tests/main_test/calbacks/T_args_lambda/expected.txt


#### Table Arguments
you can control table arguments easly with the **get_table** method, where you can retrive a
**LuaCEmbedTable** object


codeof:exemples/calbacks/getting_table_args.c

It will produce:

codeof:tests/main_test/calbacks/T_getting_table_args/expected.txt

### Callbacks Response

You also can return  values or errors, with the **response** methods

#### Returning a Long


codeof:exemples/calbacks/return_long.c

It will produce:

codeof:tests/main_test/calbacks/T_return_long/expected.txt

#### Returning a Double


codeof:exemples/calbacks/return_double.c

It will produce:

codeof:tests/main_test/calbacks/T_return_double/expected.txt

#### Returning a String


codeof:exemples/calbacks/return_string.c

It will produce:

codeof:tests/main_test/calbacks/T_return_string/expected.txt

#### Returning a Bool


codeof:exemples/calbacks/return_bool.c

It will produce:

codeof:tests/main_test/calbacks/T_return_bool/expected.txt

#### Returning a Table


codeof:exemples/calbacks/return_table.c

It will produce:

codeof:tests/main_test/calbacks/T_return_table/expected.txt


#### Returning multi return

You also can return multi values at once  with the **return_multi_return** method

codeof:exemples/calbacks/return_multi_return.c


It will produce:

codeof:tests/main_test/calbacks/T_return_multi_return/expected.txt

you can return multiple values using the multi return method


#### Returning a a Error
you can "raise" a error by returning a error in the function

codeof:exemples/calbacks/return_error.c

It will produce:

codeof:tests/main_test/calbacks/T_return_error/expected.txt

### Table Handling
you can easly handle tables, with the getters and setters methods

#### Retriving table props

codeof:exemples/table_handle/retriving_props.c

It will produce:

codeof:tests/main_test/table_handle/T_retriving_props/expected.txt


#### Retriving Sub Tables


codeof:exemples/table_handle/retriving_sub_table.c

It will produce:

codeof:tests/main_test/table_handle/S_retriving_sub_table/expected.txt

#### Iterating over table

codeof:exemples/table_handle/iterating_over_table.c

It will produce:

codeof:tests/main_test/table_handle/S_iterating_over_table/expected.txt


### Table setting
its possible to set values of table in a lot of different ways

#### Seting  basic Props
codeof:exemples/table_handle/setting_props.c

It will produce:

codeof:tests/main_test/table_handle/T_setting_props/expected.txt


#### Setting Methods
you also can set a method to a table, passing a callback function for it

codeof:exemples/table_handle/setting_method.c

It will produce:

codeof:tests/main_test/table_handle/T_setting_method/expected.txt

#### Setting Meta Methods
Meta methods like **__gc** or **__index** works fine tool

codeof:exemples/table_handle/meta_method.c

It will produce:

codeof:tests/main_test/table_handle/T_meta_method/expected.txt

### Full Object construction

in these example we are creating a **full class ** of a person

codeof:exemples/table_handle/full_person.c

It will produce:

codeof:tests/main_test/table_handle/T_full_person/expected.txt

### Appending Props
you also can work with arrays , by using the **append** methods

codeof:exemples/table_handle/appending_props.c

It will produce:

codeof:tests/main_test/table_handle/T_appending_props/expected.txt

### Setting sub tables
sub tables can be constructed, setted and autocreated

codeof:exemples/table_handle/setting_sub_table.c

It will produce:

codeof:tests/main_test/table_handle/T_setting_sub_table/expected.txt


### Globals
Glbals can be fully handled by the LuaCEmbed Api

#### Retriving Globals

#### Getting a global string

codeof:exemples/globals/get_string_global.c

It will produce:

codeof:tests/main_test/globals/T_get_string_global/expected.txt

#### Getting a global bool

codeof:exemples/globals/get_bool_global.c

It will produce:


codeof:tests/main_test/globals/T_get_bool_global/expected.txt

#### Getting a double global

codeof:exemples/globals/get_double_global.c

It will produce:

codeof:tests/main_test/globals/T_get_double_global/expected.txt


#### Getting a long global

codeof:exemples/globals/get_long_global.c

It will produce:

codeof:tests/main_test/globals/T_get_long_global/expected.txt

#### Getting a type global
codeof:exemples/globals/get_type.c

It will produce:

codeof:tests/main_test/globals/T_get_type/expected.txt
#### Getting a table
Tables are by default auto created, so yoou can just use the **get_table_auto_creating**  method
codeof:exemples/globals/get_table_global.c
It will produce:

codeof:tests/main_test/globals/T_get_table_global/expected.txt

### Setting Globals

Its also possible to set global variables

#### Set Long
codeof:exemples/globals/set_long.c
It will produce

codeof:tests/main_test/globals/T_set_long/expected.txt
#### Set Double
codeof:exemples/globals/set_double.c
It will produce

codeof:tests/main_test/globals/T_set_double/expected.txt
#### Set string
codeof:exemples/globals/set_string.c

It will produce

codeof:tests/main_test/globals/T_set_string/expected.txt

#### Set Bool
codeof:exemples/globals/set_bool.c

It will produce

codeof:tests/main_test/globals/T_set_bool/expected.txt

#### New Table
its possible to create a new global table, the vallues will be automaticaly setted


#### Set Bool
codeof:exemples/globals/set_table.c

It will produce

codeof:tests/main_test/globals/T_set_table/expected.txt


