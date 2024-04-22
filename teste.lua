x = require('minha_biblioteca')
function teste()
    i  = 0
    while i < 100000 do 
        i = i+1
        v = x.create_obj()
        v.increment(3)
        v.increment(6)
    
    
    end 

end 

teste()
teste()