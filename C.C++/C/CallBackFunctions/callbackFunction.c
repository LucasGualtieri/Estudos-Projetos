#include <stdio.h>

void printMsgPt(int idade, char* nome) {
	printf("Idade: %d, ", idade);
	printf("Nome: %s\n", nome);
}

void printMsgEn(int age, char* name) {
	printf("Age: %d, ", age);
	printf("Name: %s\n", name);
}

void callsFunctions(void (*function)(int, char*)) {
	int idade = 20;
	char* nome = strdup("Lucas");
	function(idade, nome);
}

int main() {

	callsFunctions(printMsgPt);
	callsFunctions(printMsgEn);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}