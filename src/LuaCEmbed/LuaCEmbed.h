
typedef struct{
    lua_State *state;

}LuaCEmbed;


LuaCEmbed * newLuaCEmbed();

void LuaCEmbed_interpret_string(LuaCEmbed *self,const char *str);

void LuaCEmbed_interpret_file(LuaCEmbed *self,const char *file);


void LuaCEmbed_free(LuaCEmbed *self);


