#include <stdio.h>

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

int main()
{
    int n;
    int m = 12;
    double result = 0;
    for ( n=0; n<m; n++ ) {
        result += 1 / (float)fatorial(n);
    }
    printf( "E com %d interacoes: %lf\n", m, result );
    return 0;
}
