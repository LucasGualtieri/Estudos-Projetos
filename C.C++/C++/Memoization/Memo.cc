#include <iostream>
#include <unordered_map>
#include <unistd.h>
#include "timer.hpp"

// clear && g++ -std=c++2b Memo.cc && ./a.out

using namespace std;

typedef unsigned long long bigInt;
typedef unordered_map<int, bigInt> Hash;

template <typename Hash, typename Key>
bool contains(Key key, Hash hash) {
	return hash.find(key) != hash.end();
}

bigInt fibonacci(bigInt n, Hash& memo) {

	if (!memo.contains(n - 1)) { // Only works in c++ 23
		memo[n - 1] = fibonacci(n - 1, memo);
	}

	if (!contains(n - 2, memo)) {
		memo[n - 2] = fibonacci(n - 2, memo);
	}

	return memo[n - 1] + memo[n - 2];
}

bigInt fibonacci(bigInt n) {
	if (n <= 1) return n;
	Hash memo{{0, 0}, {1, 1}};
	return fibonacci(n, memo);
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
	
	for (int i = 0; i < 100; i++) {
		cout << fibonacci(i) << endl;
	}

	// FILE* file = fopen("grafico.csv", "w");

	// fprintf(file, "i, Otimizado, Tradicional\n");

	// for (int i = 0; i < 42; i++) {
	// 	foo(i, fibonacci, "Otimizado", file);
	// 	cout << "----------------------" << endl;
	// 	foo(i, fibonacciTradicional, "Tradicional", file);
	// 	cout << "==================================\n" << endl;
	// }

	// fclose(file);
}
