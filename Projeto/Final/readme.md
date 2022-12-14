Nossa versão final do projeto reside aqui. Os resultados por serem muito grandes são apresentados em arquivos de texto, onde o nome do arquivo representa a quantidade de dígitos que conseguimos em cada bateria de testes.
Não utilizamos bibliotecas __*bigint*__ prontas para o cálculo mas criamos uma do zero. Por conta do tempo, nossa implementação __não é__ otimizada em diversos aspectos, tais como: usar uma base diferente para cálculos (binária para otimizar divisões por exemplo), implementar o [algoritmo de Karatsuba](https://en.wikipedia.org/wiki/Karatsuba_algorithm) para multiplicações com mais de 32 bytes, [Fast Fourier Transform](https://en.wikipedia.org/wiki/Fast_Fourier_transform)). 

Nossa implementação foi baseada na seguinte equação:  
![image](https://user-images.githubusercontent.com/16262291/203670620-758de7cb-3a9a-4c3d-996c-c97a9c8a026f.png)

Fizemos o cálculo do fatorial utilizando 2 threads com omp critical para gravar os resultados, e armazenando os valores de cada digito em um grande vetor em uma classe BigInt. O somatório de frações tem uma propriedade peculiar em que, para cada novo denominador, ele será o MMC da soma até ele; ou seja, ao fazer N iterações, a última fração será 1/N! e o somatório terá como denominador N! também. 
Por isso, bastava apenas calcular quais eram os valores dos numeradores das frações e somá-los em sequência. Isto também foi feita de forma paralelizada porém de uma forma diferente: uma thread calcula as divisões resultando nos primeiros numeradores, e outra thread calcula as multiplicações entre N * N-1 * N-2 ... a fim de que elas se encontrem. O resultado então é guardado em uma variável BigInt e por fim é feita a divisão final entre o numerador e o denominador.


Para os testes, utilizamos uma máquina com Windows 11 com a IDE VSCode. O processador é mostrado abaixo:  

![image](https://user-images.githubusercontent.com/16262291/203770162-f93864c5-5fce-4366-b441-97847b3015b5.png)

A comparação dos dados foi feita pelo programa [HxD](https://mh-nexus.de/en/hxd/), e fizemos uma comparação entre nossos arquivos e a lista da NASA (disponível abaixo), utilizando o comando "Comparação de dados -> Comparar" (CTRL+K).


![image](https://user-images.githubusercontent.com/16262291/203666393-084c8295-2f30-400c-9888-e55ba8c683cb.png)  
![image](https://user-images.githubusercontent.com/16262291/203666323-848bad80-bc43-4729-b373-b76bda72b7f4.png)  



Comparação entre a lista da NASA com a lista de 711271 casas decimais corretas:  
![image](https://user-images.githubusercontent.com/16262291/203666586-4c120109-2a4c-4067-912d-8f57b030a7dc.png)

---  

## Resultados feitos em máquina local  
:notebook:[213235.txt](https://raw.githubusercontent.com/EliederSousa/Lab-Paralela/main/Projeto/Final/213237.txt), time: 379s = 6m:19s  
:notebook:[711271.txt](https://raw.githubusercontent.com/EliederSousa/Lab-Paralela/main/Projeto/Final/711273.txt), time: 3089s = 51m:29s  
:notebook:[1240915.txt](https://raw.githubusercontent.com/EliederSousa/Lab-Paralela/main/Projeto/Final/1240915.txt), time: 11604s = 3h:13m  
:notebook:[1512852.txt](https://raw.githubusercontent.com/EliederSousa/Lab-Paralela/main/Projeto/Final/1512852.txt), time: 19502 = 5h:25m

---  

### Site da NASA    
https://apod.nasa.gov/htmltest/gifcity/e.2mil  
__[Link para o arquivo de testes da NASA](https://raw.githubusercontent.com/EliederSousa/Lab-Paralela/main/Projeto/Final/nasa.txt)__
