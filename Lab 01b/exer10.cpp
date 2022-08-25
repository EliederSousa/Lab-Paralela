/* Crie uma função capaz de multiplicar uma linha de uma matriz por um dado número. Faça o mesmo para uma coluna. */
#include <iostream>

using namespace std;

int main() {
  int matriz[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  
  int num;
  
  cout << "\nEntre com o valor para ser multiplicado: ";
  cin >> num;

  cout << "\nA linha da matriz ficou: ";
  for( int i=0;i<4;i++) cout << "[" << (matriz[0][i] * num) << "] ";

  cout << "\nA coluna será: ";
  for( int j=0;j<4;j++ ) cout << "[" << (matriz[j][0] * num) << "] ";
  
  return 0;
}
