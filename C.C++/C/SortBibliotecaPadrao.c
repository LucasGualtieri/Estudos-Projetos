#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// clear && gcc Teste.c && ./a.out

typedef struct Pessoa {
	char nome[50];
} Pessoa;

#define size(array) (int)(sizeof(array) / sizeof(array[0]))

int compareTo(const void* x, const void* y) {
	return strcmp(((Pessoa*)x)->nome, ((Pessoa*)y)->nome);
}

void main() {
	Pessoa array[] = {
		{"Beatriz"},
		{"Lucas"},
		{"Gabriel"},
		{"Arjuna"}
	};

	qsort(array, size(array), sizeof(array[0]), compareTo);

	for (int i = 0; i < size(array); i++) {
		printf("Nome: %s\n", array[i].nome);
	}
}