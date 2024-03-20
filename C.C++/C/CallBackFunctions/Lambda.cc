#include <iostream>
#include <stdio.h>

// clear && g++ Lambda.cc && ./a.out

using namespace std;

typedef struct Objeto {
	string nome;
	int idade;
} Objeto;

#define forEach(array, n, fn) \
	for (int i = 0; i < n; i++) fn(array[i]);

int main() {
	int array1[] = { 1, 2, 3 };
	Objeto array2[] = { {"Lucas", 21}, {"Gualtieri", 22} };

	forEach(array1, 3, ([](int n) {
		printf("Number: %d\n", n);
	}));

	forEach(array2, 2, ([](Objeto o) {
		printf("Objeto.nome: %s\n", o.nome.c_str());
		printf("Objeto.idade: %d\n", o.idade);
	}));

	return 0;
}