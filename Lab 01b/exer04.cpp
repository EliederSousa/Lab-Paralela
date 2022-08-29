#include <iostream>
#include <string>

using namespace std;

void ordemalf(char nome1[], char nome2[]){
  for(int w=0;w<100;w++) {
    int a = (int)nome1[w];
    int b = (int)nome2[w];
    if( a > b ) {
      cout << nome2 << '\n';
      cout << nome1;
      break;
    } if( a < b ) {
      cout << nome1 << '\n';
      cout << nome2;
      break;
    } else {
      continue;
    }
  }
}

int main() {
    // 4. Crie um progama capaz de ler dois nomes de pessoas e imprimi-los em ordem alfabética. Faça isto com string de C e de C++ 

  char nome1 [100];
  char nome2 [100];

  cout << "Entre com o primeiro nome: ";
  cin >> nome1;

  cout << "Entre com o segundo nome: ";
  cin >> nome2;

  ordemalf( nome1, nome2 );
  
  return 0;
} 
