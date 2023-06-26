#include <biblioteca_cpp.h>

// Selection Sort para Inteiros em ordem Crescente
void selectionSort(int* array, int arrayLength) {
	for (int i = 0; i < arrayLength - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < arrayLength; j++) {
			if (array[menor] > array[j]) menor = j;
		}
		int swap = array[menor];
		array[menor] = array[i];
		array[i] = swap;
	}
}

void ArrayFillNew(int* array, int size) {
	for (int i = 0, j = size; i < size; i++) {
		array[i] = j--;
	}
}

void ArrayPrintNew(int* array, int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int main() {

	int size = 5;
	unique_ptr<int[]> array(new int[size]);

	ArrayFillNew(array.get(), size);

	ArrayPrintNew(array.get(), size);

	selectionSort(array.get(), size);

	ArrayPrintNew(array.get(), size);

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}