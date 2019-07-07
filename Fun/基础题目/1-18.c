#include <stdio.h>

int Factorial(int n);

int main() {
	int num;

	printf("请输入一个正整数：");
	scanf("%d", &num);

	printf("%d的阶乘为：%d\n", num, Factorial(num));

	return 0;
}

int Factorial(int n) {
	int result = 1;

	for (int i = 1; i <= n; i++) {
		result *= i;
	}

	return result;
}