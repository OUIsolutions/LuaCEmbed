
#include "src/one.c"
LuaCEmbedNamespace  lua;


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
void teste(const char *format,...){
    va_list  args;
    va_start(args,format);
    char *r = private_LuaCembed_format(format,args);
    va_end(args);
}
int main(){

}


//gcc -Wall -shared -fpic -o minha_biblioteca.so  main.c && lua teste.lua