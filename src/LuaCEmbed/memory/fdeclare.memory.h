//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.consts.h"
//silver_chain_scope_end





void LuaCEmbed_set_memory_limit(LuaCEmbed *self, double limit);


static void *private_LuaCembed_custom_allocator(void *ud, void *ptr, size_t osize, size_t nsize) ;

