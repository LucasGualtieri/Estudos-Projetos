#include <stdio.h>

static void bar() {
	printf("Hello world!\n");
}

void foo() {
	bar();
}
