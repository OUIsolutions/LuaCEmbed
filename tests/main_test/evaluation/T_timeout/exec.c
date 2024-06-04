#include "../../../LuaCEmbed.h"


LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    return lua_n.response.send_str(" executed after timeout error\n");
}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_func);
    int seconds = 2;
    lua_n.set_timeout(seconds);

    lua_n.evaluate(l,"while true do end ;");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.clear_errors(l);
    char *teste =lua_n.get_string_evaluation(l,"test()");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    else{
        printf("%s",teste);
    }
    lua_n.free(l);

    return 0;
}