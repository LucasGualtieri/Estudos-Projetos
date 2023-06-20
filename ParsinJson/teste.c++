#include <biblioteca_cpp.h>

int main() {

	fstream json("ackbar.json");

	string teste;

	getline(json, teste);
	cout << teste << endl;
	getline(json, teste);
	cout << teste << endl;
	getline(json, teste);
	cout << teste << endl;
	getline(json, teste);
	cout << teste << endl;
	getline(json, teste);
	cout << teste << endl;

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}