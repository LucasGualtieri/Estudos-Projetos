#include <biblioteca_c.h>

void printMsgPt(int idade, String nome) {
	printf("Idade: %d, ", idade);
	printf("Nome: %s\n", nome);
}

void printMsgEn(int age, String name) {
	printf("Age: %d, ", age);
	printf("Name: %s\n", name);
}

void callsFunctions(void (*function)(int, String)) {
	int idade = 20;
	String nome = strdup("Lucas");
	function(idade, nome);
}

int main() {

	callsFunctions(printMsgPt);
	callsFunctions(printMsgEn);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}