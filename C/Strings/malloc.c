#include <biblioteca_c.h>

int main() {

	{
		String nome = (String)malloc(5 * sizeof(char));
		free(nome); // To avoid momory leak.

		nome = "Lucas";

		printf("Sizeof(\"Lucas\"): %d\n", (int)sizeof("Lucas"));
		printf("Nome: %s\n", nome);
	}

	String nome = (String)malloc(5 * sizeof(char));

	*(nome) = 'L';
	nome[1] = 'u';
	*(nome + 2) = 'c';
	nome[3] = 'a';
	nome[4] = 's';
	nome[5] = 'G';
	nome[6] = 'u';
	nome[7] = 'a';

	printf("Nome: %s\n", nome);

	snprintf(nome, 6, "Lucas");

	printf("Nome: %s\n", nome);

	strncpy(nome, "Lucas Gualtieri", 16); // Esse da um erro!

	printf("Nome: %s\n", nome);

	free(nome);

	nome = getstr(0);
	strncpy(nome, "Lucas Gualtieri", 16);

	printf("Nome: %s\n", nome);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}

/*
	The line nome = "Lucas" overwrites the
	value of nome, causing a memory leak
	because the previously allocated memory
	is no longer accessible.
	This line assigns the address of the string
	literal "Lucas" to the nome pointer, which
	is a valid operation since string literals
	are stored in read-only memory and have a
	fixed size.
*/