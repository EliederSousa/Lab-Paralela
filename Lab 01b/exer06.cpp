#include <iostream>

using namespace std;

// Preenche uma matriz[3][3] via entrada de teclado.
void lerMatriz( int matriz[][3] ) {
  cout << "Entre com os valores: ";
  for(int w=0;w<3;w++) {
    cout << "Linha " << (w+1) << "\n";
    for(int z=0;z<3;z++) {
      cout << "Valor " << (z+1) << ": ";
      cin >> matriz[w][z];
    }
  }

  cout << "\nMatriz final:\n";
  for(int w=0;w<3;w++) {
    for(int z=0;z<3;z++) {
       cout << "[" << matriz[w][z] << "] ";
    }
    cout << "\n";
  }
}

int main() {
  int matriz[3][3];
  lerMatriz( matriz );

  cout << "\nMatriz transposta:\n";
  int matrizTransposta[3][3];
  for( int i=0;i<3;i++ ) {
    for( int j=0;j<3;j++ ) {
      matrizTransposta[i][j] = matriz[j][i];
      cout << "[" << matrizTransposta[i][j] << "] ";
    }
    cout << "\n";
  }
  
  return 0;
}
