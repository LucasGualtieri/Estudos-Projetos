#include <biblioteca_cpp.h>

int SizeOfStr(const char* string) {
	int length = 0;
	while (string[length++] != '\0') continue;
	return length;
}

class String {
	char* buffer;

  public:
	String(const char* str) {
		// cout << "Constructor being called" << endl;

		// Allocate memory for the new string
		this->buffer = new char[SizeOfStr(str)];

		// Copy the string
		for (int i = 0; i < SizeOfStr(str); i++) {
			buffer[i] = str[i];
		}
	}

	String() {
		this->buffer = nullptr;
		// cout << "Constructor empty param being called" << endl;
	}

	~String() {
		// cout << "Descructor being called" << endl;
		delete[] this->buffer;
	}

	int length() {
		int cont = 0;
		while (buffer[cont] != '\0') cont++;
		return cont;
	}

	// char* getString() {
	// 	return buffer;
	// }

	String& operator=(const char* str) {
		// Check for self-assignment
		if (this->buffer == str) {
			return *this;
		}

		if (buffer) {
			// Deallocate existing data if any
			delete[] this->buffer;
			// Allocate memory for the new string
			this->buffer = new char[SizeOfStr(str)];
		}

		// Copy the string
		for (int i = 0; i < SizeOfStr(str); i++) {
			buffer[i] = str[i];
		}

		return *this; // Return the assigned object
	}

	friend ostream& operator<<(ostream& Cout, String& object) {
		Cout << object.buffer;
		return Cout;
	}

	friend istream& operator>>(istream& Cin, String& object) {

		delete[] object.buffer;

		object.buffer = new char[2'000];

		Cin >> object.buffer;

		char* temp = new char[SizeOfStr(object.buffer)];

		strcpy(temp, object.buffer);

		delete[] object.buffer;

		object.buffer = temp;

		// object.buffer = getstr(stdin);
		return Cin;
	}

	char operator[](size_t index) {
		if (index >= length()) {
			throw string("Error: Index [" + to_string(index) + "] is out of bounds!");
		}

		return buffer[index];
	}

	bool operator==(String compare) {
		}
};

int main() {

	// String nome = "Lucas Gualtieri";
	String nome;
	// nome = "Lucas Gualtieri";
	cin >> nome; // Ainda não consegui fazer funcionar. // Parece que agora consegui

	cout << "Nome: " << nome << endl;
	cout << nome.length() << endl;
	nome = "Lucas Gualtieri";
	cout << nome << endl;

	cout << nome[1] << endl;
	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}