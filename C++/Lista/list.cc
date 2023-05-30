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
	people.insert(new Person, 2);
	people.insertEnd(new Person("Michael Jackson", 500));

	people.print();

	people.removeBeggining();

	cout << "--------------" << endl;

	people.print();

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}