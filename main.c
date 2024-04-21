
#include "src/one.c"
LuaCEmbedNamespace  lua_n;




LuaCEmbedResponse  *increment(LuaCEmbedTable *self, LuaCEmbed *args){


    printf("nome %s\n",self->global_buffer);

    long v = lua_n.tables.get_long_prop(self,"v");

    long value_to_increment =  lua_n.args.get_long(args,0);

    printf("value to increment %ld",value_to_increment);
    return NULL;
}


int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate_string(l,"test ={a=30,x=40,b=90,d=30};");


    LuaCEmbedTable *t1  = lua_n.globals.get_table(l,"test");

    LuaCEmbedTable  *t2 = lua_n.tables.get_sub_table(t1,"teste2");
    LuaCEmbedTable  *t3 = lua_n.tables.get_sub_table(t1,"teste2");

    lua_n.tables.set_string_prop(t2,"a","va se fuder funcinou porra");

    printf("%s",lua_n.get_string_evaluation(l,"test.teste2.a"));

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    
    lua_n.free(l);

    return 0;
}
//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c 