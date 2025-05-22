#define LUA_CEMBED_INDEX_DIF 0
#include "LuaCEmbedOne.c"

LuaCEmbedResponse  * test_func(LuaCEmbed *args){
    long size = LuaCEmbed_get_total_args(args);
    if(size == 0){
        printf("no argument providided\n");
        return NULL;
    }
    int index = 1;
    int arg_type = LuaCEmbed_get_arg_type(args,index);

    if(arg_type  == LUA_CEMBED_NUMBER){
        printf("number: %lf\n",LuaCEmbed_get_double_arg(args,index));
    }

    else if(arg_type  == LUA_CEMBED_STRING){
        printf("str: %s\n",LuaCEmbed_get_str_arg(args,index));
    }

    else if(arg_type  == LUA_CEMBED_BOOL){
        printf("bool: %d\n", LuaCEmbed_get_bool_arg(args,index));
    }
    else{
        const char *converted_to_str = LuaCembed_convert_arg_code(arg_type);
        printf("type: %s\n",converted_to_str);
    }

    return NULL;
}

int main(int argc, char *argv[]){

    LuaCEmbed * l = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(l,"test",test_func);

    LuaCEmbed_evaluate(l,"test()");
    LuaCEmbed_evaluate(l,"test(10)");
    LuaCEmbed_evaluate(l,"test('hello')");
    LuaCEmbed_evaluate(l,"test(true)");
    LuaCEmbed_evaluate(l,"test({a=30})");


    if(LuaCEmbed_has_errors(l)){
        printf("error: %s\n",LuaCEmbed_get_error_message(l));
    }
    LuaCEmbed_free(l);

    return 0;
}