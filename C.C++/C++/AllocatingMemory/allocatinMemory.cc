#include <biblioteca_cpp.h>

class Person {
	int age;

public:
	Person(int age) {
		this->age = age;
		cout << "Hi! I've just been created and I'm " << age << " years old" << endl;
	}

	Person() {
		age = 0;
		cout << "Hi! I've just been created" << endl;
	}

	~Person() {
		if (age > 0) {
			cout << "I'm " << age << " years old! ";
		}
		cout << "See ya later alligator!" << endl;
	}
};

template <typename T>
T NewRealloc(T buffer, unsigned int newSize) {

	using U = typename remove_pointer<T>::type; // Remove pointer from T

	U* resizedBuffer = new U[newSize]; // Allocate a new memory block with a larger size

	memcpy(resizedBuffer, buffer, newSize * sizeof(U)); // Copy contents from the old memory block to the new block

	delete[] buffer; // Release the old memory block

	return resizedBuffer;
}

int main() {

	{
		// Standard variable declaration
		int integerA;

		// Malloc variable declaration
		int* integerB = (int*)malloc(sizeof(int)); // memory is allocated but not initialized.

		// 'New' variable declaration
		int* integerC = new int; // The constructor of the object is called.

		free(integerB);
		delete integerC;
	}

	{
		Person* aux;

		{
			// Standard object declaration
			Person p1; // The constructor of the object is called. When this object goes out of scope its destructor will be called
			Person p2(30); // The constructor of the object is called. When this object goes out of scope its destructor will be called

			// Malloc object declaration
			Person* p3 = (Person*)malloc(sizeof(Person)); // memory is allocated but not initialized, therefore the constructor isn't called.

			// 'New' object declaration
			Person* p4 = new Person; // The constructor of the object is called.

			// 'New' object declaration
			Person* p5 = new Person(20); // The constructor of the object is called.
			aux = p5;

			free(p3); // Because p1 has been allocated using malloc it has never been initialized, so the desctructor won't be called at all (but maybe it is possible to initialize it some how???)

			// The delete operator invokes the destructor and deallocates the memory
			// It is not possible to use the destructor to 'delete' the object, you have to do it yourself
			// It is not possible to do "delete p4, p5;"
			// Because p4 and p5 have been initialized using 'new', their destructor will only be called when you 'delete' them
			delete p4;
			// delete p5;
		}

		delete aux; // delete p5
	}

	{
		int size = 5;

		// Standard array declaration
		int arrayA[size];

		// Malloc declaration;
		int* arrayB = (int*)malloc(size * sizeof(int)); // memory is allocated but not initialized.

		// 'New' declaration
		int* arrayC = new int[size]; // The constructor of the object is called.

		arrayC = NewRealloc(arrayC, 10);

		free(arrayB);
		delete[] arrayC;
	}

	{
		// Introducing SMART POINTERS!!!
		shared_ptr<Person[]> aux;
		{
			// unique_ptr variable declaration
			unique_ptr<int> uniquePtr(new int); // Allocate memory with unique ownership
			// No need to explicitly deallocate memory
			// Memory will be automatically released when uniquePtr goes out of scope

			// unique_ptr array declaration
			int size = 5; // Optional ofcourse
			unique_ptr<int[]> array(new int[size]);

			for (int i = 0; i < size; i++) {
				array[i] = i + 1;
				cout << array[i] << " ";
			}
			cout << endl;

			// unique_ptr object declaration
			unique_ptr<Person> p1(new Person(25)); // Despite the fact that this is a pointer its destructor will be automatically called

			// unique_ptr<Person*> won't work
			shared_ptr<Person[]> arrayOfPeople(new Person[size]); // Despite the fact that this is a pointer its destructor will be automatically called when going out of scope
			aux = arrayOfPeople; // This will only work if these are shared smart pointers
		}
	} // aux going out of scope

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}

/*
	Yes, there are several differences between malloc and new, apart from the syntax. Here are some key differences:

	Syntax: The syntax is indeed different. malloc is a C library function, and it is used as follows: void* malloc(size_t size). On the other hand, new is an operator in C++ and is used with the specific type: Type* pointer = new Type;.

	Initialization: When using malloc, memory is allocated but not initialized. The allocated memory may contain garbage values. In contrast, when using new in C++, memory allocation is followed by object construction. The constructor of the object is called, and the memory is initialized.

	Type Safety: new is type-safe because it allocates memory for a specific type. The compiler ensures that the allocation and initialization are appropriate for that type. malloc, being a C function, does not have type checking, so it returns a void* pointer that needs to be explicitly cast to the appropriate type.

	Operator Overloading: new is an operator in C++, and it can be overloaded by user-defined classes to customize memory allocation behavior. malloc is a standard library function and cannot be overloaded.

	Exception Handling: new in C++ supports exception handling. If the allocation fails, it throws a std::bad_alloc exception. malloc does not throw exceptions but returns a null pointer (NULL or nullptr) if the allocation fails.

	Size Calculation: When using malloc, you need to manually calculate the size of the allocated memory in bytes. With new, the size calculation is automatically done based on the type.

	Memory Reallocations: In C++, you can use new to allocate a single object or an array, and you can use delete or delete[] to deallocate them respectively. malloc can be used to allocate a block of memory, and free must be used to deallocate it. If you need to resize the allocated memory, realloc can be used with malloc, whereas in C++, you would need to allocate a new block of memory, copy the existing elements, and deallocate the old block.

	It's worth noting that in modern C++, it is generally recommended to use the new operator and delete or smart pointers (std::unique_ptr, std::shared_ptr) instead of directly using malloc and free. new provides additional benefits in terms of type safety, exception handling, and constructor invocation, which are important in C++.
*/