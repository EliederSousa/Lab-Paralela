#include <math.h>
#include <stdio.h>

double Fatorial( int n ) {
	return (sqrt(2 * 3.1415 * n) * pow( n / 2.718281828459045235360, n ));
}


int main() {
	int num;
	printf("Digite o numero para calcular o fatorial: ");
	scanf("%d", &num);
	
	printf("%f", Fatorial(num));
  
  return 0;
}
