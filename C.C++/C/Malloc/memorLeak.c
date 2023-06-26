#include <biblioteca_c.h>

int main() {
	printf("Ola\n");

	int* gigachad = (int*)malloc(1000000000 * sizeof(int));

	int i = 0;
	while (1) {
		gigachad[i] = ++i;
		sleep(5);
	}

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}