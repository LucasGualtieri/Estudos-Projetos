#include <stdio.h>

// clear && gcc teste.c && ./a.out JOAO
// arrayStrings[0] == ./a.out
// arrayStrings[1] == JOAO
// arrayStrings[2] == 21
// argc = 3;

int main(int argc, char* argv[]) {
    // Verifica se pelo menos um argumento foi passado (o nome do programa).
    if (argc < 2) {
        printf("Uso: %s <nome>\n", argv[0]);
        return 1; // Retorna um código de erro.
    }

    // Imprime o nome passado como argumento.
    printf("Argc, %d!\n", argc);
    printf("Nome do programa, %s!\n", argv[0]);
    printf("Olá, %s!\n", argv[1]);
    printf("Idade, %s!\n", argv[2]);
	int idade;
	scanf("%d", argv[2]);
	printf("Idade: %d\n", idade);

    return 0;
}