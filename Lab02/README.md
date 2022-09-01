- Compilamos usando {gcc main.c -o main} no windows e o tempo gasto para rodar foi em media 16 Milissegundos  
testamos com o fatorial de 20 e resultou em: 
PS C:\Users\MariEli\Desktop> .\main.exe 20  
2432902008176640000    
PS C:\Users\MariEli\Desktop> Measure-Command {.\main.exe 20}  
  
  
Days              : 0  
Hours             : 0  
Minutes           : 0  
Seconds           : 0  
Milliseconds      : 16  
Ticks             : 164725  
TotalDays         : 1,90653935185185E-07  
TotalHours        : 4,57569444444444E-06  
TotalMinutes      : 0,000274541666666667  
TotalSeconds      : 0,0164725  
TotalMilliseconds : 16,4725  
