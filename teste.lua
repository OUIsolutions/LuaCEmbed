

local meta  = {}
local normal = {}
setmetatable(normal,meta)


meta.__gc = function (t1,t2)
    print("chamou")
end 
