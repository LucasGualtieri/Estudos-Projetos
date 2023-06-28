#include <biblioteca_cpp.h>

class Animal {
  public:
	int	   idade;
	string nome;
};

class Vaca: herda Animal {
	int qtdLeite;
};

int main() {

	Vaca vaca;

	vaca.idade;
	vaca.nome;

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}