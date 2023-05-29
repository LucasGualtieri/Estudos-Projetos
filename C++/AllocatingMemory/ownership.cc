#include <biblioteca_cpp.h>

template <typename T>
class SmartPointer {
	T* pointer;
	int size;

public:
	SmartPointer(T* address, int size) {
		pointer = address;
		this->size = size;
	}

	// T& operator*() const {
	// 	return *pointer;
	// }

	T& operator[](int index) {
		return pointer[index];
	}

	friend ostream& operator<<(ostream& Cout, SmartPointer& object) {
		cout << "\n{ ";
		for (int i = 0; i < object.size; i++) {
			object.pointer[i] = i + 10;
			if (i < object.size - 1) {
				cout << object.pointer[i] << ", ";
			} else {
				cout << object.pointer[i] << " }";
			}
		}
		return Cout;
	}

	void realloc(unsigned int newSize) {

		T* temp = new int[newSize];

		memcpy(temp, pointer, newSize * sizeof(T)); // Copy contents from the old memory block to the new block

		delete[] pointer; // Release the old memory block

		pointer = temp;

		this->size = newSize;
	}

	~SmartPointer() {
		delete[] pointer;
	}
};

int main() {

	int size = 5;
	SmartPointer<int> array(new int[size], size);

	int i = 0;
	while (i < size) {
		array[i++] = i + 10;
	}

	cout << array << endl;

	int newSize = 10;

	array.realloc(newSize);

	while (i < newSize) {
		array[i++] = i + 10;
	}

	cout << array << endl;

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}