data = {}
 total  = 0
function teste()
   local  i = 0
    while i < 20 do
        total = total +1
        valor = {corrente =  total}
        data["r"..total] = valor
        setmetatable(valor,{
            __gc= function (tabela)
                print("deletou r ",tabela.corrente)
            end
        })
        i = i +1
    end

end
function deleta_ref()
    local i = 0
    while i < 100 do
        x =  data[i]
        x = nil
     i = i + 1
    end
end

teste()
teste()
teste()
deleta_ref()
teste()

print("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")
teste()
teste()