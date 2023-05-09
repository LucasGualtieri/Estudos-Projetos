#include <biblioteca_c.h>

typedef struct _String {
	char* buffer;
	int (*length)(struct _String*); // Function pointer to simulate a method
	void (*delete)(struct _String*); // Function pointer to simulate a method
} _String;

// Method implementation
int length(_String* string) {
	return strlen(string->buffer);
}

void delete(_String* string) {
	free(string->buffer);
	free(string);
}

_String* createString() {
	_String* aux = (_String*)malloc(sizeof(_String));
	aux->length = length; // Assign the function pointer
	aux->delete = delete; // Assign the function pointer
	return aux;
}

int main() {
	_String* string = createString();

	string->buffer = strdup("Lucas");

	printf("Len: %d\n", string->length(string));

	string->delete (string); // Free the allocated memory

	return 0;
}