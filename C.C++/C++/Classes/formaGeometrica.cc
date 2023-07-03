#include <biblioteca_cpp.h>

#define PI M_PI

class Forma {
  public:
	static int contador;

	Forma() {
		// cout << "Forma sendo criada!" << endl;
	}

	static void mostrarForma(Forma* forma) { forma->imprimir(); }

	virtual double area() { return 0; }

	virtual double perimetro() { return 0; }

	virtual void imprimir() { }
};

int Forma::contador; // Por padrão vem 0

class Circulo: extends Forma {
	int raio;

  public:
	Circulo(int raio) { this->raio = raio; }

	virtual double area() { return PI * (raio * raio); }

	virtual double perimetro() { return (2 * PI) * raio; }

	void imprimir() override {
		cout << "Círculo: Raio(" << this->raio << "): " << endl;
		cout << "Area: " << this->area();
		cout << " - Circunferência: " << this->perimetro() << endl;
		cout << endl;
	}
};

class Retangulo: extends Forma {
  protected:
	double base, altura;

  public:
	Retangulo(double base, double altura) {
		this->base	 = base;
		this->altura = altura;
	}

	double area() override {
		return base * altura;
	}

	double perimetro() {
		return (base * 2) + (altura * 2);
	}

	void imprimir() override {
		cout << "Retângulo: Base(" << this->base << ") e ";
		cout << "Altura(" << this->altura << "): " << endl;
		cout << "Area: " << this->area();
		cout << " - Perímetro: " << this->perimetro() << endl;
		cout << endl;
	}
};

class Quadrado: extends Retangulo {
  public:
	Quadrado(double lado) : Retangulo(lado, lado) { }

	void imprimir() override {
		cout << "Quadrado: Lado(" << this->base << "): " << endl;
		cout << "Area: " << this->area();
		cout << " - Perímetro: " << this->perimetro() << endl;
		cout << endl;
	}
};

// void criaForma(Forma** vetorFormas) {
// 	int base, altura;
// 	cout << "Digite a base e a altura (respectivamente): ";
// 	cin >> base >> altura;

// 	vetorFormas[Forma::contador] = new Retangulo(base, altura);
// 	Forma::contador++;
// }

int main() {

	Forma** vetorFormas = new Forma*[3];

	vetorFormas[0] = new Retangulo(5.5, 10.2);
	vetorFormas[1] = new Circulo(5);
	vetorFormas[2] = new Quadrado(7.25);

	Forma::mostrarForma(vetorFormas[0]);
	Forma::mostrarForma(vetorFormas[1]);
	Forma::mostrarForma(vetorFormas[2]);

	delete[] vetorFormas;

	cout << "------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}

// int	 vetor[3];
// int* vetorM = (int*)malloc(3 * sizeof(int));
// int* vetorN = new int[3];