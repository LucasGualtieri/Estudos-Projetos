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

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main() {
	printf(ANSI_COLOR_RED "This text is red.\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN "This text is green.\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_YELLOW "This text is yellow.\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_BLUE "This text is blue.\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_MAGENTA "This text is magenta.\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_CYAN "This text is cyan.\n" ANSI_COLOR_RESET);

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