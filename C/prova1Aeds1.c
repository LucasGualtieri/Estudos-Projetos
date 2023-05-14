#include <biblioteca_c.h>

int Func1(int a, int b, int c) {
	return a - b + c;
}

int main() {

	int i, numTermos, num1, num2, num3;
	printf("Digite um numero: ");
	scanf("%d", &numTermos);

	num1 = Func1(1, 2, 3);
	num2 = Func1(3, 2, 1);
	num3 = Func1(6, 1, 7);
	printf("Num1 = %d\n", num1);
	printf("Num2 = %d\n", num2);
	printf("Num3 = %d\n", num3);
	i = 3;
	while (i <= numTermos) {

		num1 *= 2;
		printf("Num1: = %d\n", num1);
		printf("i = %d\n", i);
		i++;
		while ((num2 > 1) && (num2 < 20)) {

			num2 *= 3;
			printf("Num2 = %d\n", num2);
			i++;
			if (i % 3 == 0) {
				num3 = num3 + 4;
				printf("Num3 = %d\n", num3);
				i--;
			}
		}
	}

	return 0;
}