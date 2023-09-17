#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// clear && gcc EntendendoRand.c && ./a.out

#define RANDOM(minRange, maxRange) (rand() % ((maxRange + 1) - minRange)) + minRange

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

	printf("-----------------\n");

	printf("RANDOM: %d\n", RANDOM(3, 10));
	printf("RANDOM: %d\n", RANDOM(3, 10));
	printf("RANDOM: %d\n", RANDOM(3, 10));
	printf("RANDOM: %d\n", RANDOM(3, 10));
	printf("RANDOM: %d\n", RANDOM(3, 10));
	printf("RANDOM: %d\n", RANDOM(3, 10));
	printf("RANDOM: %d\n", RANDOM(3, 10));

}