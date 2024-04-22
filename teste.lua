x = require('minha_biblioteca')

v = x.create_obj()

v.increment(3)
pcall(v.increment)

print(v.num)