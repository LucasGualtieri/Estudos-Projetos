#include <stdio.h>

void main() {
	int reps = 11, LS = 5, LI = 2;

	// 0, 1, 2, ..., LS - 1, 0, 1, ...
	for (int i = 0; i < reps; i++) {
		int resultado = i % LS;
		printf("%d %% %d = %d\n", i, LS, resultado);
	}

	printf("-----------\n");

	// 0, 1, 2, ..., LS, 0, 1, ...
	for (int i = 0; i <= reps; i++) {
		int resultado = i % (LS + 1);
		printf("%d %% (%d + 1) = %d\n", i, LS, resultado);
	}
	
	printf("-----------\n");

	// 0 + LI, 1 + LI, 2 + LI, ..., *LS + LI*, 0 + LI, 1 + LI, 2 + LI, ... 
	for (int i = 0; i <= reps; i++) {
		int resultado = (i % (LS + 1)) + LI;
		printf("(%d %% (%d + 1)) + %d = %d\n", i, LS, LI, resultado);
	}

	printf("-----------\n");

	// 0 + LI, 1 + LI, 2 + LI, ..., LS, 0 + LI, 1 + LI, 2 + LI, ... 
	for (int i = 0; i <= reps; i++) {
		int resultado = (i % ((LS + 1) - LI)) + LI;
		printf("(%d %% ((%d + 1) - %d)) + %d = %d\n", i, LS, LI, LI, resultado);
	}
}