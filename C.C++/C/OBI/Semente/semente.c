#include <stdbool.h>
#include <stdio.h>

// Testa se a fita está preenchida / tomada pelo reagente
bool fitaPreenchida(int vetor[], int comprimento) {
	for (int i = 0; i < comprimento; i++) {
		if (vetor[i] == 0) return false;
	}
	return true;
}

int main() {

	int comprimento, qtdSementes;
	scanf("%d %d", &comprimento, &qtdSementes);

	int vetor[comprimento];

	// Preenche com 1 as posições que devem ter sementes
	for (int i = 0; i < qtdSementes; i++) {
		int posicao;
		scanf("%d", &posicao);
		vetor[posicao - 1] = 1;
	}

	// Preenche todo o resto com 0
	for (int i = 0; i < comprimento; i++) {
		if (vetor[i] != 1) vetor[i] = 0;
	}

	int dias = 0;

	// Enquanto a fita não estiver preenchida o reagente se propagará
	while (!fitaPreenchida(vetor, comprimento)) {
		for (int i = 0; i < comprimento; i++) {
			if (vetor[i] == 1) {
				// Propagando para esquerda
				if (i > 0 && vetor[i - 1] != 1) {
					vetor[i - 1] = 1;
				}
				// Propagando para direita
				if (i < comprimento - 1 && vetor[i + 1] != 1) {
					vetor[i++ + 1] = 1;
				}
			}
		}
		dias++;
	}

	printf("%d", dias);

	return 0;
}