#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define STR_STD_SIZE 80
#define STR_MAX_SIZE 2000
#define LIM 2147483647
#define EOA LIM

#define isNumber(c) ('0' <= c && c <= '9')
#define ctoi(c) c - 48

char* newString(size_t maxSize) {

	if (maxSize == 0) maxSize = STR_STD_SIZE;
	char* string = (char*)malloc(maxSize * sizeof(char));
	if (!string) {
		printf("Erro ao allocar memória para string.");
		return string;
	}

	string[maxSize - 1] = 0;

	return string;
}

// Will NOT protect against bigger line reads
// than the current's strings allocated memory
char* readstr(char* string) {
	if (!fgets(string, STR_MAX_SIZE, stdin)) {
		printf("Erro ao ler a string do teclado.");
		return string;	
	}

	string[strlen(string) - 1] = 0;
	// printf("Len: %d", (int)strlen(string));

	return string;
}	

int stringToInt(char* string) {
	
	int len = strlen(string);
	int* arrayOfNumbers = (int*)malloc(len * sizeof(int));

	int i;
	for (i = 0; i < len; i++) {
		char temp = string[i];
		if (!isNumber(temp)) len = i;
		else arrayOfNumbers[i] = ctoi(temp);
	}

	arrayOfNumbers[i - 1] = EOA;

	int arrayLen = 0;
	while (arrayOfNumbers[arrayLen] != EOA) arrayLen++;
	
	int result = 0;
	for (i = 0; i < arrayLen; i++) {
		result += arrayOfNumbers[i] * (pow(10, arrayLen - i - 1));
	}

	return result;

}

int main() {

	char* stringInteiro = newString(0);
	printf("Digite um valor inteiro: ");
	stringInteiro = readstr(stringInteiro);

	int value = stringToInt(stringInteiro);

	printf("Valor convertido = %d\n", value);

}
