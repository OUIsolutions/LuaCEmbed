
#include "../../../LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    LuaCEmbedTable *created = lua_n.tables.new_anonymous_table(args);
    lua_n.tables.set_string_prop(created,"a","test message");
    return lua_n.response.send_table(created);
}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);


    lua_n.evaluate(l,"created_table = test()");
    LuaCEmbedTable *created = lua_n.globals.get_table(l,"created_table");
    char *a = lua_n.tables.get_string_prop(created,"a");
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

   printf("value of created.a = %s\n",a);
    
    lua_n.free(l);

    return 0;
}