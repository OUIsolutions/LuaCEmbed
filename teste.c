


#include "lib.c"
#include "src/one.c"
LuaCEmbedNamespace  lua_n1;

int main(){

    lua_n1 = newLuaCEmbedNamespace();
    LuaCEmbed  * main_obj = lua_n1.newLuaEvaluation();


    lua_n1.load_lib_from_c(main_obj,luaopen_my_lib,"calc");
    if(lua_n1.has_errors(main_obj)){
        printf("erro de carrgamento = '%s'\n",lua_n1.get_error_message(main_obj));
        lua_n1.free(main_obj);
        return 0;
    }

    lua_n1.evaluate(main_obj,"x = calc.add(0,20)");
    if(lua_n1.has_errors(main_obj)){
        printf("erro interno = '%s'\n",lua_n1.get_error_message(main_obj));
        return 0;
    }
    printf("%lld\n",lua_n1.globals.get_long(main_obj,"x"));
    lua_n1.free(main_obj);
    return 0;
}
