
#include "LuaCEmbedOne.c"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * print_func(LuaCEmbed *args){
    long size = lua_n.args.size(args);
   for(int index =0;index < size;index++ ){
       int arg_type = lua_n.args.get_type(args,index);

       if(arg_type  == lua_n.types.NUMBER){
           printf("%lf\n",lua_n.args.get_double(args,index));
       }

       else if(arg_type  == lua_n.types.STRING){
           printf("%s\n",lua_n.args.get_str(args,index));
       }

       else if(arg_type  == lua_n.types.BOOL){
           bool result = lua_n.args.get_bool(args,index);
          const  char *converted_bool = result? "true":"false";
           printf("%s\n", converted_bool);
       }
       else{
           const char *converted_to_str = lua_n.convert_arg_code(arg_type);
           printf("%s\n",converted_to_str);
       }

   }


    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"print",print_func);


    lua_n.evaluate(l,"print(10,30,'aa',true,{a=30})");


    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}