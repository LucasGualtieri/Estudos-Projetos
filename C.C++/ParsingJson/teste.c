#include <biblioteca_c.h>

int main() {

	String string = strdup("1,87");

	printf("string: %s\n", replaceAll(string, ",", "."));

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}