#include <biblioteca_cpp.h>

int main() {

	int size = 5;
	{
		int* array = new int[size] { 5, 4, 3, 2, 1 };

		int* tracker = array;

		for (int i = 0; i < size; i++) {
			cout << *tracker++ << " ";
		}
		cout << endl;
	}

	// smart pointer don't suport pointer arithmetic directly.
	// However, by using the raw pointer obtained from array.get(),
	// you can perform pointer arithmetic as needed.

	unique_ptr<int[]> array(new int[size] { 5, 4, 3, 2, 1 });
	int* tracker = array.get();

	for (int i = 0; i < size; i++) {
		cout << *tracker++ << " ";
	}

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}