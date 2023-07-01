#include <biblioteca_cpp.h>

class Animal {
  protected:
	string nome;
	int	   idade;

  public:
	Animal() {
		cout << "Animal()" << endl;
		this->nome	= "NULL";
		this->idade = 0;
	}

	Animal(string nome) {
		cout << "Animal(string nome)" << endl;
		this->nome	= nome;
		this->idade = 0;
	}

	void setNome(string nome) {
		this->nome = nome;
	}
};

class Vaca: extends Animal {
	size_t qtdLeite;

  public:
	Vaca() {
		cout << "Vaca()" << endl;
		// Animal();
		qtdLeite = 100;
	}

	Vaca(string nome) : Animal(nome) {
		cout << "Vaca()" << endl;
		// Animal();
		qtdLeite = 100;
	}

	void setNome(string nome) {
		this->nome = nome;
	}
};

int main() {

	Vaca teste, teste2("teste2");

	teste.setNome("teste");

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}