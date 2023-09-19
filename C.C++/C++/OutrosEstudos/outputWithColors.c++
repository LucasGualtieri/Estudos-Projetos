#include <iostream>

using namespace std;

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

void printColorLn(string msg, string color) {
	cout << color << msg << RESET << endl;
}

void printColor(string msg, string color) {
	cout << color << msg << RESET;
}

int main() {

	printColorLn("Olá mundo!", RED);

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}