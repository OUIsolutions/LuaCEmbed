
#include "src/one.c"
LuaCEmbedNamespace  lua;

LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * create_table(LuaCEmbed *args){

    LuaCEmbedTable * t1 = lua_n.tables.new_anonymous_table(args);
    LuaCEmbedTable   *t2 = lua_n.tables.new_sub_table(t1,"a");
    lua_n.tables.set_string_prop(t2,"test","value of test\n");

    return lua_n.response.send_table(t1);
}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"create", create_table);
    lua_n.evaluate_string(l,"r = create()");
    char *test = lua_n.get_string_evaluation(l,"r.a.test");
    printf("%s\n",test);

    lua_n.free(l);

    return 0;
}
//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c && lua teste.lua