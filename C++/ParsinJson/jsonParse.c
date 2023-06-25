#include <biblioteca_c.h>

// Tenho que programar na prática para ver funcionando maneiras
// mesmo que gambiarradas de separar em uma linha de json
// uma chave e N valores

// string getTillSubstr(fstream& jsonFile, string substr) {
// 	string aux, str;

// 	while (aux != substr) {
// 		aux.erase();
// 		while (aux.length() < substr.length() && !jsonFile.eof()) {
// 			aux += jsonFile.get();
// 		}
// 		str += aux;
// 		cout << "'" << aux << "'" << endl;
// 	}

// 	return str;
// }

// string Key(fstream& jsonFile) {
// 	string key, aux;

// 	// while (*jsonFile)

// 	getline(jsonFile, key, ':');
// 	ReplaceAll(key, "\"':\n{", "");
// 	trim(key, '\t');

// 	return key;
// }

// vector<string> Values(fstream& jsonFile) {
// 	vector<string> array;

// 	// slkdjfl

// 	int	 singleOrArray = 0; // 1 == single 2 == array
// 	char c;
// 	while (!singleOrArray && !jsonFile.eof()) {
// 		if ((c = jsonFile.get()) == '[') {
// 			singleOrArray = 1;

// 		} else if (c == '\"') {
// 			singleOrArray = 2;
// 			string value  = getTillSubstr(jsonFile, "\",");
// 			cout << "Value: {" << value << " }" << endl;
// 			ReplaceAll(value, "\"',", "");
// 			trim(value);
// 			cout << "Value: {" << value << " }" << endl;
// 			array.push_back(value);
// 		}
// 	}

// 	return array;
// }

typedef struct Pessoa {
	String	nome;
	int		idade, alturaCm;
	String* jogosFavoritos;
} Pessoa;

typedef struct Key {
	int		length;
	String	name;
	String	value;
	String* values; // char** se der pau // NULL by default Will have the same value as value but value will be NULL if there's more than one
} Key;

struct JSON {
	int	 length;
	Key* key;
};
typedef JSON* JSON;

JSON JSONParse(char* const jsonFileDir) {
	FILE* jsonFile = fopen(jsonFileDir, "r");

	JSON json = (JSON)malloc(sizeof(JSON));
	json->key = KeyValues(); // Essa função deverá reallocar conforme novas keys forem sendo "achadas"

	// json->key = (Key*)malloc(N * sizeof(Key));

	fclose(jsonFile);

	return json;
}

void PessoaDados(Pessoa* pessoa, JSON json) {
	for (int i = 0; i < json->length; i++) {
		if (!strcmp(json->key[i]->name, "nome")) {
			pessoa->nome = json->key[i]->Value;
		} else if (!strcmp(json->key[i]->name, "idade")) {
			pessoa->idade = json->key[i]->Value;
		} else if (!strcmp(json->key[i]->name, "altura")) {
			pessoa->alturaCm = json->key[i]->Value;
		} else if (!strcmp(json->key[i]->name, "jogos favoritos")) {
			for (int j = 0; j < json->key[i]->length; j++) {
				pessoa->jogosFavoritos[j] = json->key[i]->Values[j];
			}
		} else {
			break;
		}
	}
}

void PessoaDados2(Pessoa* pessoa, JSON json) {
	pessoa->nome			  = json->key[0]->Value;
	pessoa->idade			  = atoi(json->key[1]->Value);
	pessoa->alturaCm		  = atoi(json->key[2]->Value);
	pessoa->jogosFavoritos[0] = json->key[3]->Values[0];
	pessoa->jogosFavoritos[1] = json->key[3]->Values[1];
}

int main() {

	JSON   json = JSONParse("pessoa.json"); // Dynamically allocated and NULL/nullptr terminated array of dynamically allocated and NULL/nullptr terminated arrays of strings;
	Pessoa lucas;

	// PessoaDados(&lucas, json);
	PessoaDados2(&lucas, json);

	printf("lucas.nome: %s\n", lucas.nome);
	printf("lucas.idade: %s\n", lucas.idade);
	printf("lucas.alturaCm: %s\n", lucas.alturaCm);
	printf("lucas.jogosFavoritos[0]: %s\n", lucas.jogosFavoritos[0]);
	printf("lucas.jogosFavoritos[1]: %s\n", lucas.jogosFavoritos[1]);

	JSONClose(json);

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}