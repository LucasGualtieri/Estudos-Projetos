#include <biblioteca_cpp.h>

long int LerTelefone() {
	long int telefone;
	bool loop = false;

	do {
		try {
			if (loop) {
				cout << "O valor digitado deve conter 11 dígitos\n";
			}
			cout << "Digite seu telefone: ";

			cin >> telefone;
			if (telefone == 0) throw exception();

			if (to_string(telefone).length() != 11) {
				loop = true;
				continue;
			}

			loop = false;
		} catch (...) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			loop = true;
		}
	} while (loop);

	return telefone;
}

int main() {
	cout << maskTelefone(LerTelefone());
	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}