
void  private_LuaCEmbedTable_add_space(LuaCEmbedTable *self, long formatted_index){

    lua_getglobal(self->main_object->state, self->global_name);
    int table_index = lua_gettop(self->main_object->state);
    int total = 1;
    bool last_pushed = false;
    lua_pushnil(self->main_object->state); // Empilhando o primeiro par chave-valor
    while (lua_next(self->main_object->state, table_index)) {

        if (total >= formatted_index) {
            if(last_pushed){
                last_pushed = false;
                lua_pop(self->main_object->state, 1); // Removendo o valor atual
                total++;
                continue;
            }

            lua_getglobal(self->main_object->state, self->global_name);
            lua_pushinteger(self->main_object->state, total + 1);
            lua_pushvalue(self->main_object->state, -3);
            lua_settable(self->main_object->state, -3);
            lua_pop(self->main_object->state, 1);
            last_pushed = true;
        }


        lua_pop(self->main_object->state, 1); // Removendo o valor atual
        total++;
    }
}
void LuaCEmbedTable_insert_string_at_index(LuaCEmbedTable *self, long index, const char *value) {
    // Movendo os elementos existentes para frente
    long formatted_index = index + LUA_CEMBED_INDEX_DIF;

    private_LuaCEmbedTable_add_space(self,formatted_index);
    // Inserindo o novo valor na posição especificada
    lua_getglobal(self->main_object->state, self->global_name);
    lua_pushnumber(self->main_object->state, (double)formatted_index);
    lua_pushstring(self->main_object->state, value);
    lua_settable(self->main_object->state, -3);

    // Limpando a pilha
    lua_settop(self->main_object->state, 0);
}