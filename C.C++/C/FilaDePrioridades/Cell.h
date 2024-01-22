#ifndef CELL_H
#define CELL_H

#include "Pacient.h"

typedef struct Cell {
	Pacient pacient;
	struct Cell *prev, *next;
	void (*Close) (struct Cell*);
} Cell;

// void CloseCelulaDupla(Cell* celula) {
// 	celula->pacient.Close(celula->pacient);
// 	free(celula);
// }

// Cell* newCelulaDupla(Pacient pacient, Cell* prev, Cell* next) {
// 	Cell* celula = malloc(sizeof(Cell));

// 	celula->pacient = pacient.Clone(pacient);
// 	celula->prev = prev;
// 	celula->next = next;
// 	celula->Close = CloseCelulaDupla;

// 	return celula;
// }

#endif