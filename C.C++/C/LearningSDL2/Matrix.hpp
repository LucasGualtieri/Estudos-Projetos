#ifndef MATRIX
#define MATRIX

#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

template <typename T>
class Matrix {
	vector<vector<T>> matrix;
  public:

	const int height, width;

	Matrix(int height, int width) : height(height), width(width) {

		matrix.reserve(height); // Optionally reserve memory for efficiency

		for (int i = 0; i < height; i++) {
			vector<T> row(width);
			matrix.push_back(row);
		}
	}

	Matrix(initializer_list<initializer_list<T>> list) : height(list.size()), width(list.begin()->size()) {
		
		matrix.reserve(height); // Optionally reserve memory for efficiency

		for (auto row : list) {
			matrix.push_back(row);
		}
	}

	bool inBounds(int i, int j) {
		return 0 <= i && i < height && 0 <= j && j < width;
	}

	vector<T>& operator[](int i) {

		ostringstream oss;
		oss << "Erro ao indexar: " << i << endl;

		if (i < 0 || height <= i) throw string(oss.str());

		return matrix[i];
	}

	string toString() const {
		ostringstream oss;
		int colWidth = 0;

		// First pass: Determine the width needed for each column
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				ostringstream temp;
				temp << matrix[i][j];
				colWidth = max(colWidth, static_cast<int>(temp.str().length()));
			}
		}

		// Second pass: Generate the string with alignment
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				oss << setw(colWidth) << matrix[i][j];
				if (j < width - 1) oss << " ";
			}
			oss << '\n';
		}

		return oss.str();
	}

	string toString(bool flag) const {
		ostringstream oss;
		int colWidth = 0;

		// First pass: Determine the width needed for each column
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				ostringstream temp;
				if (matrix[i][j] > 10) temp << (matrix[i][j] / 10);
				else if (abs(matrix[i][j]) >= 100) temp << (matrix[i][j] / 100);
				else temp << matrix[i][j];
				colWidth = max(colWidth, static_cast<int>(temp.str().length()));
			}
		}

		oss << " ";

		for (int i = 0; i < width; i++) {
			oss << setw(colWidth) << i << " ";
		}
		
		oss << "\n";

		// Second pass: Generate the string with alignment
		for (int i = 0; i < height; i++) {
			oss << i;
			for (int j = 0; j < width; j++) {
				if (10 <= matrix[i][j] && matrix[i][j] < 100 || matrix[i][j] == -2) {
					// oss << setw(colWidth) << matrix[i][j];
					oss << setw(colWidth) << (matrix[i][j] / 10);
					if (j < width - 1) oss << " ";
				}

				else if (abs(matrix[i][j]) >= 100) {
					oss << setw(colWidth) << "*";
					if (j < width - 1) oss << " ";
				}

				else {
					// oss << setw(colWidth) << " ";
					oss << setw(colWidth) << ".";
					if (j < width - 1) oss << " ";
				}
			}
			oss << '\n';
		}

		return oss.str();
	}

	friend ostream& operator<<(ostream& os, const Matrix<T>& m) {
		os << m.toString();
		return os;
	}
};

#endif