#include <biblioteca_c.h>

int main() {

	String nome = "Lucas Gualtieri";

	nome = substr(nome, indexOf(nome, "u", 2), ends);

	printf("Nome: %s\n", nome);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}