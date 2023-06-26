#include <math.h>
#include <stdio.h>
#include <string.h>

void BinarioDecimal() {
	char binario[80];
	float soma = 0;
	int parteInteira;

	printf("\n**** Conversão para Decimal ****\n\n");
	printf("Digite um número Binário: ");
	scanf("%s", binario);

	// Essa parte do código define o tamanho da parte inteira
	for (int i = 0, j = 0; i < strlen(binario); i++) {
		if (binario[i] == '.' || binario[i] == ',') {
			parteInteira = i;
			break;
		} else {
			parteInteira = strlen(binario);
		}
	}

	for (int i = 0, j = parteInteira - 1; i < strlen(binario); i++) {
		if (binario[i] == '1') {
			soma += pow(2, j);
		}

		if (binario[i] != '.' && binario[i] != ',') j--;
	}

	printf("Decimal de %s é: %g", binario, soma);
}

void DecimalBinario() {

	int num, auxNum, printNum, size = 0;

	printf("\n**** Conversão para Binário ****\n\n");
	printf("Digite um número Natural: "), scanf("%d", &num);

	auxNum = num;
	printNum = num;

	// Setta o size da array.
	while (auxNum > 0) {
		if (auxNum % 2 == 0) {
			auxNum /= 2;
		} else {
			auxNum = (auxNum - 1) / 2;
		}
		size++;
	}

	// Escreve os valores 0 ou 1 dentro de um vetor.
	int array[size];
	for (int loop = 0; loop < size; loop++) {
		if (num % 2 == 0) {
			num /= 2;
			array[loop] = 0;
		} else {
			num = (num - 1) / 2;
			array[loop] = 1;
		}
	}

	printf("Binário de %d é: ", printNum);

	// Printa o vetor de trás pra frente;
	for (int loop = size - 1; loop >= 0; loop--) {
		printf("%d", array[loop]);
	}
}

void Conversor() {
	int metodo;
	char resposta;

	printf("Decimal -> Binário: 1\nBinário -> Decimal: 2\n");
	do {
		printf("Escolha o método: "), scanf("%d", &metodo);
	} while (metodo != 1 && metodo != 2);

	metodo == 1 ? DecimalBinario() : BinarioDecimal();

	printf("\n\n");
	do {
		printf("Converter mais um número? S ou N: "), scanf(" %c", &resposta);
	} while (resposta != 'S' && resposta != 's' && resposta != 'N' && resposta != 'n');

	printf("\n");

	if (resposta == 'S' || resposta == 's') Conversor();
}

int main() {

	Conversor();

	printf("******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}