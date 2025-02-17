
LuaCEmbed it's  a lua wrapper to allow easy interoperability beetwen C and Lua
providing any methods to control Lua Code from C

<h3 style="color:red;">
DESPITE BEING 100% COVERED BY TESTS, THIS LIBRARY IS NOT CONSIDERED PRODUCTION READY YET, USE RESPONSIBLY
</h3>


{HASHTAG}{HASHTAG}{HASHTAG} Usefull Links


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Lua Project
[Lua Project](https://www.lua.org/)

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Oui WebSite
[Link to Web Site](oui.tec.br)

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Download Link
[Click Here to Download](https://github.com/OUIsolutions/LuaCEmbed/releases/download/v0.75/LuaCEmbed.h)


{HASHTAG}{HASHTAG}{HASHTAG} Instalation
Like all Oui librarys, the LuaCEmbed addopt the ideia of single file lib, so you just need to copy the **LuaCEmbed.h** file
into your project, and compile with gcc/clang 
{create_c_example("exemples/evaluation/hello_world.c")}



It will produce:

{create_c_example("tests/main_test/evaluation/T_hello_world/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG} Runting Native functions
<h3 style="color:red;">
NEVER CALL THE FUNCTION 'load_native_libs' IF YOU DON TRUST IN THE USER 
</h3>
You can load native lua functions by the usage of **load_native_libs** function 

{create_c_example("exemples/evaluation/basic_evaluation_with_loaded_libs.c")}


It will produce:
{create_c_example("tests/main_test/evaluation/T_basic_evaluation_with_loaded_libs/expected.txt")}



{HASHTAG}{HASHTAG}{HASHTAG} Making a library
in the same way we can execute lua from C, we also can generate dll/so to be acessible by lua as a library

~~~c

{HASHTAG}include "LuaCEmbed.h"

LuaCEmbedNamespace  lua_n;


    LuaCEmbedResponse  *add_cfunc(LuaCEmbed *args)#{
    double first_num = lua_n.args.get_double(args,0);
    double second_num = lua_n.args.get_double(args,1);

    if(lua_n.has_errors(args))#{
        char *message = lua_n.get_error_message(args);
        return lua_n.response.send_error(message);
    }#/
    double result = first_num + second_num;
    return lua_n.response.send_double(result);
}#/
LuaCEmbedResponse  *sub_cfunc(LuaCEmbed *args)#{
    double first_num = lua_n.args.get_double(args,0);
    double second_num = lua_n.args.get_double(args,1);

    if(lua_n.has_errors(args))#{
        char *message = lua_n.get_error_message(args);
        return lua_n.response.send_error(message);
    }#/
    double result = first_num - second_num;
    return lua_n.response.send_double(result);
}#/
int luaopen_my_lib(lua_State *state)#{
    lua_n = newLuaCEmbedNamespace();
    //functions will be only assescible by the required reciver
    LuaCEmbed * l  = lua_n.newLuaLib(state);
    lua_n.add_callback(l,"add",add_cfunc);
    lua_n.add_callback(l,"sub",sub_cfunc);

return lua_n.perform(l);

}#/
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
{HASHTAG}{HASHTAG}{HASHTAG} Lib Props
you can determine library props into your lib:
~~~c 


{HASHTAG}include "LuaCEmbed.h"

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


{HASHTAG}{HASHTAG}{HASHTAG} Evaluation
To evaluate Lua Code from C, you can use all the evaluation methods, provided by the lib


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Evaluating string

{create_c_example("exemples/evaluation/string_evalation.c")}


It will produce:

