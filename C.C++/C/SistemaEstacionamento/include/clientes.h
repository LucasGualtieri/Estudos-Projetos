#ifndef CLIENTE_H
#define CLIENTE_H

#include "../utils/include/user_input.h"
#include "../utils/include/date_utils.h"
#include "../utils/include/lista.h"

typedef struct Cliente {

	String nome;
	char codigo[7];
	Date dataNascimento;
	char contrato;
	int qtdPlacas;
	Lista* placas;

	void (*setNome) (struct Cliente*);
	void (*setCodigo) (struct Cliente*);
	void (*setDataNascimento) (struct Cliente*);
	void (*setContrato) (struct Cliente*);
	void (*setQtdPlacas) (struct Cliente*);
	// void (*close) (struct Cliente*);

} Cliente;

Cliente newCliente();

void lerDadosCliente(Cliente*);

#endif