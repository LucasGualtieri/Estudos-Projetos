#include <stdio.h>

/*
	In the C programming language, the standard output
	(typically the console) does not provide built-in
	support for color formatting. However, you can achieve
	colored output by using ANSI escape sequences. These sequences
	are special character sequences that, when printed
	to the console, control various formatting options,
	including colors.

	Here's an example of how you can use ANSI
	escape sequences to print colored output in C:
*/

// #define ANSI_COLOR_RED "\x1b[31m"
// printf(RED "This text is red.\n" RESET);

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

void printColor(const char* msg, const char* color) {
	printf("%s%s%s", color, msg, RESET);
}

void printColorLn(const char* msg, const char* color) {
	printf("%s%s%s\n", color, msg, RESET);
}

int main() {

	printColorLn("This text is red.", RED);
	printColorLn("This text is green.", GREEN);
	printColorLn("This text is yellow.", YELLOW);
	printColorLn("This text is blue.", BLUE);
	printColorLn("This text is magenta.", MAGENTA);
	printColorLn("This text is cyan.", CYAN);

	return 0;
}

/*
	In this example, the printf statements are prefixed
	with ANSI escape sequences that define the desired
	color. The escape sequence \x1b[XXm sets the color,
	where XX is a number representing the desired color.
	After printing the colored text, the sequence \x1b[0m
	is used to reset the color back to the default.

	Please note that the support for ANSI escape sequences
	may vary depending on the terminal or console you are
	using. Some environments may not display the colors
	correctly or may require additional configuration.
*/