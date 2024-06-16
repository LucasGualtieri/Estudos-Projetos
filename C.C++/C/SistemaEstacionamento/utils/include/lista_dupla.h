#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

#include "celula_dupla.h"

typedef struct ListaDupla {

	int size;
	CelulaDupla *primeiro, *ultimo;

	void (*Mostrar) (struct ListaDupla);
	int (*CompareTo) (CelulaDupla* jog1, CelulaDupla* jog2);
	void (*InserirInicio) (Cliente, struct ListaDupla*);
	void (*InserirFim) (Cliente, struct ListaDupla*);
	void (*Close) (struct ListaDupla*);

} ListaDupla;

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

ListaDupla newListaDupla();
int CompareToListaDupla(CelulaDupla* cel1, CelulaDupla* pivot);
void InserirInicioListaDupla(Cliente cliente, ListaDupla* lista);
void InserirFimListaDupla(Cliente cliente, ListaDupla* lista);
void MostrarListaDupla(ListaDupla lista);
void CloseListaDupla(ListaDupla* lista);


#endif