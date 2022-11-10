## Critical  
  
Fazer o calculo de direto na viarável do resultado, teriamos as threads executando sequencialmente mesmo estando dentro do bloco paralelo e da sessão crítica. Nisso, para não termos essa situação e conseguir fazer as threads executarem em paralelo e com o controle da região crítica, colocamos uma variável privada dentro do bloco paralelizado que vai receber cada resultado calculado e depois que as threads terminam os calculos, entra na sessão crítica para adicionar o resultado da variavel privada na variavel compartilada dop resultado total.
