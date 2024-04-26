
#include "src/one.c"
LuaCEmbedNamespace  lua;

LuaCEmbedNamespace  lua_n;

LuaCEmbedResponse *soma(LuaCEmbed *args){
    double num1 = lua_n.args.get_double(args,0);
    double num2 =  lua_n.args.get_double(args,1);
    if(lua_n.has_errors(args)){
        return lua_n.response.send_error("chama a função direito danilo\n");
    }
    return lua_n.response.send_double(num1 + num2);
}

LuaCEmbedResponse *sub(LuaCEmbed *args){
    double num1 = lua_n.args.get_double(args,0);
    double num2 =  lua_n.args.get_double(args,1);
    if(lua_n.has_errors(args)){
        return lua_n.response.send_error("chama a função direito danilo\n");
    }
    return lua_n.response.send_double(num1 - num2);
}



int luaopen_minha_biblioteca(lua_State *L) {
    lua =  newLuaCEmbedNamespace();
    lua_n = newLuaCEmbedNamespace();
    LuaCEmbed * l = lua.newLuaLib(L, true);
    lua.add_callback(l, "soma", soma);
    lua.add_callback(l, "sub", sub);

    return  lua.perform(l);
}



//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c && lua teste.lua