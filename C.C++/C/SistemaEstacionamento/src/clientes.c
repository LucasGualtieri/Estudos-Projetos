#include "../include/clientes.h"
#include "../utils/include/date_utils.h"
#include "../utils/include/user_input.h"
#include "../utils/include/utils.h"
#include <stdbool.h>
#include <string.h>

void setNome(Cliente* cliente) {

	String nome = readString(50, "Digite seu nome: ");

	cliente->nome = strdup(nome);
}

void setDataNascimento(Cliente* cliente) {

	Date dataNascimento;

	int idade;

	do {

		dataNascimento = getDateInput("Digite sua data de nascimento (dd/mm/yyyy): ");\
		idade = ANO_ATUAL - dataNascimento.ano;

		if (idade < 18 || 100 < idade) {
			printf("Idade inválida, mínimo de 18 anos e máximo de 100 anos.\n");
		}

	} while (idade < 18 || 100 < idade);

	cliente->dataNascimento = dataNascimento;
}

void setCodigo(Cliente* cliente) {

	static int ID = 1;

	char c = cliente->nome[0];
	int anoNascimento = cliente->dataNascimento.ano;

	sprintf(cliente->codigo, "%c%d%02d", c, anoNascimento, ID++);
}

void setContrato(Cliente* cliente) {
	
	int escolha;

	printf("\nEscolha o tipo de contrato:\n\n");

	do {

		printf("D - Diária.\n");
		printf("P - Parcial.\n");
		printf("M - Mensal.\n\n");

		escolha = escolher("Escolha uma das opções acima: ");

		switch (escolha) {
			case 'D':
				cliente->contrato = 'D';
			break;
			case 'P':
				cliente->contrato = 'P';
			break;
			case 'M':
				cliente->contrato = 'M';
			break;
			default:
				printf("\nOpção inválida tente novamente\n\n");
			break;
		}

	} while (escolha != 'D' && escolha != 'D' && escolha != 'M');
}

void setQtdPlacas(Cliente* cliente) {}

void lerDadosCliente(Cliente* cliente) {

	cliente->setNome(cliente);
	cliente->setDataNascimento(cliente);
	cliente->setCodigo(cliente);
	cliente->setContrato(cliente);
	// cliente->setQtdPlacas(cliente);

	// printf("O nome do cliente é: %s\n", cliente->nome);
	// printf("Data de nascimento do cliente é %d/%d/%d\n",
	// cliente->dataNascimento.dia, cliente->dataNascimento.mes, cliente->dataNascimento.ano);
}

Cliente newCliente() {

	Cliente cliente;

	cliente.setNome = setNome;
	cliente.setCodigo = setCodigo;
	cliente.setDataNascimento = setDataNascimento;
	cliente.setContrato = setContrato;
	cliente.setQtdPlacas = setQtdPlacas;

	return cliente;
}