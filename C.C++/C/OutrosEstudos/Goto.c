#include <stdio.h>

// clear && gcc Goto.c && ./a.out

int main() {

	int i = 0;

	// Equivalente a fazer um while
	loop:
	if (i >= 5) goto fim;
	printf("i: %d\n", i++);
	goto loop;
	fim:

	return 0;
}