#include <stdio.h>

// clear && gcc teste.c && ./a.out

#define LENGTH(array) (int)(sizeof(array) / sizeof(array[0]))

// void forEach(int* array, int N, void (*function)(int)) {
// 	for (int i = 0; i < N; i++) {
// 		function(array[i]);
// 	}
// }

#define forEach(array, N, function)   \
		for (int i = 0; i < N; i++) { \
			function(array[i]);       \
		}

void printNumber(int N) {
	printf("Number: %d\n", N);
}

int fatRec(int N) {
	return N == 1 ? 1 : N * fatRec(N - 1);
}

void fat(int N) {
	printf("%d!\n", fatRec(N));
}

void Sera(int N, int M) {
	printf("N + M = %d\n", N, M, N + M);
}

void main() {
	int array[] = { 3, 4, 5, 6 };
	forEach(array, LENGTH(array), printNumber);
	forEach(array, LENGTH(array), fat);
}