#include <ctype.h>
#include "../include/user_input.h"
#include "../include/utils.h"

void clearscreen() {
	#ifdef _WIN32
	// Windows system
	system("cls");
	#elif __linux__
	// Linux system
	system("clear");
	#elif __APPLE__
	// MacOS system
	system("clear");
	#else
	// If the OS is not recognized, we print a message
	printf("Clear screen not supported on this OS.\n");
	#endif
}

char escolher(String msg) {

	// loop da escolha?

	return toupper(readChar(msg));
}
