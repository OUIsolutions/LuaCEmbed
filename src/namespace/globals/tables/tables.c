

LuaCEmbedGlobalTableModule newLuaCEmbedGlobalTableModule(){
    LuaCEmbedGlobalTableModule self = {0};
    self.get_bool = LuaCEmbed_get_global_table_bool;
    self.get_string = LuaCEmbed_get_global_table_string;
    self.get_double = LuaCEmbed_get_global_table_double;
    self.get_type  = LuaCEmbed_get_global_table_type;
    self.get_type = LuaCEmbed_get_global_table_type;
    self.get_long = LuaCEmbed_get_global_table_long;
    return self;
}