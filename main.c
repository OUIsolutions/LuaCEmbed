
#include "src/one.c"
LuaCEmbedNamespace  lua;


LuaCEmbedResponse * increment(LuaCEmbedTable *self,LuaCEmbed *args){


    long value = lua.tables.get_long_prop(self,"num");
    lua.tables.set_long_prop(self,"num",0+value);

    long value_to_increment = lua.args.get_long(args,0);
    if(lua.has_errors(args)){
        return  lua.response.send_error(lua.get_error_message(args));
    }

    lua.tables.set_long_prop(self,"num",value_to_increment+value);
    return NULL;
}

LuaCEmbedResponse * delete44(LuaCEmbedTable *self,LuaCEmbed *args){

    printf("chamou o delete\n");
    return NULL;
}


LuaCEmbedResponse * create_obj(LuaCEmbed *args){
    long  start = 0;
    if(lua.args.size(args) > 0){
        start = lua.args.get_long(args,0);
    }

    LuaCEmbedTable *t = lua.tables.new_anonymous_table(args);
    LuaCEmbedTable *valores = lua.tables.new_sub_table(t,"valores");
    lua.tables.append_long(valores,10);

    LuaCEmbedTable  *valores0 = lua.tables.new_anonymous_table(args);
    lua.tables.set_string_prop(valores0,"a","vai se fuder");
    lua.tables.append_table(valores,valores0);

    lua.tables.append_evaluation(valores,"50 + 50");

    lua.tables.set_evaluation_prop(t, "a", "10 +30");

    lua.tables.set_long_prop(t,"num",start);
    lua.tables.set_method(t,"increment",increment);
    lua.tables.set_method(t,"__gc",delete44);
    return lua.response.send_table(t);
}



int luaopen_minha_biblioteca(lua_State *L) {
    lua =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua.newLuaLib(L, true);
    lua.add_callback(l, "create_obj", create_obj);

    return  lua.perform(l);
}
LuaCEmbedResponse * lua_print_func(LuaCEmbed *args){
    int size = lua.args.size(args);
    for(int i = 0; i < size; i++){
        int type = lua.args.get_type(args,i);
        if(type == lua.types.NUMBER){
            printf("%lf",lua.args.get_double(args,i));;
        }
        if(type == lua.types.STRING){
            printf("%s",lua.args.get_str(args,i));
        }
    }
    printf("\n");
    return NULL;
}


int main(int argc, char *argv[]){

    lua =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua.newLuaEvaluation();
    lua.add_callback(l, "create_obj", create_obj);
    lua.add_callback(l, "print", lua_print_func);

    lua.evaluete_file(l,"teste.lua");

    if(lua.has_errors(l)){
        printf("error: %s\n", lua.get_error_message(l));
    }

    lua.free(l);

    return 0;

}

//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c 