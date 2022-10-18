#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* somaFracao( void* rank );

#define NTHREADS 2
double sum = 0;
int n;

int fatorial( int n ) {
    int w;
    if (n == 0) {
        return 1;
    }
    
    float result = 1;
    for ( w=1; w<=n; w++ ) {
        result *= w;
    }
    return result;
}

int main( int argc, char* argv[] ) {
    
    if( argc > 0 ) {
        n = atoi(argv[1]);
    } else {
        n = 10000;
    }
    
	// O número da thread (como um ID).
    long thread;
    // Um ponteiro para os manipuladores das threads (uma array de threads).
    pthread_t* thread_handles;

	// Alocação de memória para as threads:
    // número de threads * o tamanho de cada uma delas
    thread_handles = malloc(NTHREADS * sizeof(pthread_t));
	printf("Thread principal executando...\n\n");

    // Criando todas as threads.
    for( thread=0; thread < NTHREADS; thread++ ) {
        // Cria uma thread, indicando a função a ser executada para cada uma
        // e o argumento a ser passado para ela (void*) thread
        pthread_create(&thread_handles[thread], NULL, somaFracao, (void*) thread);
    }
    
    // Parando todas as threads.
    for( thread=0; thread < NTHREADS; thread++ ) {
        // Espera que cada thread conclua sua execução.
        pthread_join(thread_handles[thread], NULL);
    }
    
    // Desalocar a memória.
    free(thread_handles);
    printf( "E com %d interacoes: %lf\n", n, sum );
    return 0;
}

void* somaFracao( void* rank ) {
    
    // long que indica qual é o ID dessa thread.
    long idThread = (long) rank;
    printf("Iniciando a thread %ld.\n", idThread);
    
    double factor;
    long long i;
    long long my_n = n / NTHREADS;
    long long my_first_i = my_n * idThread;
    long long my_last_i = my_first_i + my_n;
    
    for ( i=my_first_i; i < my_last_i; i++ ) {
        sum += 1 / (float)fatorial(i);
    }
    
    return NULL;
}
