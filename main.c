
#include "src/one.c"
LuaCEmbedNamespace  lua;


LuaCEmbedResponse * increment(LuaCEmbedTable *self,LuaCEmbed *args){

    long value = lua.tables.get_long_prop(self,"num");
    long value_to_increment = lua.args.get_long(args,0);
    lua.tables.set_long_prop(self,"num",value_to_increment+value);

}


LuaCEmbedResponse * create_obj(LuaCEmbed *args){
    LuaCEmbedTable *t = lua.tables.new_anonymous_table(args);
    lua.tables.set_long_prop(t,"num",0);
    lua.tables.set_method(t,"increment",increment);
    return lua.response.send_table(t);
}

int luaopen_minha_biblioteca(lua_State *L) {
    lua =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua.newLuaLib(L, false);
    lua.add_callback(l, "create_obj", create_obj);


    lua.perform(l);
    return 1;

}


int main(int argc, char *argv[]){

    lua =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua.newLuaEvaluation();

    lua.evaluete_file(l, "teste.lua");


    if(lua.has_errors(l)){
        printf("error: %s\n", lua.get_error_message(l));
    }

    
    lua.free(l);

    return 0;

}

//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c 