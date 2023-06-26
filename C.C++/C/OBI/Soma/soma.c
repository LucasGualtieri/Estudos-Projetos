#include <stdio.h>

// By rangel and chatgpt

int main() {

	int arrayLength, sumTarget;
	scanf("%d %d", &arrayLength, &sumTarget);

	int array[arrayLength];

	for (int i = 0; i < arrayLength; i++) { scanf("%d", &array[i]); }

	int qtdRetangulos = 0;
	for (int i = 0; i < arrayLength; i++) {
		int sum = 0;
		for (int j = i; j < arrayLength; j++) {
			if ((sum += array[j]) == sumTarget) qtdRetangulos++;
		}
	}

	printf("%d", qtdRetangulos);

	return 0;
}