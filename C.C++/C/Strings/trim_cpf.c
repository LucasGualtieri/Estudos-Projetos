#include <biblioteca_c.h>

int main() {

	int idade;
	printf("Digite sua idade: ");
	scanf("%d", &idade);
	printf("Idade: %d\n", idade);

	pause(1);

	String nome = trim(readString("Digite seu nome: "));
	printf("Nome: %s\n", nome);
	printf("Length: %d\n", (int)strlen(nome));

	CPF CPFNumber = 41602264612;
	String cpf = MaskCPF(CPFNumber);

	printf("CPF: %s\n", cpf);
	printf("CPF Len: %d\n", (int)strlen(cpf));

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}