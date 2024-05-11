#include <iostream>
#include <vector>
#include <sstream>
#include "Matrix.hpp"

using namespace std;

// clear && g++ Islands.cc && ./a.out

template <typename T>
void registerIsland(int i, int j, T& matrix) {
	if (matrix.inBounds(i, j) && matrix[i][j] == '*') {
		matrix[i][j] = '-';
		registerIsland(i + 1, j, matrix);
		registerIsland(i - 1, j, matrix);
		registerIsland(i, j + 1, matrix);
		registerIsland(i, j - 1, matrix);
	}
}

template <typename T>
int islandCounter(T matrix) {

	int counter = 0;

	for (int i = 0; i < matrix.height; i++) {
		for (int j = 0; j < matrix.width; j++) {
			if (matrix[i][j] == '*') {
				counter++;
				registerIsland(i, j, matrix);
			}
		}
	}

	return counter;
}

int main() {

	Matrix<char> m = {
		{ '*', '*', '-', '-', '-', '-' },
		{ '*', '*', '-', '-', '-', '-' },
		{ '-', '-', '-', '-', '-', '-' },
		{ '-', '-', '-', '-', '-', '-' },
		{ '-', '*', '-', '-', '*', '*' },
		{ '-', '-', '-', '-', '*', '*' },
	};

	cout << m << endl;
	cout << "There are " << islandCounter(m) << " islands." << endl;
}