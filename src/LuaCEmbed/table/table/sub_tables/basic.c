

LuaCEmbedTable  *privateLuaCEmbedTable_append_or_create_by_name(LuaCEmbedTable *self, const char *full_sub_name, const char *name){
    if(!self){
        return NULL;
    }
    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_prop_name(
            (privateLuaCEmbedTableArray *) self->sub_tables,
            name
    );
    if(possible){
        return possible;
    }

    LuaCEmbedTable  *creaeted = newLuaCembedTable(self->main_object,false, full_sub_name);
    creaeted->prop_name = strdup(name);

    privateLuaCEmbedTableArray_append(
            (privateLuaCEmbedTableArray*)self->sub_tables,
            creaeted
    );
    return creaeted;
}
