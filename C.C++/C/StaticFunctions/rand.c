#include <stdio.h>

int seed = 0;

void srand() {
	printf("Ola\n");
	// printf("_seed: %d, seed: %d", _seed, seed);
	// seed = _seed;
}

static int rand() {
	
	seed++;
	printf("Seed: %d\n", seed);
	return seed * 2;
}