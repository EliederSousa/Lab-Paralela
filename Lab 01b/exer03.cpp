/*Faça o programa que apresenta a seguinte saída, perguntando ao usuário o número máximo (no exemplo, 9). Este número deve ser sempre ímpar.

1 2 3 4 5 6 7 8 9
   2 3 4 5 6 7 8
      3 4 5 6 7
         4 5 6
            5   */

#include <iostream>

int main() {
  int max;
  std::cout << "Digite o número máximo(impar): ";
  std::cin >> max;

  for (int linha=0;linha<=max/2;linha++) {
    for (int s=0; s<linha; s++) {
      std::cout << "  ";
    }
    for(int w=linha;w<max-linha;w++) {
      std::cout << (w+1) << " ";
    }
    std::cout << "\n";
  }
  return 0;
}
