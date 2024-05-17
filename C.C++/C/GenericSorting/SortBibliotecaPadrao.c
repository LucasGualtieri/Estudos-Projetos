#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// clear && gcc SortBibliotecaPadrao.c && ./a.out

typedef struct Pessoa {
	char nome[50];
} Pessoa;

#define size(array) (int)(sizeof(array) / sizeof(array[0]))
#define procedure void
#define deref(x) (*(Pessoa*)x)

typedef unsigned char byte;

procedure swap(void* v1, void* v2, size_t size);
void quickSortRec(int left, int right, size_t size, int (compare)(const void*, const void*), void* array);
void quickSort(void* array, size_t n, size_t size, int (compare)(const void*, const void*));

int compareTo(const void* x, const void* y) {
	return strcmp(deref(x).nome, deref(y).nome);
}

void main() {
	Pessoa array[] = {
		{"Beatriz"},
		{"Lucas"},
		{"Gabriel"},
		{"Arjuna"}
	};

	quickSort(array, size(array), sizeof(array[0]), compareTo);

	for (int i = 0; i < size(array); i++) {
		printf("Nome: %s\n", array[i].nome);
	}
}

procedure swap(void* x, void* y, size_t size) {
	void* buffer[size];
	memcpy(buffer, x, size);
	memcpy(x, y, size);
	memcpy(y, buffer, size);
}

void quickSortRec(int left, int right, size_t size, int (compare)(const void*, const void*), void* array) {
	
	int i = left, j = right;
	void* pivo = (array + ((right + left) / 2) * size);

	byte* arrayByte = (byte*) array;

	while (i <= j) {
		while (compare(&arrayByte[i * size], pivo) < 0) i++;
		while (compare(&arrayByte[j * size], pivo) > 0) j--;
		if (i <= j) swap(&arrayByte[i++ * size], &arrayByte[j-- * size], size);
	}

	if (left < j) quickSortRec(left, j, size, compare, array);
	if (i < right) quickSortRec(i, right, size, compare, array);
}

void quickSort(void* array, size_t n, size_t size, int (compare)(const void*, const void*)) {
	quickSortRec(0, n - 1, size, compare, array);
}