

TESTE = {
    __index = function (a,b)
        print("chamo1u",a,b)
    end,

    __gc = function (v)
        print("chamo2u")
    end

}
xx = {}

setmetatable(xx,TESTE)
local y = xx 
y.a = 30 

print(xx.a)

