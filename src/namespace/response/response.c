

LuaCEmbedResponseModule newLuaCEmbedResponseModule(){
    LuaCEmbedResponseModule self = {0};
    self.send_str = LuaCEmbed_send_str;
    self.send_bool = LuaCEmbed_send_bool;
    self.send_double = LuaCEmbed_send_double;
    self.send_evaluation_function =  LuaCEmbed_send_evaluation;
    self.send_long = LuaCEmbed_send_long;
    self.send_table = LuaCEmbed_send_table;
    return  self;
}
