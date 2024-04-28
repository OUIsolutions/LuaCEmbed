
#include "LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * add_func(LuaCEmbed *args){


    double num1 = lua_n.args.get_long_arg_clojure_evalation(args,0,"function(t) return t.num1  end ");
    double num2 = lua_n.args.get_long_arg_clojure_evalation(args,0,"function(t) return t.num2  end ");

    if(lua_n.has_errors(args)){
        char *error_message = lua_n.get_error_message(args);
        return lua_n.response.send_error(error_message);
    }
    return lua_n.response.send_double(num1+num2);
    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"add",add_func);


   double result = lua_n.get_evaluation_double(l,"add({num1=10, num2=30})");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
   printf("resullt :%lf\n",result);

    lua_n.free(l);

    return 0;
}