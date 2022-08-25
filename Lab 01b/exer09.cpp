/* Crie uma função capaz de substituir todos os números negativos de uma matriz por seu módulo. */
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int matriz[3][3] = {{1,-2,3},{-4,5,6},{-7,8,-9}};

  cout << "Matriz 3x3: " << endl;
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      cout << "[" << matriz[i][j] << "] ";
    }
    cout << "\n";
  }

  cout << "\nMatriz final: " << endl;
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      matriz[i][j] = abs(matriz[i][j]);
      cout << "[" << matriz[i][j] << "] ";
    }
    cout << "\n";
  }
  
  return 0;
}
