

LuaCembedArgsModule newLuaCembedArgsModule(){
    LuaCembedArgsModule self = {0};
    self.get_bool = LuaCEmbed_get_bool_arg;
    self.get_long = LuaCEmbed_get_long_arg;
    self.get_double = LuaCEmbed_get_double_arg;
    self.get_str = LuaCEmbed_get_str_arg;
    self.get_type = LuaCEmbed_get_arg_type;
    self.table = newLuaCEmbedArgsTableModule();
    return self;
}