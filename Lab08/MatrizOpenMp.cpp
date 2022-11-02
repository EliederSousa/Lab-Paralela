#include <iostream>
#include <omp.h>

#define m 4
#define n 4

double multiplicarMatriz(double a[][n], double x[], int id);
int numThreads = 4;

int main(int argc, char* argv[]) {
    double A[m][n] = {{1,2,3,4}, {5,6,7,8}, {2,4,6,8}, {1,3,5,7}};
    double X[n] = {9, 10, 11, 12};
    double global_result[n] = {0.0, 0.0, 0.0, 0.0};

    // int thread_count = strtol(argv[1], NULL, 10); // Só faz sentido se o cálculo for automatizado independente do nº de threads
    int thread_count = numThreads;

    #pragma omp parallel num_threads(thread_count) \
        reduction(+:global_result)
    {
        #pragma omp critical
        {
            global_result[0] += multiplicarMatriz( A, X, 0);
            global_result[1] += multiplicarMatriz( A, X, 1);
            global_result[2] += multiplicarMatriz( A, X, 2);
            global_result[3] += multiplicarMatriz( A, X, 3);
        }
    }

    std::cout << "Matriz resultado: " <<    global_result[0] << " - " << \
                                            global_result[1] << " - " << \
                                            global_result[2] << " - " << \
                                            global_result[3] << std::endl;
    

    return 0;
}

double multiplicarMatriz( double a[][n], double x[], int id ) {
    int idThread = omp_get_thread_num();
    // int iteracoes = numThreads/omp_get_num_threads();
    
    double y = 0.0;
    for (int j = 0; j < 4; j++) {
        y += a[id][j] * x[j];
    }
    printf("Resultado da thread %d = %f\n", idThread, y);
    return y;
}
