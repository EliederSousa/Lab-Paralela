/** 
 *  main.cpp
 *  
 *  Copyright (c) 2022
 *  
 *  Distributed under the MIT license.
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *  
 *  @date 23/11/22
 *  
 *  @brief  Calcula a constante de Euler utilizando um somatório de frações.
 *  
 *          Projeto da disciplina de Computação Paralela, Universidade Presbiteriana Mackenzie, 5º semestre, 2022
 *          Autores: 
 *              Elieder Damasceno Sousa
 *              José Eduardo Bernardino Jorge
 *  
 */

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

int MAXDIGITS = 10000000;
long base = 10;

class BigInt {
    public:
        int *num;
        int size;
        int tens;
        int *nonTenFactors;
        int factorsSize;

    public:
        BigInt( int initialValue ) {
            tens = 0;
            nonTenFactors = new int[MAXDIGITS];
            factorsSize = 0;
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

        BigInt( string strValue ) {
            tens = 0;
            nonTenFactors = new int[MAXDIGITS];
            factorsSize = 0;
            num = new int[MAXDIGITS];
            size = strValue.length();
            for ( int w=0; w<MAXDIGITS; w++ ) {
                num[w] = 0;
            }
            for( int w=0; w<size; w++ ) {
                num[MAXDIGITS-1-w] = strValue.at(w);
            }
        }

        void reset( int initialValue ) {
            tens = 0;
            nonTenFactors = new int[MAXDIGITS];
            factorsSize = 0;
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

        void multiplyByTens( int numberOfZeros ) {
            for (int actual=MAXDIGITS-size; actual<MAXDIGITS; actual++) {
                num[actual-numberOfZeros] = num[actual];
            }
            for( int w=0;w<numberOfZeros; w++ ) {
                num[MAXDIGITS - 1 - w] = 0;
            }
            size += numberOfZeros;
        }

        void multiply(int x) {
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

        void divideByTens( int numberOfZeros ) {
            if( numberOfZeros < size ) {
                for (int actual=0; actual<size; actual++) {
                    num[MAXDIGITS-1-actual] = num[MAXDIGITS-1-actual-numberOfZeros];
                }
                size -= numberOfZeros;
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

        void subtract( BigInt valor ) {
            int borrow = 0;
            for(int i=MAXDIGITS-size; i < MAXDIGITS; i++) {
                int result= (num[i] - valor.num[i] - borrow);
                if(result < 0) {
                    num[i] = result + 10;
                    borrow = 1;
                } else {
                    num[i] = result;
                    borrow = 0;
                }
            }
        }

        

        void fatorial( int n ) {
            reset( 1 );
            int twos = 0;
            int fives = 0;
            tens = 0;
            #pragma omp parallel num_threads(2)
            {
                int idThread = omp_get_thread_num();
                int candidate = 0;
                int temptwos = 0;
                int tempfives = 0;
                for( int w=2+idThread;w<=n;w+=2 ) {
                    candidate = w;
                    while( candidate % 2 == 0 ) {
                        candidate /= 2;
                        temptwos++;
                    }
                    while( candidate % 5 == 0 ) {
                        candidate /= 5;
                        tempfives++;
                    }
                    if( candidate != 1 ) {
                        #pragma omp critical
                        {
                            nonTenFactors[factorsSize] = candidate;
                            factorsSize++;
                            multiply(candidate);
                        }
                    }
                }
                #pragma omp critical
                {
                    twos += temptwos;
                    fives += tempfives;
                }
            }
            tens = fives;
            multiplyByTens( tens );
            twos -= fives;
            nonTenFactors[factorsSize] = 1;
            
            for( int w=0; w<twos; w++ ) {
                if( nonTenFactors[factorsSize] < 8388608 ) {
                    nonTenFactors[factorsSize] *= 2;
                } else {
                    factorsSize++;
                    nonTenFactors[factorsSize] = 2;
                }
                multiply(2);
            }
        }
};

int main() {
    using namespace std::chrono;
  	high_resolution_clock::time_point time1;
  	high_resolution_clock::time_point time2;
    time1 = high_resolution_clock::now();

    int iterations = 300000;

    BigInt a = BigInt(0);
    BigInt copy = BigInt(0);

    cout << "Calculando o maior fatorial...\n";
    a.fatorial(iterations);

    int numDigits = a.size;
    cout << "\nNumero de casas decimais certas (aproximadamente): " << numDigits << "\n";

    cout << "\nCalculando as fracoes... \n";
    BigInt decimals = BigInt(0);
    int integerPart = 2;
    int fivePercent = floor(iterations / 20);
    BigInt tempmultiplication = BigInt(1);

    #pragma omp parallel num_threads(2)
	{
		int idThread = omp_get_thread_num();
        printf("Iniciando a thread %d...\n", idThread);

		int last = (iterations / 5);

		BigInt decimalsPartial = BigInt(0);

		if( idThread == 0 ) {
			// Começamos com 2 por que não precisamos calcular 1/0! + 1/1! (pois o resultado é 2).
			for( int w=2; w<last; w++ ) {
				if (w % 1000 == 0) std::cout << "Thread 0 calculando a " << w << "a divisao e somando o resultado...\n";
                a.divide(w);
                decimalsPartial.add(a);
			}
            #pragma omp critical
            {
                decimals.add(decimalsPartial);
            }
		} else {
			// Começamos com 2 por que não precisamos calcular 1/0! + 1/1! (pois o resultado é 2).
			for( int w=iterations; w>last; w-- ) {
				if (w % 1000 == 0) std::cout << "Thread 1 calculando a " << w << "a divisao e somando o resultado...\n";
				tempmultiplication.multiply(w);
				// A área crítica é essa.
				#pragma omp critical 
				{
					decimalsPartial.add(tempmultiplication);
				}
			}
            #pragma omp critical
            {
                decimals.add(decimalsPartial);
            }
		}
	}

    cout << "\nExpandindo casas decimais...\n";
    decimals.multiplyByTens(numDigits);
    
    cout << "\nDividindo a fracao final...\n";
    
    decimals.divideByTens( a.tens );
    fivePercent = floor(a.factorsSize / 20);
    for( int w=0;w<=a.factorsSize;w++ ) {
        if( w % fivePercent == 0 ) cout << floor(w/fivePercent) * 5 << "% ";
        decimals.divide( a.nonTenFactors[w] );
    }

    ofstream myfile;
    myfile.open ( to_string(numDigits) + ".txt" );
    myfile << ("2." + decimals.toString());
    myfile.close();

    time2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(time2 - time1);
    std::cout << "Calculado em " << std::setprecision(5) << time_span.count() << "s.\n";

    return 0;
}
