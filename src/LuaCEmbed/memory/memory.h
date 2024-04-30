
#define LUA_CEMBED_ONE_MB (1024 * 1024)



#ifndef  LUA_CEMBED_MAX_MEMORY_LIMIT
#define LUA_CEMBED_MAX_MEMORY_LIMIT (100 * LUA_CEMBED_ONE_MB) // 10 MB
#endif

static void *private_LuaCembed_custom_allocator(void *ud, void *ptr, size_t osize, size_t nsize) ;
