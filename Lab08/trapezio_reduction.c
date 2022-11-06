#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

double f(double x) {
	return exp(x);
}

int main(int argc, char* argv[]){
    double global_result = 0.0;
    double a, b;
    long int n;
    int thread_count;

    thread_count = strtol(argv[1], NULL, 10);
    a = 0;
    b = 1;
    n = 1000000000;
    #pragma omp parallel num_threads(thread_count) reduction(+:global_result)
    {
        double h, x, my_result;
        double local_a, local_b;
        int i, local_n;
        int my_rank = omp_get_thread_num();
        int thread_count = omp_get_num_threads();
        printf("Thread %d iniciando.\n", my_rank);

        h = (b-a)/n;
        local_n = n/thread_count;
        local_a = a + my_rank * local_n * h;
        local_b = local_a + local_n * h;
        my_result = (f(local_a) + f(local_b)) / 2.0;

        for (i = 1; i <= local_n - 1; i++) {
            x = local_a + i * h;
            my_result += f(x);
        }
        my_result = my_result * h;
        global_result += my_result;
    }
    printf("With n = %ld trapezoids, our estimate\n", n);	
    printf("of the integral from %f to %f = %.14e\n", a, b, global_result);

    return 0;
}
