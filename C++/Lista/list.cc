#include "person.h"
#include <biblioteca_cpp.h>
#include <list.h>

int main() {

	int size = 5;

	// List<int> integers(new int[size], size);
	List<Person*> people;
	people.initialize(size);

	people.insertBeggining(new Person("Lucas", 21));
	people.insertBeggining(new Person("Arjuna", 20));
	people.insertBeggining(new Person("Gontcha", 19));
	people.insertEnd(new Person);
	people.insert(new Person("Michael Jackson", 500), 2);

	people.print();

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}