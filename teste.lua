r = require("my_lib")

imagem = io.open("teste.png","rb"):read("a")
r.salva_arquivo("saida2.png",imagem)