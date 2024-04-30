
#include "src/one.c"
LuaCEmbedNamespace  lua;

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
//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c && lua teste.lua