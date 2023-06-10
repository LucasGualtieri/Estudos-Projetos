#include <biblioteca_cpp.h>
#include <list.h>

char getCharacter(fstream& file) {
	char c;
	if (!file.get(c)) {
		return '\n';
		// throw runtime_error("Error: Failed to read character from file.");
	}
	return c;
}

string readTilC(fstream& file, char targetCharacter) {
	string str;
	char currentCharacter;

	while (file.get(currentCharacter)) {
		str += currentCharacter;

		if (currentCharacter == targetCharacter) break;
	}

	return str;
}

bool isOneOf(char c, const string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == c) return true;
	}
	return false;
}

string NomeDoJogador(fstream& listaIn) {

	char c;
	string nomeJogador;
	bool fullName = false;

	while (listaIn.get(c) && !fullName) { // Finding first letter

		if (isalpha(c)) { // Reading full name
			int spaceCount = 0;
			do {
				nomeJogador += c;
				if (c == ' ') spaceCount++;
			} while (!isOneOf(c = getCharacter(listaIn), "\n\r\0") && spaceCount < 2);
			fullName = true;
		}
	}

	if (nomeJogador.length() > 0) {
		trim(nomeJogador);
	} else {
		return "FIM";
	}

	return nomeJogador;
}

template <>
void List<string>::populate() {
	fstream listaIn("lista.in");
	readTilC(listaIn, ':'); // skipping the first line

	while (!listaIn.eof()) {
		string jogador = NomeDoJogador(listaIn);
		if (jogador != "FIM") insertEnd(jogador);
	}

	listaIn.close();
}

template <>
void List<string>::print(bool printIndices) {

	fstream listaIn("lista.in");
	string cabecalho = readTilC(listaIn, ':');
	listaIn.close();

	ofstream listaOut("lista.out");

	cout << cabecalho << "\n\n";
	listaOut << cabecalho << "\n\n";

	for (int i = 0; i < size; i++) {
		cout << i + 1 << ") " << array[i] << endl;
		listaOut << i + 1 << ") " << array[i] << endl;
	}

	listaOut.close();
}

int main() {

	List<string> listaJogadores(25);

	listaJogadores.populate();

	listaJogadores.print();

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}