#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>
#include <thread>
#include <stack>
#include <utility>

// clear && g++ chuva.cc && ./a.out < pub.in > result.txt
 
#define procedure void

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

	bool inBounds(int i, int j) {
		return 0 <= i && i < height && 0 <= j && j < width;
	}

	vector<T>& operator[](int i) { return matrix[i]; }
	vector<T> operator[](int i) const { return matrix[i]; }

	string toString() const {

		string str;

		for (int i = 0; i < height; i++) {
			ostringstream oss;

			for (int j = 0; j < width; j++) {
				oss << matrix[i][j];
			}

			str += oss.str() + '\n';
			// str.erase(str.length() - 3, 2);
		}

		str.erase(str.length() - 1, 1);

		return str;
	}

	friend ostream& operator<<(ostream& os, const Matrix<T>& m) {
		os << m.toString();
		return os;
	}
};

void pause();
int readInt();
void clear_screen();
void buildMatrix(Matrix<char>& matrix);
int findStartingPoint(const Matrix<char>& matrix);

void floodMatrix(int i, int j, Matrix<char>& matrix) {

	if (!matrix.inBounds(i, j) || matrix[i][j] == 'o') return;

	matrix[i][j] = 'o';

	clear_screen();
	// printf("i[%d] - j[%d]\n", i, j);
	cout << matrix;
	pause();

	// Going down
	if (matrix.inBounds(i + 1, j) && matrix[i + 1][j] == '.') {
		floodMatrix(i + 1, j, matrix);
	}

	// Continue flooding only if there are more levels to go down.
	else if (i < matrix.height - 1) {
		floodMatrix(i, j - 1, matrix); // Going left
		floodMatrix(i, j + 1, matrix); // Going right
	}
}

void floodMatrix(Matrix<char>& matrix) {
	int j = findStartingPoint(matrix);
	
	clear_screen();
	// printf("i[%d] - j[%d]\n", i, j);
	cout << matrix;
	pause();

	matrix[0][j] = '.';

	floodMatrix(0, j, matrix);	
}

void floodMatrixIte(Matrix<char>& matrix) {

	int i = 0, j = findStartingPoint(matrix);

	cout << matrix;
	pause();

	matrix[i][j] = '.';

	stack<pair<int, int>> s;

	do {

		if (!matrix.inBounds(i, j) || matrix[i][j] == 'o') {
			// Backtracking
			tie(i, j) = s.top();
			s.pop();
			continue;
		}

		matrix[i][j] = 'o';

		clear_screen();
		// printf("i[%d] - j[%d]\n", i, j);
		cout << matrix;
		pause();

		if (matrix.inBounds(i + 1, j) && matrix[i + 1][j] == '.') {
			i++; // Going down
		}

		// Continue flooding only if there are more levels to go down.
		else if (i < matrix.height - 1) {
			s.push(pair(i, j + 1)); // Saving to go right later.
			j--; // Going left;
		}

		else if (s.empty()) break;

	} while (!s.empty() || i < matrix.height); // Possivelmente é uma codição falha
}

int main() {

	int n = readInt(), m = readInt();

	Matrix<char> matrix(n, m);

	buildMatrix(matrix);

	// floodMatrix(matrix);
	floodMatrixIte(matrix);

	// cout << matrix << endl;

	return 0;
}

int readInt() {
	int n;
	cin >> n;
	// cin.ignore(2, '\n');
	return n;
}

void buildMatrix(Matrix<char>& matrix) {

	for (int i = 0; i < matrix.height; i++) {
		for (int j = 0; j < matrix.width; j++) {
			cin >> matrix[i][j];
		}
	}
}

int findStartingPoint(const Matrix<char>& matrix) {
	
	int pos;

	for (int j = 0; j < matrix.width; j++) {
		if (matrix[0][j] == 'o') {
			pos = j;
			break;	
		}
	}

	return pos;
}

void pause() {
	// std::cout << "Press Enter to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void clear_screen() {
	#ifdef _WIN32
		std::system("cls");  // Clear screen for Windows
	#else
		std::system("clear");  // Clear screen for POSIX (Linux, macOS)
	#endif
}