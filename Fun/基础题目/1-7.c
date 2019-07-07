#include <stdio.h>

int main() {
	int total = 0;
	int eat_time = 0;

	printf("请输入最后剩余的桃子数：");
	scanf("%d", &total);

	while (1) {
		printf("请输入猴子吃了多少次桃子：");
		scanf("%d", &eat_time);
		if (eat_time < 0) {
			printf("您输入的次数有误！\n");
			continue;
		}
		else
			break;
	}

	while (eat_time > 0) {
		total = 2 * (total + 1);
		eat_time--;
	}

	printf("猴子总共摘了%d个桃子\n", total);

	return 0;
}