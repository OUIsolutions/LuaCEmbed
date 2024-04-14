
--local minha_biblioteca = require("minha_biblioteca")

function interna(x,y)
    print(x)
    print(y)
end

function test(...)
    interna(...)
end

test(1,2,3,{a=3})