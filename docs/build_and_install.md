

## Install

To install the lib just copy the [Amalgamation](https://github.com/OUIsolutions/LuaCEmbed/releases/download/0.8.3/LuaCEmbedOne.c) into your project and include it in your code:
```c
#include "LuaCEmbedOne.c"
```


If  you are on Linux, you can download the lib with:
```bash
curl -L https://github.com/OUIsolutions/LuaCEmbed/releases/download/0.8.3/LuaCEmbedOne.c -o LuaCEmbedOne.c 
```

## Compile on Linux

To compile the lib in **Linux** you can use the following command:
```bash
gcc main.c -o your_output.out
```

## Compile on Windows

To compile the lib in **Windows** you can use the following commands

With Microsoft Visual C:
```cmd
cl.exe examples\example_simple.c /Fe:bin\example_simple.exe
```

With mingw64:
```bash
i686-w64-mingw32-gcc examples\example_simple.c -o bin\example_simple.exe -lws2_32
```

## Build from scratch

For buiding from scratch you need to have [darwin](https://github.com/OUIsolutions/Darwin/) installed on your machine. To install darwin:
```bash
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.2.0/darwin.out -o darwin.out && chmod +x darwin.out &&  sudo  mv darwin.out /usr/bin/darwin
```

Then you can build the project with in the root dir of the project:
```bash
darwin run_blueprint build/  --mode folder
```

It will generate all the **releases** in the **/release** dir.



### Mocking dependencies or dependencies implementations

The following defines toggle dependencies or just the definitions.
It is useful for  working with dynamic compilation or mocking dependencies.
check [dep_declare.dependecies.h](/src/src_dependencies/dep_declare.dependecies.h) and 
[dep_define.dependencies.c](/src/src_dependencies/dep_define.dependencies.c) for more information.
```c

//unallow lua 
#define LUA_CEMBED_MOCK_LUA

//unallow Universal Garbage
#define LUA_CEMBED_MOCK_UNIVERSAL_GARBAGE

//unallow lua definition
#define LUA_CEMBED_MOCK_LUA_DEFINE

//unallow universal garbage definition
#define LUA_CEMBED_MOCK_UNIVERSAL_GARBAGE_DEFINE

//unallow custom math.h  (-lm on compilation ill be required)
#define LUA_CEMBED_NOT_IMPLEMENT_MATH


#include "LuaCEmbedOne.c"


```