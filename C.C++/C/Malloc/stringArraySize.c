#include <biblioteca_c.h>

int main() {

	char** array = (char**)malloc(4 * sizeof(char*));

	array[0] = getstr(0);
	array[1] = getstr(0);
	array[2] = getstr(0);
	array[3] = NULL;

	String string1 = array[0];
	String string2 = array[1];
	String string3 = array[2];

	printf("array[0]: \"%s\"\n", array[0]);
	printf("array[1]: \"%s\"\n", array[1]);
	printf("array[2]: \"%s\"\n", array[2]);

	printf("Size of array: %d\n", strArrayLen(array));

	free(array);

	printf("string1: %s\n", string1);
	printf("string2: %s\n", string2);
	printf("string3: %s\n", string3);

	free(string1);
	free(string2);
	free(string3);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}