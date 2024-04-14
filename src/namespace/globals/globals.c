

LuaCEmbedGlobalModule newLuaCEmbedGlobalModule(){
    LuaCEmbedGlobalModule self = {0};
    self.ensure_type = LuaCEmbed_ensure_global_type;

    self.get_double = LuaCEmbed_get_global_double;
    self.get_string = LuaCEmbed_get_global_string;
    self.get_long = LuaCEmbed_get_global_long;
    self.get_bool = LuaCEmbed_get_global_bool;

    self.get_evaluation_double = LuaCEmbed_get_global_evaluation_double;
    self.get_evaluation_string = LuaCEmbed_get_global_evaluation_string;
    self.get_evaluation_long = LuaCEmbed_get_global_evaluation_long;
    self.get_evaluation_bool = LuaCEmbed_get_global_evaluation_bool;

    self.set_string = LuaCEmbed_set_global_string;
    self.set_bool =LuaCEmbed_set_global_bool;
    self.set_double = LuaCEmbed_set_global_double;
    self.set_long = LuaCEmbed_set_global_long;
    return self;
}