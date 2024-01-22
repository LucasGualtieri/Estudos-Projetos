#ifndef QUEUE_H
#define QUEUE_H

#include "Cell.h"

typedef struct Queue {

	int size;
	Cell *head, *tail;

	void (*Print) (struct Queue);
	// int (*CompareTo) (Cell*, Cell*);

	void (*SortedEnqueue) (Pacient, struct Queue*);
	void (*Dequeue)(struct Queue*);

	void (*Close) (struct Queue*);
} Queue;

// int CompareTo(Cell* cell1, Cell* cell2) {

// 	Pacient p1 = cell1->pacient, pivotJog = cell2->pacient;

// 	// int strComp = strcmp(jog1.estadoNascimento, pivotJog.estadoNascimento);

// 	// if (strComp == 0) {
// 	// 	log->comparacoes++;
// 	// 	strComp = strcmp(jog1.nome, pivotJog.nome);
// 	// }

// 	return strComp;
// }

void SortedEnqueue(Pacient jogador, Queue* queue) {

	// Cell* new = newCelulaDupla(jogador, NULL, NULL);
	
	// if (queue->primeiro == NULL) queue->primeiro = queue->ultimo = new;

	// else {
	// 	new->dir = queue->primeiro;
	// 	queue->primeiro = queue->primeiro->esq = new;
	// }

	queue->size++;
}

Pacient Dequeue(Queue* queue) {
	return;
}

// void MostrarListaDupla(Queue queue) {
// 	if (queue.size == 0) {
// 		errx(1, "Erro ao mostrar: Lista Dupla vazia.\n");
// 	}

// 	for (Cell* i = queue.primeiro; i != NULL; i = i->dir) {
// 		printf("[%d ## ", i->jogador.id);
// 		printf("%s ## ", i->jogador.nome);
// 		printf("%d ## ", i->jogador.altura);
// 		printf("%d ## ", i->jogador.peso);
// 		printf("%d ## ", i->jogador.anoNascimento);
// 		printf("%s ## ", i->jogador.universidade);
// 		printf("%s ## ", i->jogador.cidadeNascimento);
// 		printf("%s]\n", i->jogador.estadoNascimento);
// 	}

// }

// void CloseListaDupla(Queue* queue) {
	
// 	Cell* i = queue->primeiro;
// 	while (i != NULL) {
// 		Cell* tmp = i;
// 		i = i->dir;
// 		tmp->Close(tmp);
// 	}

// 	queue->size = 0;
// }

Queue newListaDupla() {

	Queue queue;

	queue.size = 0;
	queue.head = queue.tail = NULL;

	// queue.CompareTo = CompareToListaDupla;

	queue.SortedEnqueue = SortedEnqueue;
	queue.Dequeue = Dequeue;

	// queue.Mostrar = MostrarListaDupla;
	// queue.Close = CloseListaDupla;

	return queue;
}

#endif