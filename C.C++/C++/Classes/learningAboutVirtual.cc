#include <biblioteca_cpp.h>

class Funcionario {
  protected:
	int salario;
	int saldo;

  public:
	Funcionario() {
		salario = 1'200;
		saldo	= 0;
	}

	Funcionario(int salario) {
		this->salario = salario;
		saldo		  = 0;
	}

	virtual void recebeSalario() {
		saldo += salario;
	}

	int getSaldo() {
		return saldo;
	}
};

class Gerente: herda Funcionario {
	int bonus;

  public:
	Gerente(int salario, int bonus) {
		this->salario = salario;
		this->bonus	  = bonus;
		saldo		  = 0;
	}

	void recebeSalario() override {
		saldo += salario + bonus;
	}
};

int main() {

	Funcionario* vetorFuncionarios[2];

	vetorFuncionarios[0] = new Funcionario(1'200);
	vetorFuncionarios[1] = new Gerente(3'000, 50);

	vetorFuncionarios[0]->recebeSalario(); // Funcionario normal
	vetorFuncionarios[1]->recebeSalario(); // Funcionario Gerente

	cout << vetorFuncionarios[0]->getSaldo() << endl; // 1200
	cout << vetorFuncionarios[1]->getSaldo() << endl; // 3050

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}

// Funcionario f1(1'200); // Saldo = 0

// f1.recebeSalario();

// cout << f1.getSaldo() << endl;

// Gerente g1(3'000, 50); // Saldo = 0

// g1.recebeSalario();
// cout << g1.getSaldo() << endl;