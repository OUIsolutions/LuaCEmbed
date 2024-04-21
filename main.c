
#include "src/one.c"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  *test (LuaCEmbed *args){

    LuaCEmbedTable * t = lua_n.args.get_table(args,0);
    if(lua_n.has_errors(args)){
        lua_n.raise_error(args,lua_n.get_error_message(args));
        return NULL;
    }

    printf("a = %ld",lua_n.tables.get_long_prop(t,"teste"));
    if(lua_n.has_errors(args)){
        lua_n.raise_error(args,lua_n.get_error_message(args));
    }

    return NULL;
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