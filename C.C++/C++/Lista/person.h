#ifndef PERSON_H
#define PERSON_H

#include <biblioteca_cpp.h>
#include <list.h>

using namespace std;

class Person {
	string name;
	int age;

public:
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	Person() {
		name = "Fulano";
		age = 0;
	}

	string getName() {
		return name;
	}

	int getAge() {
		return age;
	}

	~Person() {
		cout << name << " estou indo de berço" << endl;
	}
};

shared_ptr<Person> NewPerson(string name, int age) {
	return make_shared<Person>(name, age);
}

shared_ptr<Person> NewPerson() {
	return make_shared<Person>();
}

template <>
void List<shared_ptr<Person>>::print() {
	int index = 1;

	for (int i = 0; i < size; i++) {
		cout << index++ << " ";
		cout << array[i]->getName() << " ";
		cout << array[i]->getAge() << endl;
	}
}

template <>
void List<shared_ptr<Person>>::sort() {
	for (int i = 0; i < size - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < size; j++) {
			if (array[menor]->getAge() > array[j]->getAge()) menor = j;
		}
		shared_ptr<Person> swap = array[menor];
		array[menor] = array[i];
		array[i] = swap;
	}
}

#endif