#include <biblioteca_c.h>

void ListaDeConfirmacao(FILE* listaIn, FILE* listaOut) {
	String string = (char*)malloc(2000 * sizeof(char));

	fscanf(listaIn, "%[^:]", string);

	fprintf(listaOut, "%s:\n\n", string);
	printf("%s:\n", string);

	free(string);
}

String NomeDoJogador(FILE* listaIn) {

	String jogador = (String)malloc(2000 * sizeof(char));

	bool readAgain = true;
	while (readAgain) {
		fscanf(listaIn, "%s", jogador);
		for (int i = 0; jogador[i] != '\0'; i++) {
			if (strchr("aeiouAEIOU", jogador[i]) != NULL) {
				readAgain = false;
			}
		}
	}

	// printf("Jogador: %s\n", jogador);

	int indexOfParen;
	if ((indexOfParen = indexOf(jogador, ")", 1)) != -1) {
		// printf("indexOfParen: %d\n", indexOfParen);
		strcpy(jogador, substr(jogador, indexOfParen + 1, ends));
	}

	// pause(0);
	return (char*)realloc(jogador, SizeOfStr(jogador) * sizeof(char));
}

int main() {

	FILE* listaIn = fopen("lista.in", "r");
	FILE* listaOut = fopen("lista.out", "w");

	ListaDeConfirmacao(listaIn, listaOut);

	int contador = 0;
	while (!feof(listaIn)) {
		char* jogador = NomeDoJogador(listaIn);
		fprintf(listaOut, "%d) %s", ++contador, jogador);
		printf("%d) %s", contador, jogador);
		if (!feof(listaIn)) {
			fprintf(listaOut, "\n");
			printf("\n");
		}
		free(jogador);
	}

	fclose(listaIn);
	fclose(listaOut);

	puts("\n\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}