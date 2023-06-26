#ifndef LISTA_H
#define LISTA_H

#include <string>

#include "Classes/Aluno.h"
#include "Classes/Celula.h"

using namespace std;

class Lista {
private:
	Celula* primeiro;
	Celula* ultimo;

public:
	Lista() {
		primeiro = nullptr;
		ultimo = nullptr;
	}

	void inserirInicio(Aluno* aluno) {

		Celula* temp = new Celula(aluno);

		if (this->listIsEmpty()) {
			primeiro = temp;
			ultimo = primeiro;
		} else {
			temp->proximo = primeiro;
			primeiro->anterior = temp;
			primeiro = temp;
		}
	}

	bool listIsEmpty() {
		if (primeiro == nullptr && ultimo == nullptr) return true;
		return false;
	}

	// void inserirFim(int x) {
	// 	ultimo->proximo = new Celula(x);
	// 	ultimo->proximo->anterior = ultimo;
	// 	ultimo = ultimo->proximo;
	// }

	// int removerInicio() throws Exception {
	// 	if (primeiro == ultimo) {
	// 		throw new Exception("Erro ao remover (vazia)!");
	// 	}

	// 	Celula temp = primeiro;
	// 	primeiro = primeiro->proximo;
	// 	int resp = primeiro->elemento;
	// 	temp->proximo = primeiro->anterior = nullptr;
	// 	temp = nullptr;
	// 	return resp;
	// }

	// int removerFim() throws Exception {
	// 	if (primeiro == ultimo) {
	// 		throw new Exception("Erro ao remover (vazia)!");
	// 	}
	// 	int resp = ultimo->elemento;
	// 	ultimo = ultimo->anterior;
	// 	ultimo->proximo->anterior = nullptr;
	// 	ultimo->proximo = nullptr;
	// 	return resp;
	// }

	// void inserir(int x, int pos) throws Exception {

	// 	int tamanho = tamanho();

	// 	if (pos < 0 || pos > tamanho) {
	// 		throw new Exception("Erro ao inserir posicao (" + pos + " / tamanho = " + tamanho + ") invalida!");
	// 	} else if (pos == 0) {
	// 		inserirInicio(x);
	// 	} else if (pos == tamanho) {
	// 		inserirFim(x);
	// 	} else {
	// 		// Caminhar ate a posicao anteriorerior a insercao
	// 		Celula i = primeiro;
	// 		for (int j = 0; j < pos; j++, i = i->proximo)
	// 			;

	// 		Celula temp = new Celula(x);
	// 		temp->anterior = i;
	// 		temp->proximo = i->proximo;
	// 		temp->anterior->proximo = temp->proximo->anterior = temp;
	// 		temp = i = nullptr;
	// 	}
	// }

	// int remover(int pos) throws Exception {
	// 	int resp;
	// 	int tamanho = tamanho();

	// 	if (primeiro == ultimo) {
	// 		throw new Exception("Erro ao remover (vazia)!");

	// 	} else if (pos < 0 || pos >= tamanho) {
	// 		throw new Exception("Erro ao remover (posicao " + pos + " / " + tamanho + " invalida!");
	// 	} else if (pos == 0) {
	// 		resp = removerInicio();
	// 	} else if (pos == tamanho - 1) {
	// 		resp = removerFim();
	// 	} else {
	// 		// Caminhar ate a posicao anteriorerior a insercao
	// 		Celula i = primeiro->proximo;
	// 		for (int j = 0; j < pos; j++, i = i->proximo)
	// 			;

	// 		i->anterior->proximo = i->proximo;
	// 		i->proximo->anterior = i->anterior;
	// 		resp = i->elemento;
	// 		i->proximo = i->anterior = nullptr;
	// 		i = nullptr;
	// 	}

	// 	return resp;
	// }

	// void mostrar() {
	// 	System->out->print("[ "); // Comeca a mostrar->
	// 	for (Celula i = primeiro->proximo; i != nullptr; i = i->proximo) {
	// 		System->out->print(i->elemento + " ");
	// 	}
	// 	System->out->println("] "); // Termina de mostrar->
	// }

	// void mostrarInverso() {
	// 	System->out->print("[ ");
	// 	for (Celula i = ultimo; i != primeiro; i = i->anterior) {
	// 		System->out->print(i->elemento + " ");
	// 	}
	// 	System->out->println("] "); // Termina de mostrar->
	// }

	// bool pesquisar(int x) {
	// 	bool resp = false;
	// 	for (Celula i = primeiro->proximo; i != nullptr; i = i->proximo) {
	// 		if (i->elemento == x) {
	// 			resp = true;
	// 			i = ultimo;
	// 		}
	// 	}
	// 	return resp;
	// }

	// int tamanho() {
	// 	int tamanho = 0;
	// 	for (Celula i = primeiro; i != ultimo; i = i->proximo, tamanho++) { }

	// 	return tamanho;
	// }
};

#endif