#include <iostream>

// clear && g++ Teste.cc && ./a.out

using namespace std;

int main() {

	int array[] = {1,2,3};

	auto [x, y, z] = array;

	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
}