#include <biblioteca_cpp.h>

#define END "sdkljfghldskjhfgklsdjhfgklsjdfghskdjfhgslkdfjgh";

int main() {

	// JSON KeyValue("ackbar.json");

	vector<vector<string>> matrix;

	vector<string> string1;
	string1.push_back("oi ");
	string1.push_back("meu ");
	string1.push_back("nome é Lucas");

	matrix.push_back(string1);

	vector<string> string2;
	string2.push_back("Joca ");
	string2.push_back("é ");
	string2.push_back("bobão");

	matrix.push_back(string2);

	cout << matrix[0][0] << endl;
	cout << matrix[0][1] << endl;
	cout << matrix[0][2] << endl;
	cout << matrix[1][0] << endl;
	cout << matrix[1][1] << endl;
	cout << matrix[1][2];
	cout << endl;

	cout << "Matrix size: " << matrix.size() << endl;
	cout << "Matrix[0]: " << matrix[0].size();

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}