#include <biblioteca_c.h>

int main() {

	int sizeOfArray = 5;
	int* arrayOfIntegers = (int*)malloc(sizeOfArray * sizeof(int));

	arrayOfIntegers[0] = 1;
	arrayOfIntegers[1] = 2;
	arrayOfIntegers[2] = 3;
	arrayOfIntegers[3] = 4;
	arrayOfIntegers[4] = 5;
	arrayOfIntegers[5] = 6;
	sizeOfArray++;

	for (int i = 0; i < sizeOfArray; i++) {
		printf("Idade %d: %d\n", i + 1, arrayOfIntegers[i]);
	}

	free(arrayOfIntegers);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}