
#if defined(__unix__) || defined(__APPLE__)
    #include <unistd.h>
#endif 

#if !defined(lua_h) && !defined(LUA_CEMBED_MOCK_LUA)
    #define LUA_SINGLE_UNITY_GUESS_OS
    #define LUA_SINGLE_UNITY_EMBED_MODE
    #if !defined(LUA_CEMBED_NOT_IMPLEMENT_MATH)
        #define LUA_SINGLE_UNITY_IMPLEMENT_MATH
    #endif

    #include "../../dependencies/lua_single_unity.h"
    #define LUA_CEMBED_LUA_DECLARATED
#endif 


#if !defined(UniversalGarbage_fdeclare) && !defined(LUA_CEMBED_MOCK_UNIVERSAL_GARBAGE)
    #include "../../dependencies/UniversalGarbage.h"
    #define LUA_CEMBED_UNIVERSAL_GARBAGE_DECLARATED
#endif

