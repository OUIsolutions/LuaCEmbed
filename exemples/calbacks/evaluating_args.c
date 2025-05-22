#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * add_func(LuaCEmbed *args){

    double num1 = LuaCEmbed_get_long_arg_clojure_evalation(args,0,"function(t) return t.num1  end ");
    double num2 = LuaCEmbed_get_long_arg_clojure_evalation(args,0,"function(t) return t.num2  end ");

    if(LuaCEmbed_has_errors(args)){
        char *error_message = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_message);
    }
    return LuaCEmbed_send_double(num1+num2);
    return NULL;
}

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l,"add",add_func);

    double result = LuaCEmbed_get_evaluation_double(l,"add({num1=10, num2=30})");

    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n",LuaCEmbed_get_error_message(l));
    }
    printf("result :%lf\n",result);

    LuaCEmbed_free(l);

    return 0;
}