#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <time.h>

// clear && gcc rand.c -lm && ./a.out

unsigned int srand(int seed_arg) {
	static int seed = 0;
	seed = seed_arg != 0 ? seed_arg : seed;
	seed %= INT_MAX;
	return seed_arg == 0 ? seed : seed_arg;
}

unsigned int rand() {
	static int count = 0;
	count++;
	int seed = srand(0) % INT_MAX;
	// printf("count: %d\n", count);
	// printf("seed: %d\n", seed);
	// return seed;
	return (count * seed) % INT_MAX;
}

int main() {

	srand(time(0));

	for (int i = 0; i < 10; i++) {
		printf("Seed: %d\n", srand(0));
		int N = rand();
		printf("N: %d\n", N);
	}

	return 0;
}