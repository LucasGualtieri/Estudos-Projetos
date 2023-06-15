#include <biblioteca_c.h>

void teste() {
	printf("Ola\n");
}

int main() {

	char* string = "Literal";

	int testVar = 2;
	int idade	= 1;

	if (testVar == 1) printf("Ola\n");

	printf("Idade: ");
	scanf("%d%*c", &idade);
	printf("Idade: %d\n", idade);

	Pause(0);

	printf("Ola mundo\n");

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}