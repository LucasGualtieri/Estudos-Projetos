#include <stdio.h>

#define ARRAY_PRINT(array, arrayLength, format)            \
	printf("{ ");                                          \
	for (int i = 0; i < arrayLength; i++) {                \
		printf(format, array[i]);                          \
		printf("%s", i < arrayLength - 1 ? ", " : " }\n"); \
	}

void IntArrayPrint(int* array, int arrayLength) {
	ARRAY_PRINT(array, arrayLength, "%d");
}

void FloatArrayPrint(float* array, int arrayLength) {
	ARRAY_PRINT(array, arrayLength, "%.2f");
}

#define ARRAY_FILL(array, size)      \
	int contador = 0;                \
	for (int i = 0; i < size; i++) { \
		array[i] = ++contador;       \
	}

void IntFill(int* array, int size) {
	ARRAY_FILL(array, size);
}

void FloatFill(int* array, int size) {
	ARRAY_FILL(array, size);
}

int main() {
	int intArray[15];
	int intArrayLength = sizeof(intArray) / sizeof(int);
	IntFill(intArray, intArrayLength);
	IntArrayPrint(intArray, intArrayLength);

	float floatArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	int floatArrayLength = sizeof(floatArray) / sizeof(float);
	FloatArrayPrint(floatArray, floatArrayLength);

	return 0;
}