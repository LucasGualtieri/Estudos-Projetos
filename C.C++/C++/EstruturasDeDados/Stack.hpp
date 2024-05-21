#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
class Stack {

  private:
  public:
	class Cell {
	  private:
	  public:

		T value;
		Cell* bottom;

		Cell(T value, Cell* bottom) {
			this->value = value;
			this->bottom = bottom;
		}

		// T Value() { return value; }
	};

	Cell* top;
  
	Stack() : top(nullptr) {}
	~Stack() {
		while (!empty()) pop();
	}

	/**
	 * Inserts an element to the top of the stack.
	 * 
	 * @param element item of type T.
	 * @return True if the insertion is successful, otherwise, false.
	 */
	bool push(T element) {

		Cell* newCell = new Cell(element, top);

		if (newCell == nullptr) return false;

		top = newCell;

		return true;
	}

	// Removes the element at the top of the stack and returns it.
	T pop() {

		Cell* removedCell = top;
		T removedValue = top->value;

		top = top->bottom;

		delete removedCell;

		return removedValue;
	}

	// Returns a reference to the element at the top of the stack without removing it.
	T& peek() { return this->top->value; }

	// Checks whether the stack is empty.
	bool empty() { return top == nullptr; }

};

#endif