
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.consts.h"
//silver_chain_scope_end


char * LuaCEmbed_get_error_message(LuaCEmbed *self);

bool LuaCEmbed_has_errors(LuaCEmbed *self);

void LuaCEmbed_clear_errors(LuaCEmbed *self);


void privateLuaCEmbed_raise_error_not_jumping(LuaCEmbed *self, const char *error, ...);

void LuaCEmbed_dangerous_raise_error_jumping(LuaCEmbed *self,const char *error_msg,...);

void LuaCEmbed_dangerous_raise_self_error_jumping(LuaCEmbed *self);
