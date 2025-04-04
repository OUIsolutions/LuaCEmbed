
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.consts.h"
//silver_chain_scope_end



LuaCEmbed * newLuaCEmbedEvaluation();



void LuaCEmbed_load_lib_from_c(LuaCEmbed *self,int (*callback)(lua_State *l),const char *name);

void LuaCEmbed_load_native_libs(LuaCEmbed *self);

void LuaCembed_set_delete_function(LuaCEmbed *self,void (*delelte_function)(struct  LuaCEmbed *self));


void privateLuaCEmbd_get_field_protected(LuaCEmbed *self,const char *name);


void * privateLuaCEmbed_get_current_table_array(LuaCEmbed *self);


void LuaCEmbed_set_timeout(int seconds);



void  privata_LuaCEmbed_increment_stack_(LuaCEmbed *self);


void  privata_LuaCEmbed_decrement_stack(LuaCEmbed *self);

void LuaCEmbed_free(LuaCEmbed *self);
