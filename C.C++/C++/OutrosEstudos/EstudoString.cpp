#include <iostream>

using namespace std;

size_t SizeOfStr(const char* const str) {
	size_t size = 0;
	while (str[size++] != '\0') continue;
	return size;
}

void stringcopy(char* str, const char* const toBeCopied) {
	for (int i = 0; i < SizeOfStr(str); i++) {
		str[i] = toBeCopied[i];
	}
}

class String;

void stringcopy(char* str, const String& toBeCopied);

// void stringcopy(char* str, String& toBeCopied);

class String {
	char* buffer;

  public:
	String() {
		// cout << "Constructor empty param being called" << endl;
		this->buffer = nullptr;
	}

	String(const char* const str) {
		// cout << "Constructor being called" << endl;

		// Allocate memory for the new string
		this->buffer = (char*)malloc(SizeOfStr(str) * sizeof(char));

		// Copy the string
		stringcopy(buffer, str);
	}

	String(const String& str) {
		// cout << "Constructor(String& str) being called" << endl;

		// Allocate memory for the new string
		this->buffer = (char*)malloc(str.length() + 1 * sizeof(char));

		// Copy the string
		stringcopy(buffer, str);
	}

	~String() {
		// cout << "Descructor being called" << endl;
		free(this->buffer);
	}

	int length() const {
		/*
			By adding the const qualifier at the end
			of the function declaration, you indicate
			that the length() function does not modify
			the object's state and can be safely invoked
			on const objects.
		*/

		int cont = 0;
		while (buffer[cont] != '\0') cont++;
		return cont;
	}

	// char* getString() {
	// 	return buffer;
	// }

	String& operator=(const char* const str) {
		// cout << "operator=" << endl;

		// Check for self-assignment
		if (this->buffer == str) {
			cout << "Self assigment" << endl;
			return *this;
		}

		// Deallocate existing data if any
		if (buffer != nullptr) free(this->buffer);

		// Allocate memory for the new string
		this->buffer = (char*)malloc(SizeOfStr(str) * sizeof(char));

		// Copy the string
		stringcopy(buffer, str);

		return *this; // Return the assigned object
	}

	String& operator=(String& str) {
		// cout << "operator=" << endl;

		// Check for self-assignment
		// if (this->buffer == str) {
		// 	cout << "Self assigment" << endl;
		// 	return;
		// }

		// Deallocate existing data if any
		if (buffer != nullptr) free(this->buffer);

		// Allocate memory for the new string
		this->buffer = (char*)malloc(str.length() + 1 * sizeof(char));

		// Copy the string
		stringcopy(buffer, str);

		return *this; // Return the assigned object
	}

	friend ostream& operator<<(ostream& cout, String& object) {
		cout << object.buffer;
		return cout;
	}

	friend istream& operator>>(istream& cin, String& object) {

		delete[] object.buffer;

		object.buffer = new char[2'000];

		cin >> object.buffer;

		char* temp = new char[SizeOfStr(object.buffer)];

		// Copy the string
		for (int i = 0; i < SizeOfStr(object.buffer); i++) {
			temp[i] = object.buffer[i];
		}

		delete[] object.buffer;

		object.buffer = temp;

		// object.buffer = getstr(stdin);
		return cin;
	}

	char operator[](size_t index) const {
		if (index >= length()) {
			// String erro = ("Error: Index [" + to_string(index) + "] is out of bounds!");
			const char* const erro = "Error!";
			throw erro;
		}

		return buffer[index];
	}

	bool operator==(String& compare) {
		// nome1.toLowerCase();
		// nome2.toLowerCase();

		if (this->length() != compare.length()) return false;

		for (int i = 0; i < this->length(); i++) {
			if (this->buffer[i] != compare[i]) return false;
		}

		return true;
	}

	// Fazer os overloads
	String& operator+=(String& concat) {
		size_t sizeofconcat = concat.length() + 1, initialLen = this->length();

		this->buffer = (char*)realloc(buffer, initialLen + sizeofconcat);

		for (int i = 0; i <= sizeofconcat; i++) {
			this->buffer[initialLen + i] = concat[i];
		}

		return *this;
	}

	// Fazer os overloads
	String& operator+=(const char* const concat) {

		size_t sizeofconcat = SizeOfStr(concat), initialLen = this->length();

		this->buffer = (char*)realloc(buffer, initialLen + sizeofconcat);

		for (int i = 0; i <= sizeofconcat; i++) {
			this->buffer[initialLen + i] = concat[i];
		}

		return *this;
	}

	String& operator+=(char c) {

		size_t initialLen = length();

		this->buffer				 = (char*)realloc(buffer, initialLen + 1);
		this->buffer[initialLen]	 = c;
		this->buffer[initialLen + 1] = 0;

		return *this;
	}

	bool operator>(String& compare) {

		size_t shortestLen = (length() < compare.length()) ? length() : compare.length();

		for (int i = 0; i < shortestLen; i++) {
			if (buffer[i] > compare[i]) return false;
		}

		if (shortestLen != length()) return false;

		return true;
	}

	// bool operator>=(String compare);

	bool operator<(String& compare) {

		size_t shortestLen = (length() < compare.length()) ? length() : compare.length();

		for (int i = 0; i < shortestLen; i++) {
			if (buffer[i] < compare[i]) return false;
		}

		if (shortestLen != compare.length()) return false;

		return true;
	}

	// bool operator<=(String compare);
};

void stringcopy(char* str, const String& toBeCopied) {
	// cout << "stringcopy(char* str, const String& toBeCopied)" << endl;

	for (int i = 0; i < toBeCopied.length(); i++) {
		str[i] = toBeCopied[i];
	}
	str[toBeCopied.length()] = 0;
}

// void stringcopy(char* str, String& toBeCopied) {
// 	for (int i = 0; i < toBeCopied.length(); i++) {
// 		str[i] = toBeCopied[i];
// 	}
// 	str[toBeCopied.length()] = 0;
// }

template <typename T>
void insertionSort(T* array, size_t size) {

	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (array[minIndex] < array[j]) minIndex = j;
		}
		T swap			= array[minIndex];
		array[minIndex] = array[i];
		array[i]		= swap;
	}
}

template <typename T>
void SelectionSort(T* array, size_t size) {

	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (array[minIndex] < array[j]) minIndex = j;
		}
		T swap			= array[minIndex];
		array[minIndex] = array[i];
		array[i]		= swap;
	}
}

int main() {

	String vetor[3]{"ABC", "AAA", "AAAB"};

	for (int i = 0; i < 3; i++) {
		cout << vetor[i] << endl;
	}

	SelectionSort(vetor, 3);
	// insertionSort(vetor, 3);

	// MEXER NAS LOGICAS DOS OPERADORES > e <

	cout << "-----" << endl;

	for (int i = 0; i < 3; i++) {
		cout << vetor[i] << endl;
	}

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}