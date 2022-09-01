Compilamos usando {gcc main.c -o main} no windows e o tempo gasto para rodar foi em média 16 Milissegundos  
  
Testamos com o fatorial de 20 e resultou em:   
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
  
Testamos o fatorial de 20 com o código que o professor disponibilizou, não apresenta o valor correto e o tempo foi de:  
PS C:\Users\MariEli\Desktop> Measure-Command {./fatorial.exe 20 }  
  
Days              : 0  
Hours             : 0  
Minutes           : 0  
Seconds           : 0  
Milliseconds      : 40  
Ticks             : 400012  
TotalDays         : 4,62976851851852E-07  
TotalHours        : 1,11114444444444E-05  
TotalMinutes      : 0,000666686666666667  
TotalSeconds      : 0,0400012  
TotalMilliseconds : 40,0012  
