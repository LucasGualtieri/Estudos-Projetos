#include <biblioteca_cpp.h>

class String : public string {
private:
	string str;

public:
	String() { }

	String(const string& s)
		: str(s) {
	}

	String(const char* str) {
		this->str = str;
	}

	void split() {
		cout << "ls" << endl;
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

	String teste;

	teste = "Lucas";

	teste.split();

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}