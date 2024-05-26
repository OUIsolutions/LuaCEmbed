#include "../../../LuaCEmbed.h"
LuaCEmbedNamespace  lua_n;


LuaCEmbedResponse  * describe( LuaCEmbedTable  *self,LuaCEmbed *args){
    char *name = lua_n.tables.get_string_prop_by_field(self,"name");
    long age  = lua_n.tables.get_long_prop_by_field(self,"age");
    double height = lua_n.tables.get_double_prop_by_field(self,"height");
    bool married = lua_n.tables.get_bool_prop_by_field(self,"married");
    printf("person description:\n");
    printf("name: %s\n",name);
    printf("age: %ld\n",age);
    printf("height: %lf\n",height);
    printf("married %d\n",married);
    return NULL;

}
LuaCEmbedResponse  * create_table(LuaCEmbed *args){

    char *name = lua_n.args.get_str(args,0);
    long age  = lua_n.args.get_long(args,1);
    double height = lua_n.args.get_double(args,2);
    bool maried = lua_n.args.get_bool(args,3);

    if(lua_n.has_errors(args)){
      const char *error_message = lua_n.get_error_message(args);
      return lua_n.response.send_error(error_message);
    }

    LuaCEmbedTable *custom_table =  lua_n.tables.new_anonymous_table(args);
    lua_n.tables.set_string_prop(custom_table,"name",name);
    lua_n.tables.set_long_prop(custom_table,"age",age);
    lua_n.tables.set_double_prop(custom_table,"height",height);
    lua_n.tables.set_bool_prop(custom_table,"married",maried);
    lua_n.tables.set_method(custom_table,"describe",describe);
    return lua_n.response.send_table(custom_table);

}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();
    lua_n.add_callback(l,"create_person", create_table);
    lua_n.evaluate(l,"r = create_person('test',30,1.4,true)");
    lua_n.evaluate(l,"r.describe()");
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }

    lua_n.free(l);

    return 0;
}