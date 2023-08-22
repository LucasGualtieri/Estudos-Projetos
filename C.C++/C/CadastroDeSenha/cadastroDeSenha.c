#include <biblioteca_c.h>
#include <termios.h>

#define backspace 127

// Toggles the visibility of the input characters.
void ToggleConsoleVisibility() {
	static bool enabled = true;

	struct termios term;
	tcgetattr(fileno(stdin), &term);

	if (!(enabled = !enabled)) {
		term.c_lflag &= ~(ICANON | ECHO);
	} else {
		term.c_lflag |= (ICANON | ECHO);
	}

	tcsetattr(fileno(stdin), TCSAFLUSH, &term);
}

char* readPassword() {
	ToggleConsoleVisibility();

	char c, *password = (char*)malloc(MaxStringLength * sizeof(char));

	int passwordLength = 0;
	while ((c = getchar()) != '\n') {
		if (c != backspace) {
			password[passwordLength++] = c;
			putchar('*');
		} else if (passwordLength > 0) {
			printf("\b \b"); // Moves the cursor back by one position
			passwordLength--;
		}
	}
	password[passwordLength++] = '\0';
	putchar('\n');

	password = (char*)realloc(password, passwordLength * sizeof(char));

	ToggleConsoleVisibility();

	return password;
}

void CadastrarSenha() {
	clrscreen();
	puts(BOLD "------- Cadastrando uma nova senha -------\n" RESET);

	string password;
	string passwordConfirmation;
	bool   divergent = false;
	int	   chances	 = 0;

	do {

		if (divergent) {
			printColorBold("\nSenhas divergentes, ", RED);
			printf("tente novamente [%d/3]: \n", ++chances);
		}

		printf("Digite sua senha: ");
		password = readPassword();

		printf("Confirme sua senha: ");
		passwordConfirmation = readPassword();

		divergent = strcmp(password, passwordConfirmation);

		if (divergent) free(password);
		free(passwordConfirmation);

	} while (divergent && chances < 3);

	clrscreen();
	if (divergent) {
		printColorLn(BOLD "------- Falha no cadastro da senha! -------\n", RED);
		return;
	}
	printColorLn(BOLD "------- Senha cadastrada com sucesso! -------\n", GREEN);

	FILE* passwordStorage = fopen("password.dat", "w");
	fprintf(passwordStorage, "%s", password);
	fclose(passwordStorage);
	free(password);
}

void ValidarSenha() {
	FILE*  passwordStorage = fopen("password.dat", "r");
	string password		   = getstr(passwordStorage);
	fclose(passwordStorage);

	string passwordValidation;
	bool   invalid = false;
	int	   chances = 0;

	clrscreen();
	puts(BOLD "------- Validar uma senha cadastrada -------\n" RESET);

	do {
		if (!invalid) {
			printf("Digite sua senha: ");
		} else {
			printColorBold("Senha incorreta! ", RED);
			printf("Tente novamente [%d/3]: ", ++chances);
		}

		passwordValidation = readPassword();

		invalid = strcmp(password, passwordValidation);

		free(passwordValidation);
	} while (invalid && chances < 3);

	free(password);

	clrscreen();
	if (invalid) {
		printColorLn(BOLD "------- Validação mal-sucedida! -------\n", RED);
	} else {
		printColorLn(BOLD "------- Validação bem-sucedida! -------\n", GREEN);
	}
}

int ReadingChoice() {
	int	 choice;
	bool invalid = false;

	do {
		if (invalid) {
			printf("Valor inválido, tente novamente: ");
		}
		scanf("%d", &choice);
		flush(0);
	} while ((invalid = choice < 0 || 2 < choice));

	return choice;
}

int OptionsMenu() {

	puts("0 - Sair do programa.");
	puts("1 - Cadastrar uma senha.");
	// puts("2 - Cadastrar uma senha com criptografia.");
	puts("2 - Validar uma senha cadastrada.");
	printf("Escolha uma das opções acima: ");

	int escolha = ReadingChoice();

	switch (escolha) {
	case 1:
		CadastrarSenha();
		// 	break;
		// case 2:
		// 	// CadastrarSenhaCript();
		break;
	case 2:
		ValidarSenha();
		break;
	}

	return escolha;
}

int main() {

	while (OptionsMenu()) continue;

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}