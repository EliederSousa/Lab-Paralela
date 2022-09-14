/*
    LAB06 - Pthreads.
    Elieder Damasceno Sousa - 32093659
    José Eduardo Bernardino Jorge - 42019877
    Turma: 05G
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* Pth_mat_vect(void* rank);

// Variáveis globais (compartilhadas)
#define m 4
#define n 4
int numeroDeThreads;
double A[m][n] = {{1,2,3,4}, {5,6,7,8}, {2,4,6,8}, {1,3,5,7}};
double X[m] = {9, 10, 11, 12};
double Y[m] = {0.0, 0.0, 0.0, 0.0};


int main(int argc, char* argv[]) {
    
    // Número de threads a serem criadas (passado como argumento).
    numeroDeThreads = strtol(argv[1], NULL, 10);
    
    // Nosso programa calcula a multiplicação de uma matriz qudrada 4x4 por um vetor 1x4.
    // Não faz sentido criar 0, 3 ou 5 ou mais threads. Só é aceito 1, 2 ou 4 threads.
    if ((numeroDeThreads <= 0) || (numeroDeThreads > 4) || (numeroDeThreads == 3)) {
        printf("Erro ao passar o argumento: deve ser 1, 2 ou 4.");
    } else {
        // O número da thread (como um ID).
        long thread;
        // Um ponteiro para os manipuladores das threads (uma array de threads).
        pthread_t* thread_handles;
        
        
        
        // Alocação de memória para as threads:
        // número de threads * o tamanho de cada uma delas
        thread_handles = malloc(numeroDeThreads * sizeof(pthread_t));
        
        printf("Thread principal executando...\n\n");
        
        // Criando todas as threads.
        for( thread=0; thread < numeroDeThreads; thread++ ) {
            // Cria uma thread, indicando a função a ser executada para cada uma
            // e o argumento a ser passado para ela (void*) thread
            pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);
        }
        
        // Parando todas as threads.
        for( thread=0; thread < numeroDeThreads; thread++ ){
            // Espera que cada thread conclua sua execução.
            pthread_join(thread_handles[thread], NULL);
        }
        
        printf("\nResultado final das operações:\n");
        int w;
        for( w=0; w<4;w++) {
            printf("Y[%d] = %.1f\n", w, Y[w]);
        }
        
        // Desalocar a memória.
        free(thread_handles);
    }
    return 0;
}

void* Pth_mat_vect(void* rank) {
    
    // long que indica qual é o ID dessa thread.
    long idThread = (long) rank;
    printf("Iniciando a thread %ld.\n", idThread);
    
    int i, j;
    // M é a quantidade de subproblemas que podemos ter no problema completo.
    // No nosso caso, seria o tamanho da matriz (caso seja quadrada, 4x4 -> m = 4)
    int iteracoes = m/numeroDeThreads; // local_m é quantas "coisas" essa thread vai realizar
    
    int init = idThread*iteracoes;             // Primeira linha a multiplicar
    int end = (idThread + 1) *iteracoes - 1;   // Última linha para multiplicar
    
    // Faz o cálculo da multiplicação.
    for (i = init; i <= end; i++){
        Y[i] = 0.0;
        for (j = 0; j < n; j++)
            Y[i] += A[i][j] * X[j];
    }
    
    printf("Thread %ld finalizada.\n\n", idThread);
    return NULL;
}