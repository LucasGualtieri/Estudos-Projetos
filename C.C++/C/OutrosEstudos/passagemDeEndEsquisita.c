#include <stdio.h>

void foo(int idade[]) { // [] só pra bugar a mente, e ver que é possível
	// idade[0] = 20;
	*(idade + 0) = 20;
}

void main() {
	int idade;
	foo(&idade);
	printf("Idade: %d\n", idade);
}