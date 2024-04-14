

LuaCEmbedNamespace newLuaCEmbedNamespace(){
    LuaCEmbedNamespace self = {0};
    self.newLuaCEmbed = newLuaCEmbed;
    self.args = newLuaCembedArgsModule();
    self.types = newLuaCEmbedTypeModule();
    self.response = newLuaCEmbedResponseModule();
    self.get_error_message = LuaCEmbed_get_error_message;
    self.has_errors = LuaCEmbed_has_errors;
    self.raise_error = LuaCEmbed_raise_error;
    self.set_timeout = LuaCEmbed_set_timeout;
    self.evaluate_string = LuaCEmbed_evaluate_string;
    self.evaluete_file = LuaCEmbed_evaluete_file;
    self.add_callback = LuaCEmbed_add_callback;
    self.free = LuaCEmbed_free;
    return self;
}