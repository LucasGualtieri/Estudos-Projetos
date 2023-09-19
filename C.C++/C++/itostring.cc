#include <iostream>
#include <math.h>

// Incompleto, precisa lidar com 201, 302, 403, 504, ...
// o 0 no meio não é printado, sai 21, 32, 43, etc

using namespace std;

string itoc(int val) {
	printf("Integer: %d\n", val);
	if (val == 10) return string("10");
	return string() + (char)(val + '0'); // 48?
}

string itos(int val, int potencia = 1) {
	printf("Valor: %d\n", val);

	if (val < 10) {
		if (val == 0) {
			printf("val == 0");
			string teste;
			while (potencia-- >= 0) teste += '0';
			return teste;
		}
		return itoc(val);
	}

	int next = val;
	potencia = 1;
	while ((val /= 10) > 10) potencia++;
	printf("val: %d\n", val);
	printf("potencia: %d\n", potencia);
	next -= val * pow(10, potencia);
	printf("next: %d\n", next);
	// exit(0);
	return itoc(val) + itos(next, potencia);
}

int main() {
	for (int i = 401; i <= 401; i++) {
		string str = itos(i);
		printf("Str: %s\n", str.c_str());
	}
}