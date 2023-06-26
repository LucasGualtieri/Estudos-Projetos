#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct IntArray {
	int length;
	int* buffer;
} IntArray;

void ArrayFill(IntArray array) {
	for (int i = 0; i < array.length; i++) {
		array.buffer[i] = i + 1;
	}
}

void ArrayPrint(IntArray array) {
	printf("{ ");
	for (int i = 0; i < array.length; i++) {
		printf("%d", array.buffer[i]);
		printf("%s", i < array.length - 1 ? ", " : " }\n");
	}
}

int Soma(IntArray* array) {
	int initialLen = array->length;

	if (initialLen == 0) return array->buffer[initialLen];

	array->length--;
	int temp = array->buffer[initialLen] + Soma(array);
	array->length = initialLen;

	return temp;
}

int main() {

	IntArray array;

	array.length = 5;
	array.buffer = (int*)malloc(array.length * sizeof(array));

	ArrayFill(array);
	ArrayPrint(array);

	int soma = Soma(&array);

	printf("A soma de todos os elementos do vetor é %d\n", soma);
	printf("O tamanho do vetor é: %d\n", array.length);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}