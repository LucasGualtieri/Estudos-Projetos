#ifndef JSON_H_
#define JSON_H_

#include <biblioteca_c.h>

typedef char* String;

typedef struct Key {
	int		length;
	String	name;
	String	value;
	String* values; // char** se der pau // NULL by default Will have the same value as value but value will be NULL if there's more than one
} Key;

typedef struct JSON {
	int	 length;
	Key* key;
} JSON;

String const KeyName(FILE* jsonFile) {
	char c;
	while (!strchr("\"'[}", (c = getc(jsonFile))) && !feof(jsonFile)) continue;

	String string = (String)malloc(50 * sizeof(char));

	fscanf(jsonFile, "%[^\"']", string);
	// if (DEBUGGING) printf("String: %s\n", string);
	getc(jsonFile);

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
		fscanf(jsonFile, "%[^\"']", string);
		if (DEBUGGING) printf("String: %s\n", string);
		getc(jsonFile);
		string			 = (String)realloc(string, strsize(string));
		arrayOfValues	 = (String*)realloc(arrayOfValues, ++key->length * sizeof(String));
		arrayOfValues[0] = string;
		key->value		 = string;
	} else if (c == '[') { // Achei melhor especificar
		bool stop = false;
		if (getc(jsonFile) == ']') {
			string = (String)malloc(sizeof(char));
			strcpy(string, "");
			arrayOfValues				   = (String*)realloc(arrayOfValues, ++key->length * sizeof(String));
			arrayOfValues[key->length - 1] = string;
			return arrayOfValues;
		}
		do {
			string = (String)malloc(50 * sizeof(char));
			fscanf(jsonFile, "%[^\"']", string);
			if (DEBUGGING) printf("String: %s\n", string);
			getc(jsonFile);

			// if (!strlen(string)) stop = true;

			string						   = (String)realloc(string, strsize(string));
			arrayOfValues				   = (String*)realloc(arrayOfValues, ++key->length * sizeof(String));
			arrayOfValues[key->length - 1] = string;
			while (!strchr("\"'", (c = getc(jsonFile))) && !feof(jsonFile)) {
				if (c == ']') {
					stop = true;
					break;
				}
			}
		} while (!stop && !feof(jsonFile));
	}

	// printf("strlen(string): %d\n", strlen(string));

	// printf("string: %s\n", string);

	return arrayOfValues;
}

Key KeyValues(FILE* jsonFile) {
	Key key = {0};

	key.name = KeyName(jsonFile);
	if (DEBUGGING) printf("key.name: %s\n", key.name);
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

	// printf("json.length: %d\n", json.length);

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