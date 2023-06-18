#include <biblioteca_c.h>

int main() {

	FILE* file = fopen("teste.txt", "r");

	char string[50];

	// The value returned by fgetc and similar functions to indicate the end of the file.
	printf("EOF: %d\n", EOF); // EOF expands to -1

	// while (fscanf(file, "%[^\r]", string) > 0) // Provavelmente poderia dar merda em algum caso
	// while (fscanf(file, "%[^\r]", string) != -1)
	// while (fscanf(file, "%[^\r]", string) >= 0)
	while (fscanf(file, "%[^\r]", string) != EOF) { // Fscanf returns the quantity of items read
		printf("%s\n", string);
	}

	fclose(file);

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}