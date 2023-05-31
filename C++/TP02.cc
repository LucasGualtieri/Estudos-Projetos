#include <biblioteca_cpp.h>
#include <list.h>
// #include <personagem.h>
#include <split.h>

void Insertremove(string nome) {

	split array(nome, " ");

	cout << array[0] << endl;
	cout << array[1] << endl;
}

// Tacar pra dentro do personagens.h?
string getString() {
	string aux;
	getline(cin, aux);
	return aux;
}

int main() {

	// List<shared_ptr<Personagem>> list(80);

	// ReadData(list);

	string listActions = getString();

	// while ((listActions = getString()).compare("FIM")) {
	while (listActions.compare("FIM")) {
		Insertremove(listActions);
		listActions = getString();
	}

	// list.print();

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}