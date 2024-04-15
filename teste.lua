


local r = require("lib")

print(pcall(r.soma,10,20))
print(pcall(r.soma,10,"20"))
print(pcall(r.soma,10,40))
