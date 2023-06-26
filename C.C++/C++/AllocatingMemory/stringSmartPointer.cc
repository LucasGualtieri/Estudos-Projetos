#include <biblioteca_cpp.h>

template <typename T>
T NewRealloc(T buffer, unsigned int newSize) {

	using U = typename std::remove_pointer<T>::type; // Remove pointer from T

	U* resizedBuffer = new U[newSize]; // Allocate a new memory block with a larger size

	memcpy(resizedBuffer, buffer, newSize * sizeof(U)); // Copy contents from the old memory block to the new block

	delete[] buffer; // Release the old memory block

	return resizedBuffer;
}

int main() {

	unique_ptr<char[]> String(new char[2000]);
	char teste[2000];

	cin >> String; // Does not work

	cout << String << endl; // Does not work

	// This might not be the correct sintax but I wanna find out if it posssible
	// to reallocate a smart pointer.

	// newPointer = move(ptr); the ownership of the dynamically allocated array is transferred

	String = NewRealloc(String, strlen(String));

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}