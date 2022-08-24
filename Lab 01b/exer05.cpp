#include <iostream>

using namespace std;

// Preenche uma matriz[4][4] via entrada de teclado.
void lerMatriz( int matriz[][4] ) {
  cout << "Entre com os valores: ";
  for(int w=0;w<4;w++) {
    cout << "Linha " << (w+1) << "\n";
    for(int z=0;z<4;z++) {
      cout << "Valor " << (z+1) << ": ";
      cin >> matriz[w][z];
    }
  }

  cout << "\nMatriz final:\n";
  for(int w=0;w<4;w++) {
    for(int z=0;z<4;z++) {
       cout << "[" << matriz[w][z] << "] ";
    }
    cout << "\n";
  }
}

int main() {
  int matriz[4][4];
  lerMatriz( matriz );
  
  int num;
  
  cout << "\nEntre com o valor para ser multiplicado: ";
  cin >> num;

  cout << "\nA linha da matriz ficou: ";
  for( int i=0;i<4;i++) cout << "[" << (matriz[0][i] * num) << "] ";

  cout << "\nA coluna será: ";
  for( int j=0;j<4;j++ ) cout << "[" << (matriz[j][0] * num) << "] ";
  
  return 0;
}
