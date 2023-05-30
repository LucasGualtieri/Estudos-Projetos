#include "person.h"
#include <biblioteca_cpp.h>
#include <list.h>

int main() {

	int size = 5;

	List<shared_ptr<Person>> people;
	people.initialize(size);

	// Aqui estamos tendo vazamentos de memória!
	// Quero usar shared pointers pra não ter que me preocupar
	// com a liberação da memória

	people.insertBeggining(NewPerson("Lucas", 21));
	people.insertEnd(NewPerson("Arjuna", 20));
	people.insertBeggining(NewPerson("Michael Jackson", 500));
	people.insertBeggining(NewPerson("Gontcha", 19));
	people.insert(NewPerson(), 2);

	people.print();

	people.removeBeggining();

	cout << "--------------" << endl;

	people.print();

	cout << "--------------" << endl;
	people.sort();

	people.print();

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}