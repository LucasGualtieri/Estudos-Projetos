#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// clear && gcc userInput.c -o userInput && ./userInput

typedef char* String;

#define STR_MAX_LEN 80
#define INVALID 0

String readString(String str) {

	printf("%s", str);

	static char buffer[STR_MAX_LEN];

	fgets(buffer, STR_MAX_LEN, stdin);

	buffer[(int)strcspn(buffer, "\r\n")] = '\0';

	return buffer;
}

int readInt(String str) {

	printf("%s", str);

	int n;

	do {

		// atoi retorna INVALID se for lido um valor inválido.
		n = atoi(readString(""));

		if (n == INVALID) {
			printf("Valor inválido, tente novamente: ");
		}

	} while (n == INVALID);

	return n;
}

float readFloat(String str) {

	printf("%s", str);

	float n;

	do {

		// atof retorna INVALID se for lido um valor inválido.
		n = atof(readString(""));

		if (n == INVALID) {
			printf("Valor inválido, tente novamente: ");
		}

	} while (n == INVALID);

	return n;
}

typedef struct {
	// String nome; // Combado com o strdup somente se for haver uma rotina de close();
	char nome[STR_MAX_LEN];
	int idade;
} Pessoa;

int main() {

	int n = readInt("Digite um número inteiro: ");
	printf("n: %d\n", n);

	float f = readFloat("Digite um número real: ");
	printf("f: %f\n", f);

	Pessoa p;

	// p.lerNome("Digite seu nome: ", &p);

	strcpy(p.nome, readString("Digite seu nome: "));

	printf("p.nome: %s\n", p.nome);

	return 0;
}