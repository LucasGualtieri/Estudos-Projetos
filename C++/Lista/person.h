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
		cout << array.get()[i]->nome << " ";
		cout << array.get()[i]->idade << endl;
	}
}

template <>
void List<Person*>::sort() {
	for (int i = 0; i < size - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < size; j++) {
			if (array[menor]->idade > array[j]->idade) menor = j;
		}
		Person* swap = array[menor];
		array[menor] = array[i];
		array[i] = swap;
	}
}

#endif