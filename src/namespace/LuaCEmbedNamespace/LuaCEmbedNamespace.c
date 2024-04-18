

LuaCEmbedNamespace newLuaCEmbedNamespace(){
    LuaCEmbedNamespace self = {0};
    self.newLuaLib = newLuaCEmbedLib;
    self.newLuaEvaluation = newLuaCEmbedEvaluation;
    self.set_delete_function = LuaCembed_set_delete_function;
    self.perform = LuaCembed_perform;
    self.args = newLuaCembedArgsModule();
    self.types = newLuaCEmbedTypeModule();
    self.globals = newLuaCEmbedGlobalModule();
    self.response = newLuaCEmbedResponseModule();
    self.get_error_message = LuaCEmbed_get_error_message;
    self.has_errors = LuaCEmbed_has_errors;
    self.raise_error = LuaCEmbed_raise_error;
    self.set_timeout = LuaCEmbed_set_timeout;
    self.evaluate_string = LuaCEmbed_evaluate_string_no_return;
    self.get_evaluate_string_returning_string = LuaCEmbed_get_evaluation_string;
    self.get_evaluation_type = LuaCEmbed_get_evaluation_type;
    self.get_evaluation_size = LuaCEmbed_get_evaluation_table_size;
    self.get_evaluation_long = LuaCEmbed_get_evaluation_long;
    self.get_evaluation_double  = LuaCEmbed_get_evaluation_double;
    self.get_evaluation_bool = LuaCEmbed_get_evaluation_bool;
    self.evaluete_file = LuaCEmbed_evaluete_file;
    self.add_callback = LuaCEmbed_add_callback;
    self.free = LuaCEmbed_free;
    return self;
}