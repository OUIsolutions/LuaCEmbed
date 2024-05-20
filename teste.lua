
local teste  = io.open("a.out", "rb"):read("a")
print(type(teste))
io.open("b.out","w"):write(teste)