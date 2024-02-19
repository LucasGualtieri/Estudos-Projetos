#include <stdio.h>

// clear && gcc CallBackAndGenerics.c && ./a.out

typedef struct Objeto {
	char* nome;
	int idade;
} Objeto;

#define forEach(array, n, fn) \
	for (int i = 0; i < n; i++) fn(array[i]);

void printNumber(int n) {
	printf("Number: %d\n", n);
}

void printObjeto(Objeto o) {
	printf("Objeto.nome: %s\n", o.nome);
	printf("Objeto.idade: %d\n", o.idade);
}

void main() {
	int array1[] = { 1, 2, 3 };
	Objeto array2[] = { {"Lucas", 21}, {"Gualtieri", 22} };

	forEach(array1, 3, printNumber);
	forEach(array2, 2, printObjeto);
}