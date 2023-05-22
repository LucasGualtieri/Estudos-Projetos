#include <stdio.h>

int fibonacci(int n) {
	return (n == 0 || n == 1) ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	// 1 2 3 4 5 6
	// 1 1 2 3 5 8

	int n = 4;
	printf("O %d° termo de fibonacci é: %d\n", n + 1, fibonacci(n));

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}