#include <biblioteca_c.h>

void fileInsertion(const char* string, int position, const char* directory) {
	FILE* file = fopen(directory, "r");

	int sizeOfArray = 0;
	char** arrayOfLines = NULL;

	for (int i = 0; !feof(file); i++) {
		arrayOfLines = (char**)realloc(arrayOfLines, ++sizeOfArray * sizeof(char*));
		arrayOfLines[i] = getstr(file);
	}

	fclose(file);
	file = fopen(directory, "w");

	bool flag = false;
	for (int i = 0; i < sizeOfArray; i++) {
		if (i == position && !flag) {
			fprintf(file, "%s\n", string);
			i--;
			flag = true;
		} else {
			fprintf(file, "%s%s", arrayOfLines[i], i < sizeOfArray - 1 ? "\n" : "");
			free(arrayOfLines[i]);
		}
	}

	free(arrayOfLines);
	fclose(file);
}

int main() {

	const char* directory = "file.txt";

	fileInsertion("Gualtieri", 1, directory);
	fileInsertion("Firace", 2, directory);

	puts("******* | FIM DO PROGRAMA | *******\n");
	return 0;
}
