#include <biblioteca_cpp.h>

#define rows 3
#define columns rows

void MatrixVectorFill(vector<vector<int>>& matrix) { // Has to be by reference, normally it passes just a copy
	int contador = rows * columns;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = contador--;
			// (*matrix)[i][j] = contador++; // if vector<vector<int>>* matrix and -> MatrixVectorFill(&matrix);
		}
	}
}

void MatrixVectorPrint(vector<vector<int>> matrix) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

// TEM QUE ARRUMAR PRA ORDERNAR MATRIZ
void selectionSort(vector<vector<int>>& matrix) {
	for (int i = 0; i < rows - 1; i++) {
		for (int j = 0; j < columns; j++) {
			int menor = i;
			for (int k = i + 1; k < columns; k++) {
				if (matrix[menor] > matrix[k]) menor = k;
			}
			int swap = matrix[i][menor];
			matrix[menor] = matrix[i];
			matrix[i][j] = swap;
		}
	}
}

int main() {

	vector<vector<int>> matrix(rows, vector<int>(columns));

	MatrixVectorFill(matrix);

	MatrixVectorPrint(matrix);

	selectionSort(matrix);

	cout << "-----" << endl;

	MatrixVectorPrint(matrix);

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}