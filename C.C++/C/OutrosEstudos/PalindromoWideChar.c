#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

typedef wchar_t* wString;
typedef wchar_t wChar;

#define STR_MAX_TAM 80

/*
	"a�a"					- SIM
	"a��a"					- SIM
	"a�a�a"					- SIM
	"a´b´a"					- SIM
	"a´b`a"					- NAO
	"aça"					- SIM
	"açça"					- SIM
	"açaça"					- SIM
	"açéa"					- NAO
	"açéaaéça"				- SIM
	"açéaéça"				- SIM
	"marrocos - socorram" 	- SIM
*/

// bool isPalindromo(wString string) {
// 	bool result = true;
// 	int len = wcslen(string) - 1;
// 	for (int i = 0; i < len; i++) {
// 		if (string[i] != string[len - i]) {
// 			i = len;
// 			result = false;
// 		}
// 	}
// 	return result;
// }

bool isPalindromoRec(int left, int right, wString string) {
	if (left < right) {
		if (string[left++] == string[right--]) {
			return isPalindromoRec(left + 1, right - 1, string);
		} else {
			return false;
		}
	}
	return true;
}

bool isPalindromo(wString string) {
	return isPalindromoRec(0, wcslen(string) - 1, string);
}

int main() {

	wString string = (wString)malloc(STR_MAX_TAM * sizeof(wChar));
	fgetws(string, STR_MAX_TAM, stdin);
	string[wcslen(string) - 1] = '\0';

	printf("%s\n", isPalindromo(string) ? "É palindromo" : "Não é palindromo");

	free(string);

	return 0;
}
