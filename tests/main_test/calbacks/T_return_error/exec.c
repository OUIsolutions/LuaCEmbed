
#include "../../../LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    return lua_n.response.send_error("aaaaaa");
}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);


   lua_n.evaluate_string(l,"test()");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    lua_n.free(l);

    return 0;
}