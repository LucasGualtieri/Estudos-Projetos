#include <stdio.h>

// clear && gcc teste.c && ./a.out

int main() {
	FILE* file = fopen("teste.db", "rb+");

	if (file == NULL) return -1;

	// fprintf(file, "%d", 255 + 1);

	int inteiro = 1;
	int inteiro2 = 255;

	fwrite(&inteiro, sizeof(int), 2, file);

	// fseek(file, 0, 0);
	// fprintf(file, "%d", 5);
}