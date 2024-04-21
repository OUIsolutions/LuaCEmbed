
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

    LuaCEmbedTable *t1 = lua_n.globals.new_table(l, "test");

    lua_n.tables.set_long_prop(t1,"v",0);
    lua_n.tables.set_method(t1,"increment",increment);

    lua_n.evaluate_string(l,"test.increment(20)");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    
    lua_n.free(l);

    return 0;
}
//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c 