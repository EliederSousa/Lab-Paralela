#include <iostream>
#include <vector>
#include <omp.h>
#include <stdio.h>

using namespace std;

#define m 5000 // linhas
#define n 5000 // colunas

int main(int argc, char* argv[]) {    
    int numThreads = strtol(argv[1], NULL, 10);
   
    vector<vector<long double>> A(m, vector<long double>(n));
    vector<long double> X(n, 0);
    //vector<long double> global_result(n, 0);
    long double global_result[n];
    for(int x=0; x < n; x++ ) {
	global_result[x] = 0.0;
    }
	    
    // Preenche a matriz A
    for (int x=0; x < m; x++ ) {
        for (int y=0; y < n; y++ ) {
            A[x][y] = (long double)(x+1)/(y+1);
        }
    }

    // Preenche o vetor X
    for (int y=0; y < n; y++ ) {
        X[y] = (long double)y+1;
    }
    
    int thread_count = numThreads;

    #pragma omp parallel num_threads(thread_count) reduction(+:global_result[:n])
    {
        int idThread = omp_get_thread_num();
        int iteracoes = n/omp_get_num_threads();

        int init = idThread * iteracoes;
        int last = ((idThread + 1) * iteracoes) - 1;
	printf("Thread %d calculando de %d ate %d multiplicacoes.\n", idThread, init, last);

        // Faz o cálculo da multiplicação.
        for (int i = init; i <= last; i++){ // linhas
            long double y = 0.0;
	    for (int j = 0; j < n; j++) { // colunas
		y += A[i][j] * X[j];
            }
	    #pragma omp critical
	    {
	        global_result[i] = y;
	    }
        }
    }

    return 0;
}
