#include <stdio.h>

int main() {
	int a, b, c;
	int max, min;

	printf("请输入三个整型数：");
	scanf("%d%d%d", &a, &b, &c); 

	printf("三个数分别是：%5d,%5d,%5d\n", a, b, c);

	max = (a > b ? a : b) > c ? (a > b ? a : b) : c;
	min = (a < b ? a : b) < c ? (a < b ? a : b) : c;

	printf("三个数中的最大值为：%d\n", max);
	printf("三个数中的最小值为：%d\n", min);

	return 0;
}