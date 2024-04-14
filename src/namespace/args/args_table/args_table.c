

LuaCEmbedArgsTableModule newLuaCEmbedArgsTableModule(){
    LuaCEmbedArgsTableModule self = {0};
    self.get_arg_bool = LuaCEmbed_get_table_arg_bool;
    self.get_arg_double = LuaCEmbed_get_table_arg_double;
    self.get_arg_long = LuaCEmbed_get_table_arg_long;
    self.get_arg_size =  LuaCEmbed_get_table_arg_size;
    self.get_arg_string  = LuaCEmbed_get_table_arg_string;
    self.get_arg_type  = LuaCEmbed_get_table_arg_type;

}