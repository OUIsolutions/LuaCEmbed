#include "LuaCEmbedOne.c"
LuaCEmbedNamespace  lua_n;

LuaCEmbedResponse  * show_table(LuaCEmbed *args){

    LuaCEmbedTable * t1 = lua_n.args.get_table(args,0);
    if(lua_n.has_errors(args)){
        char *menssage = lua_n.get_error_message(args);
        return  lua_n.response.send_error(menssage);
    }

    long size = lua_n.tables.get_size(t1);
    for(int i = 0; i < size; i++){

        LuaCEmbedTable *current = lua_n.tables.get_sub_table_by_index(t1,i);
        char *name  = lua_n.tables.get_string_prop(current,"name");
        long age = lua_n.tables.get_long_prop(current,"age");

        if(lua_n.has_errors(args)){
            char *menssage = lua_n.get_error_message(args);
            return  lua_n.response.send_error(menssage);
        }

        printf("name : %s\n",name);
        printf("age: %ld\n",age);

        printf("------------------------------------------\n");
    }
    
    return NULL;

}
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"show_table", show_table);
    lua_n.evaluate(l,"show_table({{name='mateus',age=27},{name='john',age=30}} )");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}