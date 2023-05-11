#include <biblioteca_c.h>

void fileConcat(FILE* fileIn, FILE* fileOut) {

	String buffer;

	while (!feof(fileIn)) {
		buffer = getstr(fileIn);
		fputs("\n", fileOut);
		fputs(buffer, fileOut);
		free(buffer);
	}
}

int main() {

	FILE* fileIn = fopen("file2.txt", "r"); // Arquivo cujo os dados serão concatenados no fileOut
	FILE* fileOut = fopen("file1.txt", "a"); // Arquivo que receberá os dados do fileIn

	fileConcat(fileIn, fileOut);

	fclose(fileOut);
	fclose(fileIn);

	puts("******* | FIM DO PROGRAMA | *******\n");
	return 0;
}
