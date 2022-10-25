## 1) Quais são as tarefas no caminho crítico para cada grafo de dependência? Para responder a pergunta, apresente um DAG do seu projeto.  
  
- Caminho crítico: 1 - 7 - 9 - 10 - 11 - 12 - 13 - 14 - 15 - 16 - 17 - 18 - 19 - 20 - 21 - 22 - 23 - 24 - 25 - 26 - 27 - 28 - 29 - 30 - 31 - 32 - 33 - 34 - 35

(A parte em verde é a do pedaço de código paralelizável)
  
![dag2](https://user-images.githubusercontent.com/16262291/197430646-ef7ce20b-2081-4274-93b3-3809539c800a.png)

- LEGENDA:   

![image](https://user-images.githubusercontent.com/74507357/197656067-e74758fc-956f-4bfc-93f7-34e48c00ee66.png)

 
  

## 2) Qual é o limite inferior do tempo de execução paralela para cada decomposição?
- R: No nosso caso em que estamos usando 2 threads no mínimo para a execução do código, teremos 2 tarefas concorrentes o que dá um limite inferior igual a 2.
  
  
## 3) Quantos processadores são necessários para se conseguir o tempo mínimo de execução?  
- R: 2 processadores é o mínimo pois temos no mínimo 2 threads.


## 4) Qual é o grau máximo de concorrência?
- R: O grau máximo depende da granularidade de tarefas executando em cada thread. No nosso projeto, ainda não subdividimos as threads em tarefas menores, portanto nosso grau máximo de concorrência é igual a 2 também (porém podemos aumentar futuramente).


## 5) Qual é o paralelismo médio?
- R: ( 2 + 2 ) / 2 = 2
