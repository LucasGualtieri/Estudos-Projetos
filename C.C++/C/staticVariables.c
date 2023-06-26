#include <biblioteca_c.h>

int OlaMundo() {
	static int count = 0;
	puts("Olá mundo!");
	return ++count;
}

int main() {

	int count;
	for (int i = 0; i < 10; i++) {
		count = OlaMundo();
	}

	printf("Count: %d\n", count);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}