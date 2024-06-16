#include <err.h>
#include "../include/lista_dupla.h"
#include "../include/celula_dupla.h"

// // ---------------------- INSERÇÃO E REMOÇÃO ----------------------

// int CompareToListaDupla(CelulaDupla* cel1, CelulaDupla* pivot) {

// 	log->comparacoes++;

// 	Cliente jog1 = cel1->cliente, pivotJog = pivot->cliente;

// 	int strComp = strcmp(jog1.estadoNascimento, pivotJog.estadoNascimento);

// 	if (strComp == 0) {
// 		log->comparacoes++;
// 		strComp = strcmp(jog1.nome, pivotJog.nome);
// 	}

// 	return strComp;
// }

// void InserirInicioListaDupla(Cliente cliente, ListaDupla* lista) {

// 	CelulaDupla* new = newCelulaDupla(cliente, NULL, NULL);
	
// 	if (lista->primeiro == NULL) lista->primeiro = lista->ultimo = new;

// 	else {
// 		new->dir = lista->primeiro;
// 		lista->primeiro = lista->primeiro->esq = new;
// 	}

// 	lista->size++;

// }

void MostrarListaDupla(ListaDupla lista) {

	if (lista.size == 0) {
		errx(1, "Erro ao mostrar: Lista Dupla vazia.\n");
	}

	for (CelulaDupla* i = lista.primeiro; i != NULL; i = i->dir) {
		// i->cliente.Mostrar(i->cliente);
		printf("Nome: %s ", i->cliente.nome);
		printf("Nome: %d ", i->cliente.dataNascimento.dia);
		printf("Nome: %s\n", i->cliente.codigo);
	}

}

// void CloseListaDupla(ListaDupla* lista) {
	
// 	CelulaDupla* i = lista->primeiro;
// 	while (i != NULL) {
// 		CelulaDupla* tmp = i;
// 		i = i->dir;
// 		tmp->Close(tmp);
// 	}

// 	lista->size = 0;
// }

void InserirFimListaDupla(Cliente cliente, ListaDupla* lista) {

	CelulaDupla* new = newCelulaDupla(cliente, NULL, NULL);
	
	if (lista->ultimo == NULL) lista->ultimo = lista->primeiro = new;

	else {
		new->esq = lista->ultimo;
		lista->ultimo = lista->ultimo->dir = new;
	}

	lista->size++;
}

ListaDupla newListaDupla() {

	ListaDupla lista;

	lista.size = 0;
	lista.primeiro = lista.ultimo = NULL;

	// lista.CompareTo = CompareToListaDupla;

	// lista.InserirInicio = InserirInicioListaDupla;
	lista.InserirFim = InserirFimListaDupla;

	lista.Mostrar = MostrarListaDupla;
	// lista.Close = CloseListaDupla;

	return lista;
}