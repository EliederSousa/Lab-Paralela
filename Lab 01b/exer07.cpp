#include <iostream>
#include <string.h>

using namespace std;

typedef struct {
  string nome;
  int idade;
  float peso;
  float altura;
} PessoaStruct;

int main() {
  PessoaStruct pessoa[3]; 
  for( int w=0;w<3;w++) {
    cout << "Entre com os dados da pessoa " << (w+1) << ": ";
    cout << "Nome: ";
    cin >> pessoa[w].nome;
    cout << "Idade: ";
    cin >> pessoa[w].idade;
    cout << "Peso: ";
    cin >> pessoa[w].peso;
    cout << "Altura: ";
    cin >> pessoa[w].altura;
  }

  string nome;
  cout << "Entre com o nome da pessoa para verificar os dados: ";
  cin >> nome;
  
  for(int w=0;w<3;w++) {
    if(pessoa[w].nome == nome) {
      cout << "\nIdade: " << pessoa[w].idade << endl;
      cout << "Peso: " << pessoa[w].peso << endl;
      cout << "Altura: " << pessoa[w].altura << endl;
    }
  }
    
  return 0;
}
