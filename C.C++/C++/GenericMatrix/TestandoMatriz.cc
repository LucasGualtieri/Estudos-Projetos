#include <iostream>
#include <vector>
#include <sstream>
#include "Matrix.hpp"

using namespace std;

// clear && g++ TestandoMatriz.cc && ./a.out

class Classe {
	string str;
	int inteiro;
  public:
	Classe(string str, int inteiro) : str(str), inteiro(inteiro) {}

	string toString() const {
		return "{ " + str + ", " + to_string(inteiro) + " }";
	}

	friend ostream& operator<<(ostream& os, const Classe& p) {
		os << p.toString();
		return os;
	}
};

int main() {

	Matrix<Classe> m = {
		{ Classe("ABC", 1), Classe("BCD", 2) },
		{ Classe("CDE", 3), Classe("DEF", 4) },
	};

	cout << m << endl;
}