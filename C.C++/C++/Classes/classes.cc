#include <biblioteca_cpp.h>

class Pessoa {
	int	   idade;
	string nome;

  public:
	virtual void falar() {
		cout << "Pessoa falando" << endl;
	}
};

class Aluno: herda Pessoa {
	int matricula;

  public:
	Aluno() {
		cout << "Aluno sendo criado" << endl;
	}

	void falar() {
		cout << "Aluno falando" << endl;
	}
};

class Professor: herda Pessoa {
	string materiasQueDaAula;

  public:
	Professor() {
		cout << "Professor sendo criado" << endl;
	}

	void falar() {
		cout << "Professor falando" << endl;
	}
};

class Funcionario: herda Pessoa {
	int salario;

  public:
	Funcionario() {
		cout << "Funcionario sendo criado" << endl;
	}

	void falar() {
		cout << "Funcionario falando" << endl;
	}
};

int main() {

	int vetor[5]; // Homogêneo - TODAS posições armazenam dados do mesmo tipo

	Pessoa* vetorPessoas[10]; // Heterogêneo - Armazena Alunos e Professores

	vetorPessoas[0] = new Professor();
	vetorPessoas[1] = new Aluno();
	vetorPessoas[2] = new Funcionario();

	vetorPessoas[0]->falar(); // Professor
	vetorPessoas[1]->falar(); // Aluno
	vetorPessoas[2]->falar(); // Funcionario

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}