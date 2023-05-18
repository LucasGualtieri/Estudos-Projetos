#include <biblioteca_c.h>

void* allocaStruct(int size) {
	return malloc(size);
}

void modificaStruct(const char* __restrict__ __format, ...) {
	printf("%s\n", __format);
	// lucas->nome = 20;
}

typedef struct Pessoa {
	char* nome;
	int idade;
} pessoa;
typedef pessoa* Pessoa;

int main() {

	Pessoa lucas = (Pessoa)allocaStruct(sizeof(Pessoa));

	lucas->nome = getstr(0);

	printf("Nome: %s\n", lucas->nome);

	modificaStruct("Alao", lucas->nome);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}