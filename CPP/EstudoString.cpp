#include <biblioteca_cpp.h>

class String {
public:
	char* str = (char*)malloc(2000);
	// char* str;
	String(const char str[]) {

		int sizeOfString = 0;
		for (int i = 0; str[i]; i++) { // arg[i] != '\0'
			sizeOfString++;
		}

		cout << sizeOfString << endl;

		this->str = (char*)realloc(this->str, sizeOfString * sizeof(char));

		for (int i = 0; i < sizeOfString + 1; i++) {
			this->str[i] = str[i];
		}
	}

	String() { }

	int length() {
		int cont = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			cont++;
		}
		return cont;
	}

	char* getString() {
		return str;
	}

	friend ostream& operator<<(ostream& Cout, String& object) {
		Cout << object.str;
		return Cout;
	}

	friend istream& operator>>(istream& Cin, String& object) {
		Cin >> object.str;
		return Cin;
	}
};

int main() {

	String nome;
	nome = "Lucas Gualtieri";
	// cin >> nome; // Ainda não consegui fazer funcionar.

	cout << nome << endl;
	cout << nome.length() << endl;

	{ // Outros estudos.
		char c = '4';
		int idade = ctoi(c);
		cout << idade << endl;

		cout << Rand(4) << endl;
	}

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}