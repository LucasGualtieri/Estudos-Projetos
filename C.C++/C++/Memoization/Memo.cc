#include <iostream>
#include <unordered_map>
#include <unistd.h>
#include "timer.hpp"
#include <stdio.h>
#include <stdlib.h>

// clear && g++ Memo.cc && ./a.out

using namespace std;

typedef unordered_map<int, int> Hash;
typedef unsigned long long bigInt;

bigInt fibonacci(bigInt n, Hash& hash) {

	if (n == 0 || n == 1) return n;

	if (hash.find(n - 1) == hash.end()) {
		hash[n - 1] = fibonacci(n - 1, hash);
	}

	if (hash.find(n - 2) == hash.end()) {
		hash[n - 2] = fibonacci(n - 2, hash);
	}

	return hash[n - 1] + hash[n - 2];
}

bigInt fibonacci(bigInt nth) {
	Hash hash{{0, 0}, {1, 1}};
	return fibonacci(nth, hash);
}

bigInt fibonacciTradicional(bigInt n) {
  if (n == 0 || n == 1) return n;
  return fibonacciTradicional(n - 1) + fibonacciTradicional(n - 2);
}

int main() {
	Timer timer;

	bigInt x;

	FILE* file = fopen("grafico.csv", "w");

	fprintf(file, "o, v\n");

	for (int i = 0; i < 30; i++) {
		timer.start();
		x = fibonacci(i);
		timer.stop();

		cout << "Fib(i): " << x << endl;
		cout << timer << endl;
		fprintf(file, "%lf, ", timer.result());

		timer.start();
		x = fibonacciTradicional(i);
		timer.stop();

		cout << "Fib(i): " << x << endl;
		cout << timer << endl;
		fprintf(file, "%lf\n", timer.result());

		cout << "----------------------" << endl;
	}

	fclose(file);
}