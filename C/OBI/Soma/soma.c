#include <stdio.h>

// By rangel and chatgpt

int main() {
	int arrayLength, sumTarget;

	// printf("Digite o numero de quadrados que deseja: ");
	scanf("%d", &arrayLength);

	// printf("Digite o valor de soma desejado pra formar um retangulo: ");
	scanf("%d", &sumTarget);

	int array[arrayLength];

	for (int i = 0; i < arrayLength; i++) {
		// printf("Digite o numero do quadrado %d: ", i + 1);
		scanf("%d", &array[i]);
	}

	int qtdRetangulos = 0;

	for (int i = 0; i < arrayLength; i++) {
		int sum = 0;
		for (int j = i; j < arrayLength; j++) {
			sum += array[j];
			if (sum == sumTarget) qtdRetangulos++;
		}
	}

	printf("Numero de retangulos formados: %d\n\n", qtdRetangulos);

	return 0;
}