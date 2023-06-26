#include <stdbool.h>
#include <stdio.h>

bool contem(int peca, int vetor[], int N) {
	for (int i = 0; i < N; i++) {
		if (vetor[i] == peca) return true;
	}
	return false;
}

int main() {

	int N;

	scanf("%d", &N);

	int vetorCompleto[N], vetorFaltante[N - 1];

	// Preenchendo o vetorCompleto com os valores de 1 até N: 1, 2, ..., N;
	for (int i = 0; i < N; i++) {
		vetorCompleto[i] = i + 1;
	}

	// Preenchendo o vetorFaltante
	for (int i = 0; i < N - 1; i++) {
		int peca;
		scanf("%d", &peca);
		vetorFaltante[i] = peca;
	}

	// Flag opcional
	bool achou = false;

	// Descobrindo a peça faltante
	for (int i = 0; !achou && i < N; i++) {
		if ((achou = !contem(vetorCompleto[i], vetorFaltante, N - 1))) {
			printf("%d\n", vetorCompleto[i]);
		}
	}

	return 0;
}