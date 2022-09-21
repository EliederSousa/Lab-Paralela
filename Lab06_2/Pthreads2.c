/*
    LAB06 - Pthreads 2.
    Elieder Damasceno Sousa - 32093659
    José Eduardo Bernardino Jorge - 42019877
    Turma: 05G
    
    // 10^5
    // 1 thread:   3.141583
    // 2 threads:  3.141583
    // 5 threads:  3.140824
    // 10 threads: 3.141820
    
    // 10^7
    // 1 thread:   3.141593
    // 2 threads:  3.141497
    // 5 threads:  3.141385
    // 10 threads: 3.142976
    
    // 10^9
    // 1 thread:   3.141593
    // 2 threads:  3.141610
    // 5 threads:  3.142777
    // 10 threads: 3.142775
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* Thread_sum( void* rank );

// Variáveis globais (compartilhadas)
int numeroDeThreads;
double sum = 0;
int n = 10000000;

int main(int argc, char* argv[]) {
    
    // Número de threads a serem criadas.
    numeroDeThreads = 1;
    
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
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*) thread);
    }
    
    // Parando todas as threads.
    for( thread=0; thread < numeroDeThreads; thread++ ) {
        // Espera que cada thread conclua sua execução.
        pthread_join(thread_handles[thread], NULL);
    }
    
    printf("\nSoma: %f", 4 * sum);
    
    // Desalocar a memória.
    free(thread_handles);

    return 0;
}

void* Thread_sum( void* rank ) {
    
    // long que indica qual é o ID dessa thread.
    long idThread = (long) rank;
    printf("Iniciando a thread %ld.\n", idThread);
    
    double factor;
    long long i;
    long long my_n = n / numeroDeThreads;
    long long my_first_i = my_n * idThread;
    long long my_last_i = my_first_i + my_n;
    
    if ( my_first_i % 2 == 0)
        factor = 1.0;
    else
        factor = -1.0;
    
    for ( i=my_first_i; i < my_last_i; i++, factor = -factor ) {
        sum += factor / (2 * i + 1);
    }
    
    return NULL;
}
