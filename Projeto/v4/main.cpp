#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <omp.h>
#include <vector>
#include <string>
#include "bigint.h"

int multiply(int x, int res[], int res_size) {
    int carry = 0;
    for (int i=0; i<res_size; i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;  
        carry  = prod/10;    
    }

    while (carry) {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

int fatorial( int *fat, int s, int n ) {
    fat[0] = 1;
    s = 1;
    for ( int w=1; w<=n; w++ ) {
        s = multiply(w, fat, s);
    }
    return s;
}

// Calma, só usamos isso pra saber quantos digitos temos de precisão e mais nada. kkk 
int numDigits( int n ) {
    return ceil( log10(sqrt(2*3.1415926535897932384*n)) + n * log10(n/exp(1)) );
}

int main() {
	using namespace std::chrono;
  	high_resolution_clock::time_point time1 = high_resolution_clock::now();
	
	int iterations = 2000;

	std::vector<int> fator;

	std::cout << "Calculando o fatorial de " << iterations << " ...\n";

	int *fat = new int[1000000];
	int size = 1;

	// Falta de tempo dá nisso.
	size = fatorial(fat, size, iterations);

	// E isso
	for( int w=0;w<size; w++ ) {
        fator.push_back(fat[w]);
    }
	// E mais isso
	std::string s;
    while (fator.size()) {
        s.push_back(fator.back() + '0');
        fator.pop_back();
    }

	// Por incrível que pareça, até aqui foi a parte rápida do código. Se der alguns segundos, é muito.
	delete fat; // É um vetor grande demais pra deixar vagando na memória.
	
	// Variáveis "globais"
	int numThread = 2;
	BigInt sum = 1;
	BigInt precision = numDigits(iterations) + 3;
	BigInt result = BigInt(s);
	BigInt copyResult = result;

	#pragma omp parallel num_threads(numThread)
	{
		int idThread = omp_get_thread_num();
        int localIterations = (iterations - 2) / omp_get_num_threads();
        printf("Iniciando a thread %d...\n", idThread);

		int last = iterations / 2;
		BigInt tempmultiplication = 1;

		if( idThread == 0 ) {
			// Começamos com 2 por que não precisamos calcular 1/0! + 1/1! (pois o resultado é 2).
			for( int w=2; w<last; w++ ) {
				if (w % 50 == 0) {
					std::cout << "Thread 0 calculando a " << w << "a divisao e somando o resultado...\n";
				}
				// Um jeito otimizado de dividir 1/n! : dividir o fatorial por n
				// Dá na mesma, mas evita contas com muitos números quebrados.
				// Primeiro lugar de demora no código.
				result /= w;

				// A área crítica é essa.
				#pragma omp critical 
				{
					sum += result;
				}
			}
		} else {
			// Começamos com 2 por que não precisamos calcular 1/0! + 1/1! (pois o resultado é 2).
			for( int w=iterations; w>last; w-- ) {
				if (w % 50 == 0) std::cout << "Thread 1 calculando a " << w << "a divisao e somando o resultado...\n";
				// Um jeito otimizado de dividir 1/n! : dividir o fatorial por n
				// Dá na mesma, mas evita contas com muitos números quebrados.
				// Primeiro lugar de demora no código.
				
				tempmultiplication *= w;

				// A área crítica é essa.
				#pragma omp critical 
				{
					sum += tempmultiplication;
				}
			}
		}
	}

	// Essa lib BigInt não tem precisão para números float. Adicionamos então precisão manual.
	for( int w=0; w<precision; w++ ) sum *= 10;

	// O 2 é trivial. Resultado de 1/0! + 1/1! .
	std::cout << "\nEste resultado tem aproximadamente " << numDigits(iterations) + 2 << \
				 " casas decimais corretas. Calculando a divisao total...\n" << std::endl;
	std::cout << "2." << sum / copyResult; // Segundo lugar de demora no codigo.

	high_resolution_clock::time_point time2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(time2 - time1);
    std::cout << "\nCalculado em " << time_span.count() << "s.";
	return 0;
}
