#include <biblioteca_c.h>

int main() {

	int idade;
	scanf("%d", &idade);
	printf("Idade: %d\n", idade);

	String nome = getstr(0);
	nome = substr(nome, 0, indexOf(nome, " "));
	printf("Nome: %s\n", nome);
	printf("Length: %d\n", (int)strlen(nome));

	unsigned long CPFNumber = 13605269605;
	String CPF = MaskCPF(CPFNumber);

	printf("CPF: %s\n", CPF);
	printf("CPF Len: %d\n", (int)strlen(CPF));

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}