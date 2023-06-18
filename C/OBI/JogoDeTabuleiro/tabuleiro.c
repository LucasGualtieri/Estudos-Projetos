#include <stdio.h>

// 0 == peça branca
// 1 == peça preta
// 9 == peça vazia

int Fill(int i, int j, int N, int matriz[N][N]) {
	int soma = matriz[i][j - 1] + matriz[i - 1][j - 1] + matriz[i - 1][j];
	return soma >= 2 ? 0 : 1;
}

int main() {

	int N;

	scanf("%d", &N);

	int matriz[N][N];

	// Lendo a matriz
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &matriz[i][j]);
		}
	}

	// Preenchendo a matriz
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			matriz[i][j] = Fill(i, j, N, matriz);
		}
	}

	printf("%d\n", matriz[N - 1][N - 1]);

	return 0;
}