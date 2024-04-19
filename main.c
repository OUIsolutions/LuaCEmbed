
#include "src/one.c"
LuaCEmbedNamespace  lua;

LuaCEmbedResponse * print_lua_value(LuaCEmbed *l){

    char *test = lua.args.table.get_arg_string(l,0,"{'s','c','d'}");
    printf("test: %s\n",test);



    return NULL;

}


LuaCEmbedResponse * soma(LuaCEmbed *l){

    int arg1 = (int)lua.args.get_long(l,0);
    int arg2 = (int)lua.args.get_long(l,1);

    return lua.response.send_long(arg1 + arg2);
}


// Função para carregar a biblioteca
int luaopen_lib(lua_State *L) {
    lua =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua.newLuaLib(L,false);

    lua.add_callback(l, "puts", print_lua_value);
    lua.add_callback(l, "soma", soma);
    lua.perform(l);
    return 1;

}

int main(){
    lua =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua.newLuaEvaluation();
    lua.add_callback(l,"puts",print_lua_value);
    lua.evaluete_file(l,"teste.lua");


    if(lua.has_errors(l)){
        printf("error: %s\n",lua.get_error_message(l));
    }
    lua.free(l);

    return 0;
}
//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c 