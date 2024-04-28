#include "../../../LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;

LuaCEmbedResponse  * show_table(LuaCEmbed *args){

    LuaCEmbedTable * t1 = lua_n.args.get_table(args,0);
    if(lua_n.has_errors(args)){
        char *menssage = lua_n.get_error_message(args);
        return  lua_n.response.send_error(menssage);
    }
    long size = lua_n.tables.get_size(t1);
    for(int i = 0; i <size;i++){

    }
    return NULL;
}>
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"show_table", show_table);
    lua_n.evaluate_string(l,"show_table({name='mateus',age=27,'test'})");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}