#ifndef PERSON_H
#define PERSON_H

#include <biblioteca_cpp.h>
#include <list.h>

using namespace std;

class Person {
public:
	string nome;
	int idade;

	Person(string nome, int idade) {
		this->nome = nome;
		this->idade = idade;
	}
	Person() {
		nome = "Fulano";
		idade = 0;
	}
};

template <>
void List<Person*>::print() {
	int index = 1;

	for (int i = 0; i < size; i++) {
		cout << index++ << " ";
		cout << array[i]->nome << " ";
		cout << array[i]->idade << endl;
	}
}

template <>
void List<Person*>::FullFree() {
	for (int i = 0; i < size; i++) {
		delete array[i];
	}
	delete[] array;
}

#endif