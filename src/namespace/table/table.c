

LuaCembedTableModule newLuaCembedTableModule(){
    LuaCembedTableModule self ={0};
    self.set_method = LuaCEmbedTable_set_method;
    self.set_bool_prop = LuaCEmbedTable_set_bool_prop;
    self.set_double_prop = LuaCEmbedTable_set_double_prop;
    self.set_long_prop = LuaCEmbedTable_set_long_prop;
    self.set_string_prop = LuaCEmbedTable_set_string_prop;
    return self;
}
