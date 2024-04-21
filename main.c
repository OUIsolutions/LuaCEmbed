
#include "src/one.c"
LuaCEmbedNamespace  lua_n;






int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    LuaCembedTable *t1 = lua_n.globals.new_table(l,"test");
    printf("pegou aqui\n");

    lua_n.tables.set_string_prop(t1,"a","vai se fuder");
    lua_n.tables.set_string_prop(t1,"b","não pode aparecer");

    char *test = lua_n.get_string_evaluation(l,"test.a");
    printf("test: %s\n",test);
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    
    lua_n.free(l);

    return 0;
}
//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c 