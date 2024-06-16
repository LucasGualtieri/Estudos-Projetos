#include <stdio.h>
#include "../include/clientes.h"
#include "../utils/include/lista.h"
#include "../utils/include/lista_dupla.h"
#include "../utils/include/user_input.h"
#include "../utils/include/utils.h"

// make && clear && ./bin/SistemaEstacionamento

void cadastrarCliente(ListaDupla* clientes) {

	clearscreen();

	printf("Cadastrando dados do cliente:\n\n");

	Cliente cliente = newCliente();

	lerDadosCliente(&cliente);

	clientes->InserirFim(cliente, clientes);

	clearscreen();
	printf("Cadastro concluído com sucesso!\n\n");

}

void Inserir(ListaDupla* clientes) {

	clearscreen();

	int escolha;

	do {

		printf("A - Inserção de cliente.\n");
		printf("B - Inserção de placa\n");
		printf("C - Voltar.\n\n");

		escolha = escolher("Escolha uma das opções acima: ");

		switch (escolha) {
			case 'A':
				cadastrarCliente(clientes);
			break;
			case 'B':
				// Excluir
			break;
			case 'C':
				clearscreen();
			break;
		}

	} while (escolha != 'C');
}

void Excluir(/* ListaDupla* clientes */) {

}

void Relatorio(ListaDupla clientes) {
	clearscreen();
	printf("Relatório:\n");
	clientes.Mostrar(clientes);
}

int main() {

	ListaDupla clientes = newListaDupla();

	int escolha;

	do {

		printf("A - Inserir (Clientes e Placas).\n");
		printf("B - Excluir (Clientes e Placas).\n");
		printf("C - Relatórios.\n");
		printf("D - Sair do programa.\n\n");

		escolha = escolher("Escolha uma das opções acima: ");

		switch (escolha) {
			case 'A':
				Inserir(&clientes);
			break;
			case 'B':
				// Excluir
			break;
			case 'C':
				Relatorio(clientes);
			break;
		}

	} while (escolha != 'D');

	return 0;
}