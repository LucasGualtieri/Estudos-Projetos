#ifndef JSON_H_
#define JSON_H_

#include <biblioteca_c.h>

// Em C++ e Java posso botar esses métodos todos KeyName, values, etc tudo dentro da classe

typedef struct Key {
	int		length; // Número de valores
	String	name;	// A string que representa o nome da chave
	String	value;	// String que aponta para o primeiro valor do vetor de valores
	String* values; // Vetor dinâmicamente allocado de valores
} Key;

typedef struct JSON {
	int	 length; // Número de chaves e seus respectivos valores
	Key* key;	 // Vetor dinâmicamente allocado de Keys
} JSON;

String KeyName(FILE* jsonFile) {

	while (!strchr("\"'[}", getc(jsonFile)) && !feof(jsonFile)) continue;

	String string = (String)malloc(50 * sizeof(char));

	fscanf(jsonFile, "%[^\"']%*c", string);
	// if (DEBUGGING) printf("String: %s\n", string);

	string = (String)realloc(string, strsize(string));

	return string;
}

String* Values(Key* key, FILE* jsonFile) {
	char c;
	while (!strchr("\"'[}", (c = getc(jsonFile))) && !feof(jsonFile)) continue;

	String* arrayOfValues = NULL;
	String	string;

	if (c == '\'' || c == '\"') {
		string = (String)malloc(50 * sizeof(char));

		fscanf(jsonFile, "%[^\"']%*c", string);
		if (DEBUGGING) printf("String: %s\n", string);

		string			 = (String)realloc(string, strsize(string));
		arrayOfValues	 = (String*)realloc(arrayOfValues, ++key->length * sizeof(String));
		arrayOfValues[0] = key->value = string;

	} else if (c == '[') { // Achei melhor especificar

		if (getc(jsonFile) == ']') {
			string = (String)malloc(sizeof(char));
			strcpy(string, "");
			arrayOfValues				   = (String*)realloc(arrayOfValues, ++key->length * sizeof(String));
			arrayOfValues[key->length - 1] = key->value = string;
			return arrayOfValues;
		}

		bool stop = false;
		do {
			string = (String)malloc(50 * sizeof(char));
			fscanf(jsonFile, "%[^\"']%*c", string);
			// if (DEBUGGING) printf("String: %s\n", string);

			// if (!strlen(string)) stop = true;

			string						   = (String)realloc(string, strsize(string));
			arrayOfValues				   = (String*)realloc(arrayOfValues, ++key->length * sizeof(String));
			arrayOfValues[key->length - 1] = string;

			while (!strchr("\"']", (c = getc(jsonFile))) && !feof(jsonFile)) continue;
			if (c == ']') stop = true;

		} while (!stop && !feof(jsonFile));

		key->value = arrayOfValues[0];
	}

	// printf("strlen(string): %d\n", strlen(string));
	// printf("string: %s\n", string);

	return arrayOfValues;
}

Key KeyValues(FILE* jsonFile) {
	Key key = {0};

	key.name = KeyName(jsonFile);
	// if (DEBUGGING) printf("key.name: %s\n", key.name);
	key.values = Values(&key, jsonFile);

	return key;
}

JSON JSONParse(const char* jsonFileDir) {

	FILE* jsonFile = fopen(jsonFileDir, "r");

	if (!jsonFile) {
		printf("Erro: Falha ao abrir o arquivo.\n");
		exit(0);
	}

	JSON json = {0, NULL};

	Key newKey;
	while (((newKey = KeyValues(jsonFile)).length)) {
		json.key = (Key*)realloc(json.key, ++json.length * sizeof(Key));

		json.key[json.length - 1] = newKey;
	}

	fclose(jsonFile);

	return json;
}

void JSONClose(JSON json) {
	for (int i = 0; i < json.length; i++) {
		free(json.key[i].name);
		for (int j = 0; j < json.key[i].length; j++) {
			if (DEBUGGING) printf("json.key[%d].length: %d\n", i, json.key[i].length);
			free(json.key[i].values[j]);
		}
		free(json.key[i].values);
	}
	free(json.key);
}

void JSONPrint(JSON json) {
	for (int i = 0; i < json.length; i++) {
		printf("\"%s\": ", json.key[i].name);
		for (int j = 0; j < json.key[i].length; j++) {
			printf("\"%s\"", json.key[i].values[j]);
			if (j < json.key[i].length - 1) printf(", ");
		}
		printf("\n");
	}
}

#endif /*JSON_H_ */