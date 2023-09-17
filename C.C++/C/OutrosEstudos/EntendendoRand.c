#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	srand(0);
	printf("Rand: %d\n", rand());
	printf("Rand: %d\n", rand());
	printf("Rand: %d\n", rand());
	printf("Rand: %d\n", rand());
	printf("Rand: %d\n", rand());
	printf("Rand: %d\n", rand());
	printf("Rand: %d\n", rand());
	printf("Rand: %d\n", rand());
	printf("Rand: %d\n", rand());
	printf("Rand: %d\n", rand());
	printf("Rand: %d\n", rand());
	
	printf("-----------------\n");

	int timeVal = time(0);
	printf("Time: %d\n", timeVal);

	srand(timeVal);
	printf("Rand: %d\n", rand() % 10);
	printf("Rand: %d\n", rand() % 10);
	printf("Rand: %d\n", rand() % 10);
	printf("Rand: %d\n", rand() % 10);
	printf("Rand: %d\n", rand() % 10);
	printf("Rand: %d\n", rand() % 10);
	printf("Rand: %d\n", rand() % 10);
	printf("Rand: %d\n", rand() % 10);
	printf("Rand: %d\n", rand() % 10);
	printf("Rand: %d\n", rand() % 10);
	printf("Rand: %d\n", rand() % 10);

}