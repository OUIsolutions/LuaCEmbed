


static void *private_LuaCembed_custom_allocator(void *ud, void *ptr, size_t osize, size_t nsize) {
    int *used = (int *)ud;

    if (ptr == NULL) {
        osize = 0;
    }

    if (nsize == 0) {
        free(ptr);
        *used -= osize; /* subtract old size from used memory */
        return NULL;
    } else {
        if (*used + (nsize - osize) > LUA_CEMBED_MAX_MEMORY_LIMIT) /* too much memory in use */
            return NULL;
        ptr = realloc(ptr, nsize);
        if (ptr) /* reallocation successful? */
            *used += (nsize - osize);
        return ptr;
    }
}

