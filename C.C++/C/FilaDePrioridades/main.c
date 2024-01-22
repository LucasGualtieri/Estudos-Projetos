#include <stdio.h>
#include "Queue.h"

#define EXIT 0

int menu() {
	
}

void Cadastrar() {

}

int main() {

	// Queue list = newList(); // É uma Queue na realidade

	int choice;	

	while((choice = menu()) != EXIT) {
		switch (choice) {
			case 1:
			// cadastrar(&list);
			break;
			case 2:
			// list.Listar(...);
			break;
			default:
			// list.removerInicio()
		}
	}

	return 0;
}