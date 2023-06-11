#include <biblioteca_c.h>

typedef struct Pessoa {
	char *nome, sexo;
	int idade;
} Pessoa;

char* getString(FILE* stream) {
	size_t stringLen = 80;

	char* string = (char*)malloc(stringLen * sizeof(char));

	fgets(string, stringLen, stream);

	return (char*)realloc(string, (strlen(string) + 1) * sizeof(char));
}

int main() {

	Pessoa p1;
	// p1.nome = (char*)malloc(80 * sizeof(char));

	printf("Idade: ");
	scanf("%d%*c", &p1.idade);
	// scanf("%d ", &p1.idade); // This alternative allows the next string read, but it bugs the printf "Nome: "
	// scanf("%d", &p1.idade);

	// printf("Sexo: ");
	// scanf(" %c", &p1.sexo);

	printf("Nome: ");
	// scanf(" %[^\n]", p1.nome);
	p1.nome = getString(stdin);

	printf("p1.idade: %d\n", p1.idade);
	printf("p1.nome: %s\n", p1.nome);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}