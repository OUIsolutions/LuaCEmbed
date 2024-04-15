


local r = require("lib")

--local r1 = require("minha_biblioteca1")



local funcionou,valor  = pcall(r.soma,30,"aa")
print(valor)

print("depois")
local v = r.soma(10,20)

print(v)