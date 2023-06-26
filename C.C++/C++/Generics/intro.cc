#include <biblioteca_cpp.h>

template <typename T>
void ArrayFill(T array, int arraySize) {
	int contador = 0;
	for (int i = 0; i < arraySize; i++) {
		array[i] = ++contador;
	}
}

int main() {

	int array[15];
	ArrayFill(array, 15);

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}