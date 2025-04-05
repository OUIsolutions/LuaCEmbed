### Making a library
in the same way we can execute lua from C, we also can generate dll/so to be acessible by lua as a library

~~~c

#include "LuaCEmbedOne.c"

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
gcc -shared -fpic -o my_lib.so  main.c
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


#include "LuaCEmbedOne.c"

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
