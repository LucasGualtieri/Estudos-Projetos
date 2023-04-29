#include <biblioteca_c.h>

int main() {

	int idade;
	scanf("%d", &idade);
	printf("Idade: %d\n", idade);

	String nome = getstr(0);
	nome = substr(nome, 0, indexOf(nome, " "));
	printf("Nome: %s\n", nome);
	printf("Length: %d\n", (int)strlen(nome));

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}