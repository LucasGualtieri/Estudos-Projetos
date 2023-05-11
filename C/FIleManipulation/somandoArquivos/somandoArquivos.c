#include <biblioteca_c.h>

void fileSum(FILE* file1, FILE* file2, FILE* fileOut) {
	char buffer[50];
	bool flag = true;

	while (!feof(file1) || !feof(file2)) {
		if (flag) {
			fgets(buffer, sizeof(buffer), file1);
			fputs(buffer, fileOut);
		} else {
			fgets(buffer, sizeof(buffer), file2);
			fputs(buffer, fileOut);
		}

		if (feof(file1) && flag) {
			flag = false;
			fputs("\n", fileOut);
		}
	}
}

int main() {

	FILE* file1 = fopen("file1.txt", "r");
	FILE* file2 = fopen("file2.txt", "r");
	FILE* fileOut = fopen("soma.txt", "w");

	fileSum(file1, file2, fileOut);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}