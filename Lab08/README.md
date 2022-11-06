#### Para ambos os programas (cálculo da área por soma de trapézios / multiplicação de matrizes) utilizamos 2 versões de código: uma utilizando os métodos _critical_ e _reduction_ da biblioteca OpenMP. Utilizamos também duas máquinas em ambiente AWS para os testes: uma com 1 núcleo onde foi feito 4 testes de cada programa, e outra com 2 núcleos onde realizamos 4 testes.
Para calcular o speedup, fizemos uma média de tempo destes 4 testes, onde excluímos o primeiro por inconsistência nos resultados. Os gráficos com as médias de tempo para cada teste são mostrados abaixo.
---
## Trapézio
![image](https://user-images.githubusercontent.com/16262291/200195733-ca1b9b23-bd57-4588-aaec-754a15d9ffcb.png)

## Multiplicação de Matrizes
![image](https://user-images.githubusercontent.com/16262291/200195874-96fa4384-2736-4c91-8b06-ab5a57d8436a.png)
---

__OBS: Foi pedido pelo professor para realizarmos testes em máquinas de 1, 2, 4 e 8 núcleos. Porém a plataforma AWS Student não nos dá a autorização para criarmos máquinas com mais de 2 núcleos.__
