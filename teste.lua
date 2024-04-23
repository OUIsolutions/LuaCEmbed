require("minha_biblioteca")
v = create_obj(100)
v1 = create_obj(200)

v.increment(50)
--print(v.num)

v1.increment(50)
print(v1.num)
print(v1.valores[2]['a'])
print(v1.a)
print(v1.valores[3])