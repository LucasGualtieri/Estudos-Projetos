#include <biblioteca_cpp.h>
#include <list.h>

int main() {

	int size = 5;

	List<int> integers(size);

	integers.insertBeggining(1);
	integers.insertBeggining(2);
	integers.insertBeggining(3);
	integers.insertEnd(4);
	integers.insert(5, 2);

	integers.print();

	integers.removeBeggining();

	integers.print();

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}