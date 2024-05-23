#include "src/one.c"
LuaCEmbedNamespace  lua_n;

int acumulator = 0;
LuaCEmbedResponse * deleter(LuaCEmbedTable *self,LuaCEmbed *args){
    long global_value = lua_n.tables.get_long_prop(self,"global_value");
    printf("deletou %ld\n",global_value);
    return NULL;
}

LuaCEmbedResponse  * test_table(LuaCEmbed *args){

    for(int i = 0; i < 10; i++){
        char index[20] = {0};
        sprintf(index,"valor%d",acumulator);
        LuaCEmbedTable * teste = lua_n.globals.new_table(args,index);

        lua_n.tables.set_method(teste,"__gc", deleter);
        lua_n.tables.set_long_prop(teste,"global_value",acumulator);
        acumulator+=1;
    }

    return NULL;
}

LuaCEmbedResponse * printl(LuaCEmbed *args){
    LuaCEmbedTable  *valor3  = lua_n.args.get_table(args,0);
    printf("chamou o teste valor: %ld\n",(long )lua_n.tables.get_long_prop(valor3,"global_value"));
    return NULL;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"test",test_table);
    lua_n.add_callback(l,"print",printl);

    lua_n.evaluete_file(l,"teste.lua");

    lua_n.free(l);

    return 0;
}