{create_c_example("tests/main_test/evaluation/T_string_evalation/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Evaluating a file
It's also possible to evaluate a file by using the **evaluete_file** method

{create_c_example("exemples/evaluation/file_evaluation.c")}


It will produce:

{create_c_example("tests/main_test/evaluation/T_file_evaluation/expected.txt")}




{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Type Evaluation
You can determine the type of the evaluation by using the **get_evaluation_type** method
{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Evaluating Long

{create_c_example("exemples/evaluation/type_evaluation.c")}



It will produce:

{create_c_example("tests/main_test/evaluation/T_type_evaluation/expected.txt")}




{HASHTAG}{HASHTAG}{HASHTAG} Table Size
Its also possible to determine the size of a table by using the **get_evaluation_size** method

{create_c_example("exemples/evaluation/table_size.c")}



It will produce:

{create_c_example("tests/main_test/evaluation/T_table_size/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Evaluating Long

{create_c_example("exemples/evaluation/long_return.c")}


It will produce:

{create_c_example("tests/main_test/evaluation/T_long_return/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Evaluating Double

{create_c_example("exemples/evaluation/double_evaluation.c")}



It will produce:

{create_c_example("tests/main_test/evaluation/T_double_evaluation/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Evaluating Bool

{create_c_example("exemples/evaluation/bool_evaluation.c")}


It will produce:

{create_c_example("tests/main_test/evaluation/T_bool_evaluation/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG} Timeout
You can set timeout to your functions, by using the timeout method:


{create_c_example("exemples/evaluation/timeout.c")}


It will produce:

{create_c_example("tests/main_test/evaluation/T_timeout/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG} Memory usage
by using the method **set_memory_limit** you can control the max ram usage of lua, the default its 100mb
<h5 style="color:red;">NOTE THAT EXTRA MEMORY ALOCATED OUTSIDE CALLBACKS OR EVALUATIONS  ARE CONSIDER UNPROTECTED GEHAVIOR
AND IT WILL KILL THE APPLICATION

</h5>



{create_c_example("exemples/evaluation/memory_usage.c")}


It will produce:

{create_c_example("tests/main_test/evaluation/T_memory_usage/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG} Callbacks
Callbacks i'ts a way to make c functions assesible in lua code, this it's the most basic callback:

{create_c_example("exemples/calbacks/basic_callback.c")}


It will produce:

{create_c_example("tests/main_test/calbacks/T_basic_callback/expected.txt")}




{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} CallBack args
you can accept callback arguments into your function,check their types, and make operations with them.

{create_c_example("exemples/calbacks/args_retriving.c")}


It will produce:

{create_c_example("tests/main_test/calbacks/T_args_retriving/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Index type
The lua native language index first elements in position 1, authogth LuaCEmbed use the C style for indexation, starting at
0, but these can be easly reverted with the int macro **LUA_CEMBED_INDEX_DIF**

{create_c_example("exemples/calbacks/args_retriving_balanced.c")}



It will produce:

{create_c_example("tests/main_test/calbacks/T_args_retriving_balanced/expected.txt")}




{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Creating a basic print function

in these example, we are creating an 'print' function ,to allow print values

{create_c_example("exemples/calbacks/print_func.c")}


It will produce:

{create_c_example("tests/main_test/calbacks/T_print_func/expected.txt")}



{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Evaluating arguments

it's also possible to modify callbacks by lua code , by using the evaluation args mechanism.

{create_c_example("exemples/calbacks/evaluating_args.c")}


It will produce:

{create_c_example("tests/main_test/calbacks/T_evaluating_args/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Calling args callback

if you recive a lambda as argument , you can run the function with rguments and retriving its result

{create_c_example("exemples/calbacks/args_lambda.c")}


It will produce:

{create_c_example("tests/main_test/calbacks/T_args_lambda/expected.txt")}



{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Table Arguments
you can control table arguments easly with the **get_table** method, where you can retrive a
**LuaCEmbedTable** object


{create_c_example("exemples/calbacks/getting_table_args.c")}


It will produce:

{create_c_example("tests/main_test/calbacks/T_getting_table_args/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG} Callbacks Response

You also can return  values or errors, with the **response** methods

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Returning a Long


{create_c_example("exemples/calbacks/return_long.c")}


It will produce:

{create_c_example("tests/main_test/calbacks/T_return_long/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Returning a Double


{create_c_example("exemples/calbacks/return_double.c")}


It will produce:

{create_c_example("tests/main_test/calbacks/T_return_double/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Returning a String


{create_c_example("exemples/calbacks/return_string.c")}


It will produce:

{create_c_example("tests/main_test/calbacks/T_return_string/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Returning a Bool


{create_c_example("exemples/calbacks/return_bool.c")}


It will produce:

{create_c_example("tests/main_test/calbacks/T_return_bool/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Returning a Table


{create_c_example("exemples/calbacks/return_table.c")}


It will produce:

{create_c_example("tests/main_test/calbacks/T_return_table/expected.txt")}



{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Returning multi return

You also can return multi values at once  with the **return_multi_return** method

{create_c_example("exemples/calbacks/return_multi_return.c")}



It will produce:

{create_c_example("tests/main_test/calbacks/T_return_multi_return/expected.txt")}


you can return multiple values using the multi return method


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Returning a a Error
you can "raise" a error by returning a error in the function

{create_c_example("exemples/calbacks/return_error.c")}


It will produce:

{create_c_example("tests/main_test/calbacks/T_return_error/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG} Table Handling
you can easly handle tables, with the getters and setters methods

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Retriving table props

{create_c_example("exemples/table_handle/retriving_props.c")}


It will produce:

{create_c_example("tests/main_test/table_handle/T_retriving_props/expected.txt")}



{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Retriving Sub Tables


{create_c_example("exemples/table_handle/retriving_sub_table.c")}


It will produce:

{create_c_example("tests/main_test/table_handle/S_retriving_sub_table/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Iterating over table

{create_c_example("exemples/table_handle/iterating_over_table.c")}


It will produce:

{create_c_example("tests/main_test/table_handle/S_iterating_over_table/expected.txt")}



{HASHTAG}{HASHTAG}{HASHTAG} Table setting
its possible to set values of table in a lot of different ways

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Seting  basic Props
{create_c_example("exemples/table_handle/setting_props.c")}


It will produce:

{create_c_example("tests/main_test/table_handle/T_setting_props/expected.txt")}



{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Setting Methods
you also can set a method to a table, passing a callback function for it

{create_c_example("exemples/table_handle/setting_method.c")}


It will produce:

{create_c_example("tests/main_test/table_handle/T_setting_method/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Setting Meta Methods
Meta methods like **__gc** or **__index** works fine tool

{create_c_example("exemples/table_handle/meta_method.c")}


It will produce:

{create_c_example("tests/main_test/table_handle/T_meta_method/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG} Full Object construction

in these example we are creating a **full class ** of a person

{create_c_example("exemples/table_handle/full_person.c")}


It will produce:

{create_c_example("tests/main_test/table_handle/T_full_person/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG} Appending Props
you also can work with arrays , by using the **append** methods

{create_c_example("exemples/table_handle/appending_props.c")}


It will produce:

{create_c_example("tests/main_test/table_handle/T_appending_props/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG} Setting sub tables
sub tables can be constructed, setted and autocreated

{create_c_example("exemples/table_handle/setting_sub_table.c")}


It will produce:

{create_c_example("tests/main_test/table_handle/T_setting_sub_table/expected.txt")}



{HASHTAG}{HASHTAG}{HASHTAG} Globals
Glbals can be fully handled by the LuaCEmbed Api

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Retriving Globals

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Getting a global string

{create_c_example("exemples/globals/get_string_global.c")}


It will produce:

{create_c_example("tests/main_test/globals/T_get_string_global/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Getting a global bool

{create_c_example("exemples/globals/get_bool_global.c")}


It will produce:


{create_c_example("tests/main_test/globals/T_get_bool_global/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Getting a double global

{create_c_example("exemples/globals/get_double_global.c")}


It will produce:

{create_c_example("tests/main_test/globals/T_get_double_global/expected.txt")}



{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Getting a long global

{create_c_example("exemples/globals/get_long_global.c")}


It will produce:

{create_c_example("tests/main_test/globals/T_get_long_global/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Getting a type global
{create_c_example("exemples/globals/get_type.c")}


It will produce:

{create_c_example("tests/main_test/globals/T_get_type/expected.txt")}

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Getting a table
Tables are by default auto created, so yoou can just use the **get_table_auto_creating**  method
{create_c_example("exemples/globals/get_table_global.c")}

It will produce:

{create_c_example("tests/main_test/globals/T_get_table_global/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG} Setting Globals

Its also possible to set global variables

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Set Long
{create_c_example("exemples/globals/set_long.c")}

It will produce

{create_c_example("tests/main_test/globals/T_set_long/expected.txt")}

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Set Double
{create_c_example("exemples/globals/set_double.c")}

It will produce

{create_c_example("tests/main_test/globals/T_set_double/expected.txt")}

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Set string
{create_c_example("exemples/globals/set_string.c")}


It will produce

{create_c_example("tests/main_test/globals/T_set_string/expected.txt")}


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Set Bool
{create_c_example("exemples/globals/set_bool.c")}

It will produce

{create_c_example("tests/main_test/globals/T_set_bool/expected.txt")}

{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} New Table
its possible to create a new global table, the vallues will be automaticaly setted


{HASHTAG}{HASHTAG}{HASHTAG}{HASHTAG} Set Bool
{create_c_example("exemples/globals/set_table.c")}

It will produce

{create_c_example("tests/main_test/globals/T_set_table/expected.txt")}


