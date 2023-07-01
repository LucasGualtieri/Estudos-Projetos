#include <iostream>

using namespace std;

class Animal {
	static size_t contador;

  public:
	static void incrementaContador() {
		contador++;
	}

	static size_t getContador() {
		return contador;
	}

	Animal() {
		incrementaContador();
	}
};

size_t Animal::contador;

int main() {
	Animal a, b, c, d;

	Animal::incrementaContador();
	cout << Animal::getContador() << endl;

	// cout << Animal::contador << endl;
}