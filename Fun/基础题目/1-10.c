#include <stdio.h>

int main() {
	int sum = 0;
	int start, end, step;
	start = end = step = 0;

	printf("请输入起始值：");
	scanf("%d", &start);
	printf("请输入终止值：");
	scanf("%d", &end);
	printf("请输入步长：");
	scanf("%d", &step);

	for (int i = start; i <= end; i += step) {
		sum += i;
	}

	printf("该等差数列的和为：%d\n", sum);

	return 0;
}