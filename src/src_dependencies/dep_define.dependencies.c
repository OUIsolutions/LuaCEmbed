//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end

#if !defined(LUA_CEMBED_MOCK_LUA_DEFINE) && defined(LUA_CEMBED_LUA_DECLARATED)
    #define l_unlikely luai_unlikely
    #define l_likely luai_likely
    #define LUA_SINGLE_UNITY_EMBED_MODE
    #define LUA_SINGLE_UNITY_GUESS_OS
    #if !defined(LUA_CEMBED_NOT_IMPLEMENT_MATH)
        #define LUA_SINGLE_UNITY_IMPLEMENT_MATH
    #endif

#include "../../dependencies/lua_single_unity_classic_onelua.c"
#endif


#if !defined(LUA_CEMBED_MOCK_UNIVERSAL_GARBAGE_DEFINE) && defined(LUA_CEMBED_UNIVERSAL_GARBAGE_DECLARATED)
#include "../../dependencies/UniversalGarbage.c"
#endif