// Crie uma função capaz de somar os elementos das linhas L1 e L2 de uma matriz. O resultado deve ser colocado na linha L2. Faça o mesmo com a multiplicação.
#include <iostream>

using namespace std;

void somaLinhaMatriz( int matriz[][3] ) {
  for( int j=0;j<3;j++ ) {
    matriz[1][j] += matriz[0][j];
  }
}

void multiplicaLinhaMatriz( int matriz[][3] ) {
  for (int j=0;j<3;j++){
    matriz[1][j] *= matriz[0][j];
  }
}

int main() {
  int matriz [3][3] ={{1,2,3},{4,5,6},{7,8,9}};

  cout << "Matriz Original:\n";
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      cout << "[" << matriz[i][j] << "] ";
    }
    cout << "\n";
  }

  cout << "\nSoma das linhas:\n";
  somaLinhaMatriz(matriz);
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      cout << "[" << matriz[i][j] << "] ";
    }
    cout << "\n";
  }

  cout << "\nMultiplicacao das linha:\n";
  multiplicaLinhaMatriz(matriz);
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      cout << "[" << matriz[i][j] << "] ";
    }
    cout << "\n";
  }
  return 0;
}
