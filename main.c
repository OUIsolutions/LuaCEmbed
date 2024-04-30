#include "src/one.c"



static void *custom_alloc(void *ud, void *ptr, size_t osize, size_t nsize) {
    const int MAX_MEMORY_LIMIT = 1000; // 10 MB
    int *used = (int *)ud;

    if (ptr == NULL) {
        osize = 0;
    }

    if (nsize == 0) {
        free(ptr);
        *used -= osize; /* subtract old size from used memory */
        return NULL;
    } else {
        if (*used + (nsize - osize) > MAX_MEMORY_LIMIT) /* too much memory in use */
            return NULL;
        ptr = realloc(ptr, nsize);
        if (ptr) /* reallocation successful? */
            *used += (nsize - osize);
        return ptr;
    }
}


int main() {
    lua_State *L = luaL_newstate();

    // Set memory limit
    int used_memory = 0;
    lua_setallocf(L, custom_alloc,&used_memory);

    // Load Lua script
    int result = luaL_dostring(L, "r = 'assssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssa'");

    if (result != LUA_OK) {
        fprintf(stderr, "Lua error: %s\n", lua_tostring(L, -1));
        lua_pop(L, 1);  // Pop error message from the stack
    }

    lua_close(L);

    return 0;
}