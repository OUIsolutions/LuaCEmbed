
#include "src/one.c"
LuaCEmbedNamespace  lua_n;




LuaCEmbedResponse  *increment(LuaCembedTable *self,LuaCEmbed *args){

    printf("chamou\n");

    return NULL;
}


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    LuaCembedTable *t1 = lua_n.globals.new_table(l,"test");

    lua_n.tables.set_long_prop(t1,"v",0);
    lua_n.tables.set_method(t1,"increment",increment);

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    
    lua_n.free(l);

    return 0;
}
//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c 