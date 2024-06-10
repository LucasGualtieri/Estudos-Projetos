#include <iostream>
#include "Matrix.hpp"

using namespace std;

// clear && g++ Islands.cc && ./a.out

template <typename T, typename K>
void registerIsland(int i, int j, K land, K water, T& matrix) {
	if (matrix.inBounds(i, j) && matrix[i][j] == land) {
		matrix[i][j] = water;
		registerIsland(i + 1, j, land, water, matrix);
		registerIsland(i - 1, j, land, water, matrix);
		registerIsland(i, j + 1, land, water, matrix);
		registerIsland(i, j - 1, land, water, matrix);
	}
}

template <typename T, typename K>
int islandCounter(T matrix, K land, K water) {

	int counter = 0;

	for (int i = 0; i < matrix.height; i++) {
		for (int j = 0; j < matrix.width; j++) {
			if (matrix[i][j] == land) {
				counter++;
				registerIsland(i, j, land, water, matrix);
			}
		}
	}

	return counter;
}

int main() {

	Matrix<int> m = {
		{ 1, 1, 0, 0, 0, 0 },
		{ 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 1, 1 },
	};

	cout << m << endl;
	cout << "There are " << islandCounter(m, 1, 0) << " islands." << endl;
}