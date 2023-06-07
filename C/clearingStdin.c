#include <biblioteca_c.h>

typedef struct Pessoa {
	char *nome, sexo;
	int idade;
} Pessoa;

int main() {

	Pessoa p1;
	// p1.nome = (char*)malloc(80 * sizeof(char));

	printf("Idade: ");
	// scanf("%d%*c", &p1.idade);
	scanf("%d", &p1.idade);

	// printf("Sexo: ");
	// scanf(" %c", &p1.sexo);

	printf("Nome: ");
	// scanf("%[^\n]", p1.nome);
	scanf(" %[^\n]", p1.nome);

	printf("p1.idade: %d\n", p1.idade);
	printf("p1.nome: %s\n", p1.nome);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}