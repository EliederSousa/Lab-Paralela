#include <iostream>

int main() {
	/* . Crie um programa capaz de ler os dados de uma matriz quadrada de inteiros. 
	Ao final da leitura o programa deverá imprimir o número da linha que contém o menor dentre todos os números lidos.*/
	
	int matriz[4][4] = {{15,18,9,8},{10,40,8,20},{7,19,12,17},{21,14,11,18}};
	
	int menorlinha = 999;
	int menorvalor = 2147483647;
	for (int linha=0; linha<4; linha++) {
		for(int coluna=0; coluna<4; coluna++) {
			if( matriz[linha][coluna] < menorvalor ) {
				menorvalor = matriz[linha][coluna];
				menorlinha = linha;
			}
		}
	}
	
	std::cout << "O menor valor é: " << menorvalor << " na linha " << menorlinha;
	return 0;
}
