#include "biblioteca.h"

// File Get Pointer String. Equivalente a um fscanf mas para char*. Ótimo para strings em structs - fgetsptr(&string, file);
void EnemyName(char* string, FILE* file) {
	printf("string: %c\n", string);
	for (int i = 0; fgetc(file) != '"'; i++) {
		// string[i] = fgetc(file);
		printf("%c", fgetc(file));
	}
	printf("string: %c\n", string);
}

// File Get Pointer String. Equivalente a um fscanf mas para char*. Ótimo para strings em structs - fgetsptr(&string, file);
void teste(char** string, FILE* file) {
	// gets(*string);
	*string = (char*)malloc(500 * sizeof(char));
	fscanf(file, " %[^ \n]", *string);
	*string = realloc(*string, (strlen(*string) + 1) * sizeof(char));
}

int main() {
	SetConsoleOutputCP(65001);

	FILE* fileIn = fopen("in.txt", "r");

	char* string;
	int totalKills = 0;
	int totalDeaths = 0;

	char* enemyName = "\"lqk\"";
	char lastEnemy[30];

	while (!feof(fileIn)) {
		fgetsptr(&string, fileIn);
		// printf("%s\n", string);

		while (!strcmp(string, "-------------------------")) {
		}

		if (!strcmp(string, "-------------------------")) { // if string == "-------------------------"
			fgetsptr(&string, fileIn);
			fgetsptr(&string, fileIn);

			// Damage Given
			if (!strcmp(string, "Given")) { // if string == "Given"
				// Skips to enemy name.
				fgetsptr(&string, fileIn);
				fgetsptr(&string, fileIn);

				// Checks enemy name.
				if (!strcmp(string, enemyName)) { // if string == enemyName
					// printf("String: %s\n", string);
					// printf("Enemy interaction: Dmg given\n");

					// Skips to the damage given.
					fgetsptr(&string, fileIn);
					fgetsptr(&string, fileIn);

					if (atoi(string) >= 100) {
						// printf("Dmg: %d\n", atoi(string));
						// printf("Enemy killed\n");
						totalKills++;
					}
				}

				// Damage Taken
			} else if (!strcmp(string, "Taken")) {
				// Skips to enemy name.
				fgetsptr(&string, fileIn);
				EnemyName(lastEnemy, fileIn);
				// printf("enemyName: %s\n", string);

				// Checks enemy name.
				if (!strcmp(string, enemyName)) { // if string == enemyName
					// printf("String: %s\n", string);
					// printf("Enemy interaction: Dmg taken\n");

					// Skips to the damage taken.
					fgetsptr(&string, fileIn);
					fgetsptr(&string, fileIn);
					if (atoi(string) >= 100) {
						// printf("Dmg: %d\n", atoi(string));
						// printf("Died\n");
						totalDeaths++;
					}
				}
			}
		}
	}

	fclose(fileIn);

	int totalInteractions = totalKills + totalDeaths;

	printf("Total confirmed kills: %d\n", totalKills);
	printf("Total confirmed deaths: %d\n", totalDeaths);
	printf("Total interactions: %d\n", totalInteractions);

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}