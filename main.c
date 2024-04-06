
#include "src/one.c"




int nada(lua_State *L){


    char *valor = (char*)lua_touserdata(L,lua_upvalueindex(1));
    printf("chamou %s\n",valor);

    

    // Itera sobre os elementos da tabela
    lua_pushnil(L); // Coloca a chave nula na pilha
    while (lua_next(L, 1) != 0) { // Enquanto houver elementos na tabela
        // Obtém a chave e o valor atual da tabela
        if (lua_isstring(L, -2)) {
            const char *chave = lua_tostring(L, -2);
            if (lua_isstring(L, -1)) {
                const char *valor = lua_tostring(L, -1);
                printf("%s: %s\n", chave, valor);
            } else {
                printf("%s: valor não é uma string\n", chave);
            }
        } else {
            printf("chave não é uma string\n");
        }
        lua_pop(L, 1); // Remove o valor, mantendo a chave na pilha para a próxima iteração
    }

    return 0;

    
}


int main(){
    lua_State *L = luaL_newstate(); // Inicializa o estado Lua

    const char *teste = "aaaaaaaa";
    lua_pushlightuserdata(L,(void*)teste);
    lua_pushcclosure(L,nada,1);
    lua_setglobal(L, "nada");

   

    luaL_dofile(L,"teste.lua");



    lua_close(L); // Fecha o estado Lua
    return 0;
}