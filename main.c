
#include "src/one.c"




int nada(lua_State *l){
    

    

    printf("chamou\n");
    return 0;
    
}


int main(){
    lua_State *L = luaL_newstate(); // Inicializa o estado Lua

    lua_pushcfunction(L, nada);
    lua_setglobal(L, "nada");

    luaL_dofile(L,"teste.lua");



    lua_close(L); // Fecha o estado Lua
    return 0;
}