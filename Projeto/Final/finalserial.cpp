#include <iostream>
#include <iomanip>
#include <ctime>
#include <math.h>
#include <ratio>
#include <chrono>
#include <string>
#include <omp.h>
#include <fstream>

using namespace std;

int MAXDIGITS = 1000000;
long base = 10;

class BigInt {
    public:
        int *num;
        int size;

    public:
        BigInt( int initialValue ) {
            num = new int[MAXDIGITS];
            size = floor(log10(initialValue) + 1);
            for ( int w=0; w<MAXDIGITS; w++ ) {
                num[w] = 0;
            }
            num[MAXDIGITS-1] = initialValue;
            for( int w=0; w<size; w++ ) {
                num[MAXDIGITS-1-w] = (int)(initialValue / pow(10, w)) % 10;
            }
        }

        void reset( int initialValue ) {
            size = floor(log10(initialValue) + 1);
            for ( int w=0; w<MAXDIGITS; w++ ) {
                num[w] = 0;
            }
            num[MAXDIGITS-1] = initialValue;
            for( int w=0; w < size; w++ ) {
                num[MAXDIGITS-1-w] = (int)(initialValue / pow(10, w)) % 10;
            }
        }

        void copy( BigInt value ) {
            reset(0);
            for ( int w=0;w<MAXDIGITS; w++ ) {
                num[w] = value.num[w];
            } 
        }

        int digit( int n ) {
            return num[n];
        }

        void print() {
            for( int w=MAXDIGITS-size; w<MAXDIGITS; w++ ) {
                std::cout << num[w];
            }
            std::cout << std::endl;
        }

        string toString() {
            std::string str;
            for( int w=MAXDIGITS-size; w<MAXDIGITS; w++ ) {
                str.push_back(num[w] + '0');
            }
            return str;
        }

        /*void multiplyByTens( int numberOfZeros ) {
            for (int actual=MAXDIGITS-size; actual<MAXDIGITS; actual++) {
                num[actual-numberOfZeros] = num[actual];
            }
            num[MAXDIGITS - 1] = 0;
            size += numberOfZeros;
        }*/

        void multiply(int x) {
            /*while( x % 10 == 0 ) {
                x /= 10;
                multiplyByTens(1);
            }*/
            int carry = 0;
            int actual;
            for (int i=0; i<size; i++) {
                actual = MAXDIGITS - 1 - i;
                int prod = num[actual] * x + carry;
                num[actual] = prod % 10;
                carry  = prod/10;
            }

            while (carry) {
                num[MAXDIGITS - 1 - size] = carry%10;
                carry = carry/10;
                size++;
            }
        }

        void divide(long divisor) {
            long carry=0, xi, q;
            for (long i=MAXDIGITS-size; i<MAXDIGITS; i++) {
                xi    = num[i]+carry*base;
                q     = xi/divisor;
                carry = xi-q*divisor;   
                num[i]  = q;        
            }  
            bool running = true;
            int newSizeToSubtract = 0;
            for (long i=MAXDIGITS-size; i<MAXDIGITS; i++) {
                if( running && (num[i] == 0) ) {
                    newSizeToSubtract++;
                } else {
                    running = false;
                }
            }
            size -= newSizeToSubtract;
        }

        void add( BigInt valor ) {
            long carry=0;
            if( valor.size > size ) {
                size = valor.size;
            }
            for (int i=MAXDIGITS-1; i>=MAXDIGITS-size; i--) {
                num[i] += valor.num[i]+carry;
                if (num[i]<base) {
                    carry = 0;
                } else {
                    carry = 1;
                    num[i] -= base;
                }
            }
            if ( carry ) {
                num[MAXDIGITS-size-1] = 1;
                size++;
            }
        }

        void fatorial( int n ) {
            reset( 1 );
            for( int w=2;w<=n;w++) {
                multiply(w);
            }
        }
};

int main() {
    using namespace std::chrono;
  	high_resolution_clock::time_point time1;
  	high_resolution_clock::time_point time2;
    time1 = high_resolution_clock::now();

    int iterations = 10000;

    BigInt a = BigInt(0);
    BigInt copy = BigInt(0);

    cout << "Calculando o maior fatorial...\n";
    a.fatorial(iterations);

    int numDigits = a.size;

    cout << "Calculando as fracoes... \n";
    BigInt decimals = BigInt(0);
    int integerPart = 2;

    int fivePercent = floor(iterations / 20);
    for (int w=2; w<=iterations; w++ ) {
        if( w % fivePercent == 0 ) cout << floor(w/fivePercent) * 5 << "% ";
        a.divide(w);
        decimals.add(a);
    }

    cout << "\n\nExpandindo casas decimais... ";
    int tenPercent = floor(numDigits / 10);
    for ( int w=0;w<numDigits;w++) {
        if( w % tenPercent == 0 ) cout << floor(w/tenPercent) * 10 << "% ";
        decimals.multiply(10);
    }
    
    cout << "\n\nDividindo a fracao final... ";
    for( int w=2;w<=iterations;w++) {
        if( w % fivePercent == 0 ) cout << floor(w/fivePercent) * 5 << "% ";
        decimals.divide(w);
    }
    
    cout << "\n\nNumero de casas decimais: " << numDigits << "\n";

    cout << "2." << decimals.toString() << "\n";

    /*ofstream myfile;
    myfile.open ( to_string(numDigits) + ".txt" );
    myfile << ("2." + decimals.toString());
    myfile.close();*/

    time2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(time2 - time1);
    std::cout << "Calculado em " << std::setprecision(3) << time_span.count() << "s.\n";

    return 0;
}
