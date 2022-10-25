## 1) Quais são as tarefas no caminho crítico para cada grafo de dependência? Para responder a pergunta, apresente um DAG do seu projeto.  
  
- Caminho crítico: 1 - 8 - 9 - 10 - 11 - 12 - 13 - 15 - 16 - 18 - 19 - 20 - 21 - 24 - 25 - 26 - 27 - 28 - 29 - 30 - 31 - 32 - 33

(As partes coloridas são as threads executando em paralelo)
  
![Diagrama sem nome drawio(2)](https://user-images.githubusercontent.com/16262291/197656822-52c27c87-c2a1-481b-b0f9-8456d65cc0f7.png)

- LEGENDA:   

![image](https://user-images.githubusercontent.com/74507357/197656067-e74758fc-956f-4bfc-93f7-34e48c00ee66.png)

 
  
## 2) Qual é o limite inferior do tempo de execução paralela para cada decomposição?
- R: 
  
  
## 3) Quantos processadores são necessários para se conseguir o tempo mínimo de execução?  
- R: São necessários 5 processadores para realizar todas as tarefas. 


## 4) Qual é o grau máximo de concorrência?
- R: 


## 5) Qual é o paralelismo médio?
- R: 33 tarefas / 22 unidades de tempo = 1.5
