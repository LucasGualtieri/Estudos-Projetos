#include "../utils/include/user_input.h"

// make && clear && ./bin/SistemaEstacionamento

typedef struct {
	// String nome; // Combado com o strdup somente se for haver uma rotina de close();
	char nome[STR_MAX_LEN];
	int idade;
} Pessoa;

// Usuário responsável por liberar a memória
String* split(String string, String delim) {

	if (string == NULL || delim == NULL) return NULL;

	int count = 1, len = strlen(string), delim_len = strlen(delim);

	// Count the number of delimiters in the string
	for (int i = 0; i < len; i++) {
		if (strstr(&string[i], delim) == &string[i]) {
			count++;
			i += delim_len - 1;
		}
	}

	String* array = (String*)malloc((count + 1) * sizeof(String));

	String str_copy = strdup(string);

	String token = strtok(str_copy, delim);

	for (int i = 0; token != NULL; i++) {
		array[i] = strdup(token);
		token = strtok(NULL, delim);
	}

	array[count] = NULL;

	free(str_copy);

	return array;
}

void splitFree(String* array) {

	if (array == NULL) return;

	for (int i = 0; array[i]; i++) {
		free(array[i]);
	}

	free(array);
}

// Fazer também o readChoice(int n);

int main() {

	// int n = readInt("Digite um número inteiro: ");
	// printf("n: %d\n", n);

	// float f = readFloat("Digite um número real: ");
	// printf("f: %f\n", f);

	// Pessoa p;

	// // p.lerNome("Digite seu nome: ", &p);

	// strcpy(p.nome, readString("Digite seu nome: "));

	// printf("p.nome: %s\n", p.nome);

	String data = "25/04/2002";

	String* array = split(data, "/");

	int dia, mes, ano;

	dia = atoi(array[0]);
	mes = atoi(array[1]);
	ano = atoi(array[2]);

	printf("Dia: %d\n", dia);
	printf("Mes: %d\n", mes);
	printf("Ano: %d\n", ano);

	splitFree(array);

	String teste = "Val1, Val2, Val3";

	array = split(teste, ", ");

	for (int i = 0; array[i]; i++) {
		printf("'%s'\n", array[i]);
	}

	splitFree(array);

	return 0;
}