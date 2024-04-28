
#include "src/one.c"
LuaCEmbedNamespace  lua;

LuaCEmbedNamespace  lua_n;

LuaCEmbedResponse  * show_table(LuaCEmbed *args){

    LuaCEmbedTable * t1 = lua_n.args.get_table(args,0);
    if(lua_n.has_errors(args)){
        char *menssage = lua_n.get_error_message(args);
        return  lua_n.response.send_error(menssage);
    }

    char *name  = lua_n.tables.get_string_prop(t1,"name");
    long age = lua_n.tables.get_long_prop(t1,"age");

    if(lua_n.has_errors(args)){
        char *menssage = lua_n.get_error_message(args);
        return  lua_n.response.send_error(menssage);
    }

    printf("name : %s\n",name);
    printf("age: %ld\n",age);

    return NULL;
}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"show_table", show_table);
    lua_n.evaluate_string(l,"show_table({name='teste'})");
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}

//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c && lua teste.lua