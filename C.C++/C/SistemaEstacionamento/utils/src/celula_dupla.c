#include "../include/celula_dupla.h"

void CloseCelulaDupla(CelulaDupla* celula) {
	// celula->cliente.Close(celula->cliente);
	// free(celula);
}

CelulaDupla* newCelulaDupla(Cliente cliente, CelulaDupla* esq, CelulaDupla* dir) {

	CelulaDupla* celula = malloc(sizeof(CelulaDupla));

	celula->cliente = cliente;
	celula->esq = esq;
	celula->dir = dir;
	// celula->close = CloseCelulaDupla;

	return celula;
}