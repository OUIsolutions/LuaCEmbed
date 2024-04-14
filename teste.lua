
local minhaTabela = {1,2,3}

local metatabela = {
    __index = function(tabela, index)
        for chave ,value in pairs(tabela) do
             print(chave)
        end
    end
}

setmetatable(minhaTabela, metatabela)

print(minhaTabela[0])