#include <biblioteca_cpp.h>

#define END "END"

string Key(fstream& jsonFile) {
	string search;

	while (jsonFile.eof()) {
		jsonFile >> search;
		cout << search;
		trim(search);
		if (search[0] == '\"' || search[0] == '\'') break;
	}

	// string key = search.erase(search.find(' '));

	// trim(key, '\'');
	// trim(key, '\"');

	// cout << key;

	return search;
}

// string Value(fstream& jsonFile) {
// }

vector<string> KeyValue(fstream& jsonFile) {
	vector<string> array;

	// array.push_back(Key(jsonFile));

	// while (array[array.size() - 1] != "END" || jsonFile.eof()) {
	// 	array.push_back(Value(jsonFile));
	// }

	array.push_back("CHAVE");
	array.push_back("VAL1");
	array.push_back("VAL2");
	array.push_back("END");

	return array;
}

void value() { }

class JSON {

	vector<vector<string>> matrix;

  public:
	JSON(string fileDir) {

		fstream jsonFile(fileDir, ios::in);
		if (!jsonFile.is_open()) {
			throw runtime_error("Failed to open file: " + fileDir);
		}

		// while (!jsonFile.eof()) {
		// 	matrix.push_back(KeyValue(jsonFile));
		// }
		matrix.push_back(KeyValue(jsonFile));

		matrix.push_back({END});

		jsonFile.close();
	}

	vector<string> operator[](size_t index) {
		if (index >= matrix.size()) {
			throw string("Error: Index [" + to_string(index) + "] is out of bounds!");
		}

		return matrix[index];
	}
};

int main() {

	JSON KeyValue("ackbar.json");

	for (int i = 0; KeyValue[i][0] != END; i++) {
		cout << "Key: " << KeyValue[i][0] << endl; // Key
		cout << "Value: ";
		for (int j = 1; KeyValue[i][j] != END; j++) {
			cout << KeyValue[i][j] << ", "; // Value
		}
	}
	cout << endl;

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}

// vector<string> strings;
// strings.push_back("oi ");
// strings.push_back("meu ");
// strings.push_back("nome é Lucas");

// matrix.push_back(strings);

// vector<string> asdf;
// asdf.push_back("Joca ");
// asdf.push_back("é ");
// asdf.push_back("bobão");

// matrix.push_back(asdf);