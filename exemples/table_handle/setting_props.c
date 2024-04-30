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