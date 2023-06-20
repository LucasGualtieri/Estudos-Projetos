// #include <biblioteca_cpp.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {

	// fstream file("teste.txt"); // Sem nada escreve no começo do arquivo uma vez??? Não cria o arquivo
	// fstream file("teste.txt", ios::in); // NÃO permite entrada de dados. Não cria o arquivo.
	// fstream file("teste.txt", ios::out); // Apaga o arquivo e escreve. Sobrescreve ou cria se precisar
	fstream file("teste.txt", ios::app); // Concatena no fim do arquivo. Cria o arquivo se precisar

	file << "Ola " << endl;
	file << "mundo!";

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}