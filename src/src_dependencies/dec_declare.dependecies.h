

#if !defined(lua_h) && !defined(LUA_CEMBED_MOCK_LUA)
    #include "../../dependencies/lua_single_unity.h"
#endif 


#if !defined(UniversalGarbage_fdeclare) && !defined(LUA_CEMBED_MOCK_UNIVERSAL_GARBAGE)
    #include "../../dependencies/UniversalGarbage.h"
    #define LUA_CEMBED_UNIVERSAL_GARBAGE_DECLARATED
#endif

