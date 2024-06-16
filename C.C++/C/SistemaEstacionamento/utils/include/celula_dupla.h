#ifndef LIB_CELULA_DUPLA_H
#define LIB_CELULA_DUPLA_H

#include <stdlib.h>
#include "../../include/clientes.h"

typedef struct CelulaDupla {

	Cliente cliente;
	struct CelulaDupla *esq, *dir;
	void (*Close) (struct CelulaDupla*);

} CelulaDupla;

void CloseCelulaDupla(CelulaDupla* celula);

CelulaDupla* newCelulaDupla(Cliente cliente, CelulaDupla* esq, CelulaDupla* dir);

#endif