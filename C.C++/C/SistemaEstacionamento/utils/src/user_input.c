#include "../include/user_input.h"

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