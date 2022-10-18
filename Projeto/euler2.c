#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* somaFracao( void* rank );

#define NTHREADS 2
long double sum = 0;
int n;

long double fatorial( int n ) {
    if (n == 0) return 1;
    
    int w;
    long double result = 1;
    
    for ( w=1; w<=n; w++ )
        result *= w;
        
    return result;
}

int main( int argc, char* argv[] ) {
    
    if( argc > 0 )
        n = atoi(argv[1]);
    else
        n = 10000;
    
    long thread;
    pthread_t* thread_handles;

    thread_handles = malloc(NTHREADS * sizeof(pthread_t));
	printf("Thread principal executando.\n");
    
    // Criando as threads.
    for( thread=0; thread < NTHREADS; thread++ )
        pthread_create(&thread_handles[thread], NULL, somaFracao, (void*) thread);
    
    // Parando as threads.
    for( thread=0; thread < NTHREADS; thread++ ) {
        pthread_join(thread_handles[thread], NULL);
    }
    
    free(thread_handles);
    printf( "\nE com %d interacoes: %.18Lf\n", n, sum );
    return 0;
}

void* somaFracao( void* rank ) {
    long idThread = (long) rank;
    printf("Iniciando a thread %ld.\n", idThread);
    
    long long i;
    long long my_n = n / NTHREADS;
    long long my_first_i = my_n * idThread;
    long long my_last_i = my_first_i + my_n;
    
    for ( i=my_first_i; i < my_last_i; i++ )
        sum += 1.0 / fatorial(i);

}