#include "../../../LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;

LuaCEmbedResponse  * show_table(LuaCEmbed *args){

    LuaCEmbedTable * t1 = lua_n.args.get_table(args,0);
    if(lua_n.has_errors(args)){
        char *menssage = lua_n.get_error_message(args);
        return  lua_n.response.send_error(menssage);
    }
    long size = lua_n.tables.get_size(t1);
    for(int i = 0; i <size;i++){
         printf("index: %d\n",i);
        if(lua_n.tables.has_key(t1,i)){
             char *key = lua_n.tables.get_key_by_index(t1,i);
             printf("key: %s\n",key);
         }
         int type= lua_n.tables.get_type_by_index(t1,i);
        if(type == lua_n.types.NUMBER){
            double value = lua_n.tables.get_double_by_index(t1,i);
            printf("value: %lf\n",value);
        }
        if(type == lua_n.types.STRING){
            char * value = lua_n.tables.get_string_by_index(t1,i);
            printf("value: %s\n",value);
        }

        if(type == lua_n.types.BOOL){
            bool value = lua_n.tables.get_bool_by_index(t1,i);
            printf("value: %d\n",value);
        }
        printf("\n");
    }
    return NULL;
}>
int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"show_table", show_table);
    lua_n.evaluate_string(l,"show_table({name='mateus',age=27,'test'})");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}