#include <biblioteca_cpp.h>

// https://stackoverflow.com/questions/33706528/is-it-safe-to-realloc-memory-allocated-with-new
// ^^ basically says that it's probably not safe, BUT in my use it doesn't really matter.

int main() {

	int* array = new int[5];

	for (int i = 0; i < 5; i++) { array[i] = i + 1; }

	array = (int*)realloc(array, 10 * sizeof(int));

	for (int i = 5; i < 10; i++) { array[i] = i + 1; }

	for (int i = 0; i < 10; i++) { cout << array[i] << endl; }

	free(array);

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}