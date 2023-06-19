#include <iostream>

using namespace std;

string readString() {

	string str;
	// cin >> str; // Pega só até o espaço
	getline(cin, str); // Pega até o \n

	return str;
}

class Pessoa {
	
	string nome;

public:

	void setNome(string nome) {
		this->nome = nome;
	}

	string getNome() {
		return nome;
	}
};

int main() {

	Pessoa Gius;

	cout << "Digite seu nome: ";
	Gius.setNome(readString());

	cout << Gius.getNome() << endl;

	return 0;
}