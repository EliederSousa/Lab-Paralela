#include <stdio.h>
#include <stdlib.h>

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
    int n;
    int m;
    if( argc > 0 ) {
   	 m = atoi(argv[1]);
    } else {
	 m = 100000;
    }
    double result = 0;
    for ( n=0; n<m; n++ ) {
        result += 1 / (float)fatorial(n);
    }
    printf( "E com %d interacoes: %lf\n", m, result );
    return 0;
}
