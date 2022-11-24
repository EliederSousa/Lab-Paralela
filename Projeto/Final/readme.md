Nossa versão final do projeto reside aqui. Os resultados por serem muito grandes são apresentados em arquivos de texto, onde o nome do arquivo representa a quantidade de dígitos que conseguimos em cada bateria de testes.
Não utilizamos bibliotecas __*bigint*__ prontas para o cálculo mas criamos uma do zero. Por conta do tempo, nossa implementação __não é__ otimizada em diversos aspectos, tais como: usar uma base diferente para cálculos (binária para otimizar divisões por exemplo), implementar o [algoritmo de Karatsuba](https://en.wikipedia.org/wiki/Karatsuba_algorithm) para multiplicações com mais de 32 bytes, [Fast Fourier Transform](https://en.wikipedia.org/wiki/Fast_Fourier_transform)). 
Para os testes, utilizamos o programa [HxD](https://mh-nexus.de/en/hxd/), e fizemos uma comparação entre nossos arquivos e a lista da NASA (disponível abaixo), utilizando o comando "Comparar Arquivos" (CTRL+K).

![image](https://user-images.githubusercontent.com/16262291/203666200-ca778ea2-766e-4e30-8015-c802f2ee259b.png)
![image](https://user-images.githubusercontent.com/16262291/203666323-848bad80-bc43-4729-b373-b76bda72b7f4.png)



:notebook:[213235.txt](https://raw.githubusercontent.com/EliederSousa/Lab-Paralela/main/Projeto/Final/213237.txt)  
:notebook:[711271.txt](https://raw.githubusercontent.com/EliederSousa/Lab-Paralela/main/Projeto/Final/711273.txt)  


Comparação entre a lista da NASA com a lista de 711271 casas decimais corretas:  

![image](https://user-images.githubusercontent.com/16262291/203663238-30197d9b-3bdf-433a-9d4f-2a30b25382d4.png)



### Site da NASA:  
https://apod.nasa.gov/htmltest/gifcity/e.2mil  
__[Link para o arquivo de testes da NASA](https://raw.githubusercontent.com/EliederSousa/Lab-Paralela/main/Projeto/Final/nasa.txt)__
