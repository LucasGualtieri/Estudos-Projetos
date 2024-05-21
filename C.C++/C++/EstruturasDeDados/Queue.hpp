#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

using namespace std;

template <typename T>
class Queue {

  private:
  public:
	class Cell {
	  private:
	  public:

		T value;
		Cell* next;

		Cell() : value(T()) {}

		Cell(T value) {
			this->value = value;
			this->next = nullptr;
		}

		// T Value() { return value; }
	};

	Cell *first, *last;
	size_t elementCount;

	Queue() : elementCount(0) {
		first = last = nullptr;
	}

	Queue(T element) : elementCount(0) {
		first = last = nullptr;
		push(element);
	}

	~Queue() {
		while (!empty()) pop();
		delete first;
	}

	size_t size() { return elementCount; }

	/**
	 * Inserts an element to the end of the Queue.
	 * 
	 * @param element item of type T.
	 * @return True if the insertion is successful, otherwise, false.
	 */
	bool push(T element) {

		Cell* newCell = new Cell(element);

		if (newCell == nullptr) return false;

		if (size() == 0) first = last = newCell;

		else last = last->next = newCell;

		elementCount++;

		return true;
	}

	// Removes the element at the first of the Queue and returns it.
	T pop() {

		if (empty()) {
			throw string("Erro ao remover: Fila Flex vazia.\n");
		}

		Cell* removedCell = first;
		first = removedCell->next;

		T removedValue = removedCell->value;
	
		elementCount--;

		delete removedCell;
		
		return removedValue;
	}

	// Returns a reference to the element at the first of the Queue without removing it.
	T& peek() { return this->first->next->value; }

	// Checks whether the Queue is empty.
	bool empty() { return size() == 0; }

};

#endif