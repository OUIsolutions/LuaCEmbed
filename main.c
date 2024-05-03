#include "src/one.c"


LuaCEmbedNamespace  lua_n;



LuaCEmbedResponse * index_callback(LuaCEmbedTable *self, LuaCEmbed *args){




    int value_type = lua_n.args.get_type(args,1);

    if(value_type == lua_n.types.NUMBER){
        printf("index-value: %lf\n",lua_n.args.get_double(args,1));
    }

    else if(value_type == lua_n.types.STRING){
        printf("index-value: %s\n",lua_n.args.get_str(args,1));
    }


    return NULL;
}

LuaCEmbedResponse * deletion_callback(LuaCEmbedTable *self, LuaCEmbed *args){

    printf("called the delete function\n");
    return NULL;
}

LuaCEmbedResponse  * create_table(LuaCEmbed *args){

    LuaCEmbedTable *custom_table =  lua_n.tables.new_anonymous_table(args);
    lua_n.tables.set_method(custom_table,"__gc",deletion_callback);
    lua_n.tables.set_method(custom_table,"__index",index_callback);
    return lua_n.response.send_table(custom_table);

}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"create_object", create_table);
    lua_n.evaluate(l,"r = create_object()");
    lua_n.evaluate(l,"v = r[10]");
    lua_n.evaluate(l,"v = r['sss']");

    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    lua_n.free(l);

    return 0;
}
