

LuaCembedTableModule newLuaCembedTableModule(){
    LuaCembedTableModule self ={0};
    self.set_method = LuaCembedTable_set_method;
    self.set_bool_prop = LuaCembedTable_set_bool_prop;
    self.set_double_prop = LuaCembedTable_set_double_prop;
    self.set_long_prop = LuaCembedTable_set_long_prop;
    self.set_string_prop = LuaCembedTable_set_string_prop;
    return self;
}
