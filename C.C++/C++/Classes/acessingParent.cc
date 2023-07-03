#include <biblioteca_cpp.h>

class Animal {
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

	// ~Animal() { // Both destructors will be called
	// 	cout << "Animal sendo destruído" << endl;
	// }

	void setNome(string nome) {
		this->nome = nome;
	}

	void falar() { // Try setting it to virtual to see the different outputs
		cout << nome << ": Animal falando!" << endl;
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

	Vaca(string nome) : Animal(nome) { // Apperently this is the ONLY way to call the parent constructor
		cout << "Vaca()" << endl;
		qtdLeite = 100;
	}

	// ~Vaca() { // Both destructors will be called
	// 	cout << "Vaca sendo destruída" << endl;
	// }

	void falar() {
		cout << "Vaca falando!" << endl;
	}

	void falarBase() {
		// In case the falar from the Base / Parent class is declared as virtual
		// and there is still the need to call the parent version of the function
		// then this can can be used.
		Animal::falar();
	}
};

int main() {

	Vaca vaca;
	vaca.falar();
	vaca.setNome("Bete");

	{
		// Animal* animal = &vaca;
		// animal->falar();
		((Animal*)&vaca)->falar();
	}

	// scope resolution operator
	vaca.Animal::falar(); // When the falar function from the base class in virtual this can be used to access it

	// vaca.falarBase(); // Just a differente weird alternative

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}