#include <biblioteca_c.h>
#include <termios.h>

char* readPassword() {
	struct termios term;
	tcgetattr(fileno(stdin), &term);

	// Disable terminal buffering and echoing
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(fileno(stdin), TCSAFLUSH, &term);

	char* string = (char*)malloc(MaxStringLength * sizeof(char));

	int stringLength = 0;
	while (true) {
		char c = getchar();

		if (c == '\n') {
			printf("\n");
			break;
		} else if (c == 127) {
			if (stringLength > 0) {
				printf("\b \b"); // Moves the cursor back by one position
				stringLength--;
			}
		} else {
			string[stringLength++] = c;
			putchar('*');
		}
		string[stringLength] = '\0';
	}

	string = (char*)realloc(string, (strlen(string) + 1) * sizeof(char));

	// Restore terminal buffering and echoing
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(fileno(stdin), TCSAFLUSH, &term);

	return string;
}

void CadastrarSenha() {
	system("clear");
	printf("------- Cadastrando uma nova senha -------\n\n");

	String password;
	String passwordConfirmation;
	bool divergent = false;
	int chances = 0;

	do {
		if (divergent) {
			// system("clear");
			printf("\nSenhas divergentes, tente novamente [%d/3]: \n", ++chances);
		}

		printf("Digite sua senha: ");
		password = readPassword();

		printf("Confirme sua senha: ");
		passwordConfirmation = readPassword();

		divergent = strcmp(password, passwordConfirmation);

	} while (divergent && chances < 3);

	system("clear");

	if (divergent) {
		printf("------- Falha no cadastro da senha! -------\n\n");
	} else {
		printf("------- Senha cadastrada com sucesso! -------\n\n");
	}

	FILE* passwordStorage = fopen("password.dat", "w");
	fprintf(passwordStorage, "%s", password);

	fclose(passwordStorage);
	free(password);
	free(passwordConfirmation);
}

void ValidarSenha() {

	FILE* passwordStorage = fopen("password.dat", "r");
	String password = getstr(passwordStorage);
	fclose(passwordStorage);

	String passwordValidation;
	bool invalid = false;
	int chances = 0;

	system("clear");
	printf("------- Validar uma senha cadastrada -------\n\n");

	do {

		if (invalid) {
			printf("Senha incorreta! Tente novamente [%d/3]: ", ++chances);
		} else {
			printf("Digite sua senha: ");
		}

		passwordValidation = readPassword();

		invalid = (strcmp(password, passwordValidation));

	} while (invalid && chances < 3);

	system("clear");

	if (invalid) {
		printf("------- Validação mal-sucedida! -------\n\n");
	} else {
		printf("------- Validação bem-sucedida! -------\n\n");
	}
}

int LendoEscolha() {
	int escolha;
	bool invalid = false;

	do {
		if (invalid) printf("Valor inválido (o valor deve ser >= 0 e < 3): ");
		scanf("%d%*c", &escolha); // %d%*c will clear the STDIN
	} while ((invalid = escolha < 0 || escolha > 2));

	return escolha;
}

int MenuDeOpcoes() {
	printf("0 - Sair do programa.\n");
	printf("1 - Cadastrar uma nova senha.\n");
	printf("2 - Validar uma senha cadastrada.\n");
	printf("Escolha uma das opções acima: ");

	int escolha = LendoEscolha();

	switch (escolha) {
	case 1:
		CadastrarSenha();
		break;
	case 2:
		ValidarSenha();
		break;
	}

	return escolha;
}

int main() {

	while (MenuDeOpcoes()) { } // while (MenuDeOpcoes() != 0);

	puts("\n******* | FIM DO PROGRAMA | *******\n");

	return 0;
}