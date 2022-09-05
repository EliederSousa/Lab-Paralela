Compilamos o arquivo no www.onlinegdb.com, usando como argumento o valor (inteiro) 5.

O programa cria por meio do fork() e shmget() um processo filho. O valor (5) é transferido para a memória compartilhada, e modificado no processo filho de forma a fazer o cálculo (4x + 1) [no caso, seria 4 * 5 + 1 = 20]; e após o retorno do processo filho, é somado o valor 20 a esse mesmo valor (21 + 20 = 41). 

### Saída:

Servidor iniciado.  
Servidor conectado à memória compartilhada.  
Valor 5 foi colocado na memória compartilhada.  
Criando um processo filho por fork().  
---- Processo filho iniciado  
---- Valor armazenado: 5  
---- Valor parcial após o processo filho fazer os cálculos: 21  
---- Finalizando processo filho  
Servidor detectou o término do processo filho.  
Valor final na memória: 41  
Servidor finalizado.  
