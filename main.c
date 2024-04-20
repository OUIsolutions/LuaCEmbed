
#include "src/one.c"
LuaCEmbedNamespace  lua_n;






int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate_string(l,"r = {name='Mateus',age=27, height=1.80, single=true}");

    char *name = lua_n.globals.table.get_string(l,"r","{'name'}");

    long age = lua_n.globals.table.get_long(l,"r","{'age'}");
    bool single = lua_n.globals.table.get_bool(l,"r","{'single'}");
    double height = lua_n.globals.table.get_double(l,"r","{'height'}");


    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    else{
        printf("name: %s\n",name);
        printf("age: %ld\n",age);
        printf("height: %lf\n",height);
        printf("single: %d\n",single);
    }
    
    lua_n.free(l);

    return 0;
}
//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c 