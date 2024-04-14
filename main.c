
#include "src/one.c"
LuaCEmbedNamespace  lua;

LuaCEmbedResponse * print_lua_value(LuaCEmbed *l){
    if(lua.args.get_type(l,0) ==lua.types.NUMBER){
        printf("%lf\n", lua.args.get_double(l,0));
    }

    if(lua.args.get_type(l,0) == lua.types.STRING){
        printf("%s\n", lua.args.get_str(l,0));
    }

    return NULL;

}
LuaCEmbedResponse * soma(LuaCEmbed *l){

    int arg1 = (int)lua.args.get_long(l,0);
    int arg2 = (int)lua.args.get_long(l,1);
    return lua.response.send_long(arg1 + arg2);
}
LuaCEmbedResponse  *create_ob(LuaCEmbed *l){
    return lua.response.send_evaluation_function("function () return {a=30} end ");

}





int main(){
//    signal(SIGALRM, alarmante);
    //alarm(3);

    lua =  newLuaCEmbedNamespace();

    LuaCEmbed * l = lua.newLuaCEmbed();

    lua.add_callback(l, "puts", print_lua_value);
    lua.add_callback(l, "soma", soma);
    lua.add_callback(l, "create_obj", create_ob);
    //LuaCEmbed_set_timeout(lua,4);
    lua.evaluete_file(l,"teste.lua");

  // char *global = LuaCEmbed_get_global_evaluation_string(lua,"v['a']");

   if(lua.has_errors(l)){
        printf("error: %s\n", lua.get_error_message(l));

    }

    else{
        //printf("global %s\n",global);
        printf("no errors\n");
    }

    lua.free(l);

}