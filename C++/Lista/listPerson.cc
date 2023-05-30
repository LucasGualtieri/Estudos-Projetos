#include "person.h"
#include <biblioteca_cpp.h>
#include <list.h>

int main() {

	int size = 5;

	List<shared_ptr<Person>> people(size);
	// people.initialize(size);

	people.insertBeggining(NewPerson("Lucas", 21));
	people.insertEnd(NewPerson("Arjuna", 20));
	people.insertBeggining(NewPerson("Michael Jackson", 64));
	people.insertBeggining(NewPerson());
	people.insert(NewPerson("Gontcha", 19), 2);

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