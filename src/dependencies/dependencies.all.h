#include "UniversalGarbage.h"

#ifdef LUACEMBED_LIB_MODE

#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"

#else
#include "lua/onelua.c"
#endif
