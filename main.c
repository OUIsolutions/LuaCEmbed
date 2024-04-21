
#include "src/one.c"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  *test (LuaCEmbed *args){

    LuaCEmbedTable *t1 = lua_n.new_anonymous_table(args);
    lua_n.tables.set_string_prop(t1,"valor","vai se fuder");
    return lua_n.response.send_table(t1);

}



int luaopen_minha_biblioteca(lua_State *L) {
    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaLib(L,false);

    lua_n.add_callback(l, "test", test);

    lua_n.perform(l);
    return 1;

}


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l, "test", test);

    lua_n.evaluete_file(l,"teste.lua");


    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    
    lua_n.free(l);

    return 0;

}

//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c 