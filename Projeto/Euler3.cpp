#include <iostream>
#include <iomanip>
#include <omp.h>

using namespace std;

long double fatorial( int n ) {
    if (n == 0) return 1;
    
    int w;
    long double result = 1;
    
    for ( w=1; w<=n; w++ )
        result *= w;
        
    return result;
}

int main( int argc, char* argv[] ) {

    long double eulerconstant = 0.0;
    int numThread, precision;

   
    numThread = 2;
    precision = 1000000;
   
    #pragma omp parallel num_threads(numThread)
    {
        int idThread = omp_get_thread_num();
        int iteracoes = precision / omp_get_num_threads();
        printf("Iniciando a thread %d...\n", idThread);
        
        long long i;
        long long my_n = precision / numThread;
        long long my_first_i = my_n * idThread;
        long long my_last_i = my_first_i + my_n;

        long double temp_fatorial = fatorial(my_first_i);
        long double euler_parcial = 1.0 / temp_fatorial;
        
        for ( i=my_first_i+1; i < my_last_i; i++ ) {	
            temp_fatorial *= i;
            euler_parcial += 1.0 / temp_fatorial;
        }
        
        #pragma omp critical
        {
            eulerconstant += euler_parcial;
        }
    }
    cout << "\nE com " << precision << " interacoes: " << setprecision(17) << eulerconstant;

    return 0;
}
