/*#include <iostream>

using namespace std;

// Método não destrutivo. Todos os caracteres existentes são jogados para
// a direita, dando lugar ao novo caractere. Não adiciona se o indice passado for maior que a string 
void addChar(char str[], int index, char c) {
  int lastChar = 100;
  do {
    lastChar--;
  } while( str[lastChar] != '\0' );
  for(int w=lastChar;w>=index; w--) {
    str[w+1] = str[w];
  }
  str[index] = c;
}

int main() {
	char str[100] = {'a','b','c','d','e','f','g','h','i','j'};
  // Adiciona a letra 'A' no 2º índice
  addChar(str, 2, 'A');
  // Saída: abAcdefghij
	cout << str;
	return 0;
}*/