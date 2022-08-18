#include <iostream>

using namespace std;
int main() {
  /* Escreva um programa que leia 3 notas de um aluno e a média das notas dos exercícios realizados por ele. Calcular a média de aproveitamento, usando a fórmula: MA = (N1 + N2*2 + N3*3 + ME)/7. A partir da média, informar o conceito de acordo com a tabela:
maior ou igual a 9	A
maior ou igual a 7.5 e menor que 9	B
maior ou igual a 6 e menor que 7.5	C
maior ou igual a 4 e menor que 6	D
menor que 4	E */
  float nota[4];
  
  for (int w=0;w<4;w++) {
    if(w < 3) {
      cout << "Entre com a " << (w + 1) << "ª nota: ";
    } else {
      cout << "Entre com a média dos exercícios: ";
    }
    cin >> nota[w];
  }

  float ma = (nota[0] + nota[1]*2 + nota[2]*3 + nota[3])/7; 

  if( ma >= 9 ) {
    cout << "Nota A";
  } else if( ma >= 7.5 ) {
    cout << "Nota B";
  } else if( ma >= 6) {
    cout << "Nota C";
  } else if( ma >= 4) {
    cout << "Nota D";
  } else {
    cout << "Nota E";
  }
  
  return 0; 
}
