#include <stdio.h>

int main() {
	double sum, aver;
	int start, step, num;
	
	printf("请输入起始值，步长，元素个数：");
	scanf("%d%d%d", &start, &step, &num);

	printf("start = %d, step = %d, num = %d\n", start, step, num);

	aver = sum = 0;
	for (int i = 0; i < num; i++) {
		sum = sum + start + i * step;
	}

	aver = sum / num;
	printf("sum is %lf\n", sum);
	printf("average is %lf\n", aver);

	return 0;
}