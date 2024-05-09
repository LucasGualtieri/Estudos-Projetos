#include <iostream>
#include <unordered_map>
#include <unistd.h>
#include "timer.hpp"
#include <stdio.h>
#include <stdlib.h>

// clear && g++ Memo.cc && ./a.out

using namespace std;

typedef unsigned long long bigInt;
typedef unordered_map<int, bigInt> Hash;

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

void foo(int i, bigInt (*fn) (bigInt), string str, FILE* file) {
	
	static int aux = 0;
	aux++;

	Timer timer;

	timer.start();
	bigInt resultado = fn(i);
	timer.stop();

	printf("Fibonacci%s(%d): %lld\n", str.c_str(), i, resultado);
	cout << "Tempo decorrido: " << timer << endl;

	if (aux % 2 != 0) fprintf(file, "%d, %lf, ", i, timer.result());
	else fprintf(file, "%lf\n", timer.result());
}

int main() {
	
	FILE* file = fopen("grafico.csv", "w");

	fprintf(file, "i, Otimizado, Tradicional\n");

	for (int i = 0; i < 42; i++) {
		foo(i, fibonacci, "Otimizado", file);
		cout << "----------------------" << endl;
		foo(i, fibonacciTradicional, "Tradicional", file);
		cout << "==================================\n" << endl;
	}

	fclose(file);
}
