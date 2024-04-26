
#include "src/one.c"
LuaCEmbedNamespace  lua;

LuaCEmbedNamespace  lua_n;

LuaCEmbedResponse *test(LuaCEmbed *args){
    LuaCEmbedTable *t= lua.args.get_table(args,0);
    lua.tables.append_long(t,20);
    lua.tables.append_string(t,"aaa");
    lua.tables.set_long_by_index(t,1,50);
    return NULL;
}
int luaopen_minha_biblioteca(lua_State *L) {
    lua =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua.newLuaLib(L, true);
    lua.add_callback(l, "test", test);

    return  lua.perform(l);
}
char* teste(const char *format,...){
    va_list  args;
    va_start(args,format);
    char *r = private_LuaCembed_format_vaarg(format, args);
    va_end(args);
    return r;
}

int main(int argc, char *argv[]){

    lua_n =  newLuaCEmbedNamespace();
    LuaCEmbed * l = lua_n.newLuaEvaluation();

    lua_n.evaluate_string(l,"r = {a='internal text'}");
    LuaCEmbedTable *result  = lua_n.globals.get_table_auto_creating(l,"r");
    char *a = lua_n.tables.get_string_prop(result,"a");
    printf("value of r.a = %s\n",a);
    if(lua_n.has_errors(l)){
        printf("error: %s\n",lua_n.get_error_message(l));
    }
    lua_n.free(l);

    return 0;
}

//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c && lua teste.lua