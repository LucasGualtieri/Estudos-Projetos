#include <biblioteca_cpp.h>

// Tenho que programar na prática para ver funcionando maneiras
// mesmo que gambiarradas de separar em uma linha de json
// uma chave e N valores

string getTillSubstr(fstream& jsonFile, string substr) {
	string aux, str;

	while (aux != substr) {
		aux.erase();
		while (aux.length() < substr.length() && !jsonFile.eof()) {
			aux += jsonFile.get();
		}
		str += aux;
		cout << "'" << aux << "'" << endl;
	}

	return str;
}

string Key(fstream& jsonFile) {
	string key, aux;

	// while (*jsonFile)

	getline(jsonFile, key, ':');
	ReplaceAll(key, "\"':\n{", "");
	trim(key, '\t');

	return key;
}

vector<string> Values(fstream& jsonFile) {
	vector<string> array;

	// slkdjfl

	int	 singleOrArray = 0; // 1 == single 2 == array
	char c;
	while (!singleOrArray && !jsonFile.eof()) {
		if ((c = jsonFile.get()) == '[') {
			singleOrArray = 1;

		} else if (c == '\"') {
			singleOrArray = 2;
			string value  = getTillSubstr(jsonFile, "\",");
			cout << "Value: {" << value << " }" << endl;
			ReplaceAll(value, "\"',", "");
			trim(value);
			cout << "Value: {" << value << " }" << endl;
			array.push_back(value);
		}
	}

	return array;
}

int main() {

	// string** arrayOfArrayOfStrings; // Dynamically allocated and NULL/nullptr terminated array of dynamically allocated and NULL/nullptr terminated arrays of strings;

	vector<vector<string>> arrayOfArrayOfStrings;

	fstream jsonFile("ackbar.json");
	// fstream jsonFile("ackbar.txt");

	string firstKey = Key(jsonFile);
	cout << "Key: '" << firstKey << "'" << endl;
	// string aux = getTillSubstr(jsonFile, "\"],");
	// cout << "'" << aux << "'" << endl;
	vector<string> values = Values(jsonFile);
	// cout << values[0] << endl;

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}