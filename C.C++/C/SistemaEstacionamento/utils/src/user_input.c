#include "../include/user_input.h"

String readString(int len, String str) {

	if (len == 0) len = STR_MAX_LEN;
	if (len > STR_MAX_LEN) len = STR_MAX_LEN;

	printf("%s", str);

	static char buffer[STR_MAX_LEN];

	fgets(buffer, len, stdin);

	buffer[(int)strcspn(buffer, "\r\n")] = '\0';

	return buffer;
}

// Será que se eu lesse 1213f112 com scanf normal seria desnecessario o scanf de string?

int readInt(String str) {

	printf("%s", str);

	int n;

	do {

		// atoi retorna INVALID se for lido um valor inválido.
		n = atoi(readString(0, ""));

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
		n = atof(readString(0, ""));

		if (n == INVALID) {
			printf("Valor inválido, tente novamente: ");
		}

	} while (n == INVALID);

	return n;
}

char readChar(String str) {
	return readString(0, str)[0];
}