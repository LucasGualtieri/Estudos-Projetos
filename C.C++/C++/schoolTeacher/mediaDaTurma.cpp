#include <biblioteca_cpp.h>

#include "Classes/Aluno.h"
#include "Classes/Lista.h"

// bool novoAluno(String nomeDoAssassino, ListaAssassinos assassinos) {
// 	for (int i = 0; i < assassinos.getN(); i++) {
// 		// Conferindo se o assassino já apareceu antes
// 		if (assassinos.getArrayNome(i).equals(nomeDoAssassino)) {
// 			return true;
// 		}
// 	}
// 	return false;
// }

int ValorDaProva() {
	FILE* lista = fopen("prova_1.txt", "r");
	char* buffer = getstr(lista);

	int valorDaProva = atoi(substr(buffer, indexOf(buffer, (char*)" ", 3) + 1, strlen(buffer)));

	free(buffer);
	fclose(lista);

	return valorDaProva;
}

// Um aluno deve ser lido e criado, seus atributos deve ter o nome lido e a nota lida
// Esse aluno deve ser adicionado a uma lista

int main() {

	Lista* listaDeAlunos = new Lista();

	int valorDaProva = ValorDaProva();

	ifstream arquivo("prova_1.txt");

	string buffer;

	while (getline(arquivo, buffer)) {
		cout << buffer << endl;
		string nomeSobrenome;
		int nota;
		listaDeAlunos->inserirInicio(new Aluno(nomeSobrenome, nota));
	}

	arquivo.close();

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}