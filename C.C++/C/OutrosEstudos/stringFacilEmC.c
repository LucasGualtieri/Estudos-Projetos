#include <stdio.h>
#include <string.h>

// clear && gcc stringFacilEmC.c && ./a.out

typedef struct string {
	char s[80];
	int length;
} string;

string newString(const char* const str) {
	string string = { "", strlen(str) };
	strcpy(string.s, str);
	return string;
}

int main() {
	string string = newString("Lucas");
	printf("string: %s\n", string.s);
	printf("string.length: %d\n", string.length);
}