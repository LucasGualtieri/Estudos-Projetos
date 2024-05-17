#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// clear && gcc GenericSorting.c && ./a.out

/*
	5
	Lucas S 1
	Arjuna N 1
	Igor O 3
	Gontcha O 3
	Gustavin L 3
*/

#define procedure void
#define deref(x) (*(Aluno*)x)

typedef unsigned char byte;

typedef struct Aluno {
	char nome[20];
	char regiao;
	int custo;
} Aluno;

procedure swap(void* v1, void* v2, size_t size);
procedure selectionSort(void*, size_t, size_t, int (compare)(const void*, const void*));
void quickSortRec(int left, int right, size_t size, int (compare)(const void*, const void*), void* array);
void quickSortRecAlternate(int left, int right, size_t size, int (compare)(const void*, const void*), void* array);
void quickSort(void* array, size_t n, size_t size, int (compare)(const void*, const void*));

Aluno* montarArray(int n) {

	Aluno* alunos = (Aluno*)malloc(n * sizeof(Aluno));

	for (size_t i = 0; i < n; i++) {
		Aluno a;
		scanf("%s %c %i", a.nome, &a.regiao, &a.custo);
		alunos[i] = a;
	}

	return alunos;
}

int compareTo(const void* x, const void* y) { // return 0, 1 ou -1

	Aluno a1 = deref(x), a2 = deref(y);

	int resp = a1.custo - a2.custo;
	if (resp == 0) resp = a1.regiao - a2.regiao;
	if (resp == 0) resp = strcmp(a1.nome, a2.nome);

	return resp;
}

char* toString(const void* obj) {

	Aluno a1 = deref(obj);

	static char string[500];

	strcpy(string, a1.nome);

	return string;
}

procedure arrayPrint(void* array, size_t n, size_t size, char* (toString)(const void*)) {
	for (int i = 0; i < n; i++) {
		printf("%s\n", toString(array + i * size));
	}
}

int main() {

	int n = 0;

	scanf("%d", &n);
	Aluno* alunos = montarArray(n);

	qsort(alunos, n, sizeof(Aluno), compareTo);
	// selectionSort(alunos, n, sizeof(Aluno), compareTo);
	// quickSort(alunos, n, sizeof(Aluno), compareTo);
	arrayPrint(alunos, n, sizeof(Aluno), toString);
}

procedure swap(void* v1, void* v2, size_t size) {
	void* buffer[size];
	memcpy(buffer, v1, size);
	memcpy(v1, v2, size);
	memcpy(v2, buffer, size);
}

procedure selectionSort(void* array, size_t n, size_t size, int (compare)(const void*, const void*)) {

	byte* arrayByte = (byte*) array;

	for (int i = 0; i < n - 1; i++) {

		int menor = i;

		for (int j = i + 1; j < n; j++) {
			if (compare(&arrayByte[j * size], &arrayByte[menor * size]) < 0) {
				menor = j;
			}
		}

		swap(&arrayByte[i * size], &arrayByte[menor * size], size);
	}
}

procedure selectionSortAlternate(void* array, size_t n, size_t size, int (compare)(const void*, const void*)) {

	for (int i = 0; i < n - 1; i++) {

		int menor = i;

		for (int j = i + 1; j < n; j++) {
			if (compare(array + j * size, array + menor * size) < 0) {
				menor = j;
			}
		}

		swap(array + i * size, array + menor * size, size);
	}
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

void quickSortRecAlternate(int left, int right, size_t size, int (compare)(const void*, const void*), void* array) {
	
	int i = left, j = right;
	void* pivo = (array + ((right + left) / 2) * size);

	while (i <= j) {
		while (compare(array + i * size, pivo) < 0) i++;
		while (compare(array + j * size, pivo) > 0) j--;
		if (i <= j) {
			swap(array + i * size, array + j * size, size);
			i++; j--;
		}
	}

	if (left < j) quickSortRec(left, j, size, compare, array);
	if (i < right) quickSortRec(i, right, size, compare, array);
}

void quickSort(void* array, size_t n, size_t size, int (compare)(const void*, const void*)) {
	quickSortRec(0, n - 1, size, compare, array);
}