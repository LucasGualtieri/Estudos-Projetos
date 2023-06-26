#ifndef CELULA_H
#define CELULA_H

#include <string>

#include "Classes/Aluno.h"

using namespace std;

class Celula {
public:
	Aluno aluno;
	Celula* anterior;
	Celula* proximo;

	Celula() {
		this->anterior = nullptr;
		this->proximo = nullptr;
	}

	Celula(Aluno aluno) {
		this->aluno = aluno;
		this->anterior = nullptr;
		this->proximo = nullptr;
	}
};

#endif