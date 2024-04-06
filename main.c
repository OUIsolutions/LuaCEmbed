
#include "src/one.c"

void iterate(lua_State *L,int index){
    // Itera sobre os elementos da tabela
    lua_pushnil(L); // Coloca a chave nula na pilha
    while (lua_next(L, index) != 0) { // Enquanto houver elementos na tabela
        // Obtém a chave e o valor atual da tabela
        if (lua_isstring(L, -2)) {
            const char *chave = lua_tostring(L, -2);
            printf("%s:\n{",chave);

            if (lua_isstring(L, -1)) {
                const char *valor = lua_tostring(L, -1);
                printf("%s\n", valor);
            } 

            else if (lua_istable(L,-1)) {
                int index =lua_gettop(L);
                
                printf("index %d\n",index); 
                iterate(L, index);
            }
            printf("\n}");

        } else {
            printf("chave não é uma string\n");
        }
        lua_pop(L, 1); // Remove o valor, mantendo a chave na pilha para a próxima iteração
    }

}


int nada(lua_State *L){


    char *valor = (char*)lua_touserdata(L,lua_upvalueindex(1));
    printf("chamou %s\n",valor);

    iterate(L,2);
    

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