
#include "src/one.c"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  *test (LuaCEmbed *args){
    return NULL;
}



int luaopen_lib(lua_State *L) {
    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaLib(L,false);

    lua_n.add_callback(l, "test", test);

    lua_n.perform(l);
    return 1;

}

/*
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate_string(l,"test ={a=30,x=40,b=90,d=30};");


    LuaCEmbedTable *t1  = lua_n.globals.get_table_auto_creating(l, "test");

    LuaCEmbedTable  *t2 = lua_n.tables.get_sub_table_auto_creating(t1, "teste2");
    LuaCEmbedTable  *t3 = lua_n.tables.get_sub_table_auto_creating(t1, "teste2");

    lua_n.tables.set_string_prop(t2,"a","va se fuder funcinou porra");

    printf("%s",lua_n.get_string_evaluation(l,"test.teste2.a"));

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    
    lua_n.free(l);

    return 0;

}
 */
//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c 