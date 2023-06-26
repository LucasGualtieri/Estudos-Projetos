#include "json.h"
#include <biblioteca_c.h>

// Tenho que programar na prática para ver funcionando maneiras
// mesmo que gambiarradas de separar em uma linha de json
// uma chave e N valores

typedef struct Pessoa {
	String nome;
	int	   idade;
	float  alturaM;
	String jogosFavoritos[2];
} Pessoa;

void PessoaDados(Pessoa* pessoa, JSON json) {
	for (int i = 0; i < json.length; i++) {
		if (!strcmp(json.key[i].name, "nome")) {
			pessoa->nome = json.key[i].value;
		} else if (!strcmp(json.key[i].name, "idade")) {
			pessoa->idade = atoi(json.key[i].value);
		} else if (!strcmp(json.key[i].name, "altura")) {
			pessoa->alturaM = atof(json.key[i].value);
		} else if (!strcmp(json.key[i].name, "jogos favoritos")) {
			for (int j = 0; j < json.key[i].length; j++) {
				pessoa->jogosFavoritos[j] = json.key[i].values[j];
			}
		} else {
			break;
		}
	}
}

void PessoaDados2(Pessoa* pessoa, JSON json) {
	pessoa->nome			  = json.key[0].value;
	pessoa->idade			  = atoi(json.key[1].value);
	pessoa->alturaM			  = atof(json.key[2].value);
	pessoa->jogosFavoritos[0] = json.key[3].values[0];
	pessoa->jogosFavoritos[1] = json.key[3].values[1];
}

void PessoaPrint(Pessoa lucas) {
	printf("lucas.nome: \"%s\"\n", lucas.nome);
	printf("lucas.idade: %d\n", lucas.idade);
	printf("lucas.alturaM: %g\n", lucas.alturaM); // NOTE - Melhorar a altura para mudar as virgulas 1,87
	printf("lucas.jogosFavoritos[0]: \"%s\"\n", lucas.jogosFavoritos[0]);
	printf("lucas.jogosFavoritos[1]: \"%s\"\n", lucas.jogosFavoritos[1]);
}

int main() {

	JSON   json = JSONParse("pessoa.json");
	Pessoa lucas;

	// JSONPrint(json);

	PessoaDados(&lucas, json);
	// PessoaDados2(&lucas, json);
	PessoaPrint(lucas);

	JSONClose(json);

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}