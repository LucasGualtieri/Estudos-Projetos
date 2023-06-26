#ifndef ALUNO_H
#define ALUNO_H

#include <string>

using namespace std;

class Aluno {
private:
	string nomeSobrenome;
	int nota;

public:
	Aluno() { }

	Aluno(string nomeSobrenome, int nota) {
		this->nomeSobrenome = nomeSobrenome;
		this->nota = nota;
	}

	// Setters:
	void setNomeSobrenome(string nomeSobrenome) {
		this->nomeSobrenome = nomeSobrenome;
	}

	void setNota(string nomeSobrenome) {
		this->nomeSobrenome = nomeSobrenome;
	}

	// Getters: ---------------------------------
	string getNomeSobrenome() {
		return nomeSobrenome;
	}

	int getNota() {
		return nota;
	}
};

#endif